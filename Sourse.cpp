//Stack
#include "Header.h"
#include <typeinfo>
Stack::Stack(int _Size)
{
	Size = _Size;
	Mem = new TValue*[Size];
	Index = -1;
}
Stack::Stack(const Stack &b)
{
	Size = b.Size;
	Index = b.Index;
	Mem = new TValue*[Size];
	for (int i = 0; i < Index; i++)
	{
		Mem[i] = b.Mem[i];
	}
}
Stack & Stack::operator =(const Stack &b)
{
	if (this == &b)	return *this;
	delete[]Mem;
	Size = b.Size;
	Index = b.Index;
	Mem = new TValue*[Size];
	for (int i = 0; i < Index; i++)
	{
		Mem[i] = b.Mem[i];
	}
	return *this;
}
bool Stack::IsStackEmpty()
{
	return (Index == -1);
}
bool Stack::IsStackFull()
{
	return (Index == Size - 1);
}
int Stack::GetSize()
{
	return Index + 1;
}
void Stack::AddElement(TValue* Elem)
{
	if (IsStackFull())
	{
		throw - 1;
	}
	Index++;
	Mem[Index] = Elem;
}
TValue * Stack::DeleteElement()
{
	if (IsStackEmpty())
	{
		throw - 2;
	}
	Index--;
	return Mem[Index + 1];
}
void Stack::DeleteAllElements()
{
	Index = -1;
}
ostream & operator<<(ostream &os, const Stack &v)
{
	for (int i = 0; i < v.Index + 1; i++)
	{
		os << *(v.Mem[i]);
	}
	return os;
}

//Turn

#include "Header.h"
Turn::Turn(int _TSize)
{
	TSize = _TSize;
	if (TSize <= 0)
	{
		throw - 1;
	}
	TMem = new TValue*[TSize];
	LowIndex = 0;
	HighIndex = TSize - 1;
}
Turn::Turn(const Turn &b)
{
	TSize = b.TSize;
	LowIndex = b.LowIndex;
	HighIndex = b.HighIndex;
	TMem = new TValue*[TSize];
	int i = LowIndex;
	while (i != (HighIndex + 1) % TSize)
	{
		TMem[i] = b.TMem[i];
		i = (i + 1) % TSize;
	}
}
bool Turn::IsTurnEmpty()
{
	return (LowIndex == (HighIndex + 1) % TSize);
}
bool Turn::IsTurnFull()
{
	return (LowIndex == (HighIndex + 2) % TSize);
}

Stack Turn::Polish()
{
	Stack Result(TSize);
	Stack Op(TSize);
	Stack Temp(TSize);
	Turn test(TSize);
	TValue * temp1 = new Top('+');
	TValue * temp2 = new Top('-');
	TValue * temp3 = new Top('*');
	TValue * temp4 = new Top('/');
	TValue * temp5 = new Top('(');
	TValue * temp6 = new Top(')');
	int i = LowIndex;
	while (i != (HighIndex + 1) % TSize)
	{
		if ((TMem[i]->prior() == -1))
		{
			Result.AddElement(TMem[i]);
		}
		else
		{
			if (Op.IsStackEmpty())
			{
				Op.AddElement(TMem[i]);
			}
			else
			{
				if (TMem[i]->prior() == 0)
				{
					Op.AddElement(TMem[i]);
				}
				if (TMem[i]->prior() == 1)
				{
					while ((Op.RetCur())->prior() != 0)
					{
						Result.AddElement(Op.DeleteElement());
					}
					Op.DeleteElement();
				}
				if (TMem[i]->prior() == 2)
				{
					if ((Op.RetCur())->prior() >= 2)
					{
						while ((Op.IsStackEmpty() != true)&&(((Op.RetCur())->prior() >= 2) == true))
						{
							Result.AddElement(Op.DeleteElement());
						}
						Op.AddElement(TMem[i]);
					}
					if ((Op.RetCur())->prior() == 0)
					{
						Op.AddElement(TMem[i]);
					}
				}
				if (TMem[i]->prior() == 3)
				{
					if ((Op.RetCur())->prior() == 3)
					{
						Result.AddElement(Op.DeleteElement());
						Op.AddElement(TMem[i]);
					}
					if ((Op.RetCur())->prior() < 3)
					{
						Op.AddElement(TMem[i]);
					}
				}
			}
		}
		i++;
		cout << i << ")" << Result << "|||||" << Op << "\n";
	} 
	while (Op.IsStackEmpty() == false)
	{
		Result.AddElement(Op.DeleteElement());
	}
	cout << i << ")" << Result << "|||||" << Op << "\n";
	return Result;
}

int Turn::TGetSize()
{
	return TSize;
}
void Turn::TAddElement(TValue * Elem)
{
	if (IsTurnFull())
	{
		throw - 2;
	}
	HighIndex = (HighIndex + 1) % TSize;
	TMem[HighIndex] = Elem;
}
TValue * Turn::TDeleteElement()
{
	if (IsTurnEmpty())
	{
		throw - 3;
	}
	TValue * k = TMem[LowIndex];
	LowIndex = (LowIndex + 1) % TSize;
	return k;
}
TValue *& Turn::operator [](int index)
{
	return TMem[index];
}

ostream & operator <<(ostream &os, TValue &v)
{
	v.print(os);
	return os;
}

ostream & operator<<(ostream &os, const Turn &v)
{
	for (int i = 0; i < (v.HighIndex + 1) % v.TSize; i++)
	{
		cout << *(v.TMem[i]);
	}
	return os;
}
int POS(char *s, char c)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return i;
		}
		i++;
	}
	return -1;
}
bool StrCor(char *string)
{
	int i = 0;
	int cnt = 0;
	char s[] = "+-*/()";
	char t[] = "+-*/";
	char k1 = '(';
	char k2 = ')';
	if (i == 0)
	{
		if (POS(t, string[i]) >= 0)
		{
			return false;
		}
	}
	while (string[i] != '\0')
	{
		if (string[i] == ')')
		{
			cnt--;
			if (cnt < 0)
			{
				return false;
			}
		}
		if (i > 0)
		{
			if (((string[i] >= '0') && (string[i] <= '9')) && string[i - 1] == k2)
			{
				return false;
			}
		}
		if (i > 0)
		{
			if ((POS(t, string[i]) >= 0) && string[i - 1] == k1)
			{
				return false;
			}
		}
		if (i > 0)
		{
			if ((POS(t, string[i]) >= 0) && string[i + 1] == k2)
			{
				return false;
			}
		}
		if (string[i + 1] != '\0')
		{
			if (((string[i] >= '0') && (string[i] <= '9')) && string[i + 1] == k1)
			{
				return false;
			}
		}
		if (i > 0)
		{
			if ((POS(t, string[i]) >= 0) && (POS(t, string[i - 1]) >= 0))
			{
				return false;
			}
		}
		if (string[i] == '(')
		{
			cnt++;
		}
		if ((((string[i] >= '0') && (string[i] <= '9')) || (POS(s, string[i]) >= 0)) == false)
		{
			return false;
		}
		i++;
	}
	i--;
	if (POS(t, string[i]) >= 0)
	{
		return false;
	}
	if (cnt > 0)
	{
		return false;
	}
	return true;
}
