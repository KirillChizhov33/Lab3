//Stack
#include "Header.h"
Stack::Stack(int _Size)
{
	Size = _Size;
	Mem = new int[Size];
	Index = -1;
}
Stack::Stack(const Stack &b)
{
	Size = b.Size;
	Index = b.Index;
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
	Mem = new int[Size];
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
	return Index;
}
void Stack::AddElement(int Elem)
{
	if (IsStackFull())
	{
		throw - 1;
	}
	Index++;
	Mem[Index] = Elem;
}
int Stack::DeleteElement()
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
		os << v.Mem[i] << "\n";
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
	TMem = new TValue [TSize];
	LowIndex = 0;
	HighIndex = TSize - 1;
}
Turn::Turn(const Turn &b)
{
	TSize = b.TSize;
	LowIndex = b.LowIndex;
	HighIndex = b.HighIndex;
	TMem = new TValue[TSize];
	int i = LowIndex;
	while (i != HighIndex + 1)
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
void Turn::TAddElement(TValue * Elem)
{
	if (IsTurnFull())
	{
		throw - 2;
	}
	HighIndex = (HighIndex + 1) % TSize;
	TMem[HighIndex] = *Elem;
}
TValue & Turn::TDeleteElement()
{
	if (IsTurnEmpty())
	{
		throw - 3;
	}
	TValue & k = TMem[LowIndex];
	LowIndex = (LowIndex + 1) % TSize;
	return k;
}
TValue & Turn::operator [](int index)
{
	return TMem[index];
}
ostream & operator<<(ostream &os, const Turn &v)
{
	for (int i = 0; i < v.HighIndex+1; i++)
	{
		cout << v.TMem[i] << "\n" ;
	}
	return os;
}
