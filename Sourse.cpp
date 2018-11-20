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

//Turn

#include "Header.h"
Turn::Turn(int _Size)
{
	Size = _Size;
	if (Size <= 0)
	{
		throw - 1;
	}
	Mem = new int[Size];
	LowIndex = 0;
	HighIndex = Size - 1;
}
Turn::Turn(const Turn &b)
{
	Size = b.Size;
	LowIndex = b.LowIndex;
	HighIndex = b.HighIndex;
	Mem = new int[Size];
	int i = LowIndex;
	while (i != HighIndex + 1)
	{
		Mem[i] = b.Mem[i];
		i = (i + 1) % Size;
	}
}
bool Turn::IsTurnEmpty()
{
	return (LowIndex == (HighIndex + 1) % Size);
}
bool Turn::IsTurnFull()
{
	return (LowIndex == (HighIndex + 2) % Size);
}

void Turn::AddElement(int Elem)
{
	if (IsTurnFull())
	{
		throw - 2;
	}
	HighIndex = (HighIndex + 1) % Size;
	Mem[HighIndex] = Elem;
}
int Turn::DeleteElement()
{
	if (IsTurnEmpty())
	{
		throw - 3;
	}
	int k = Mem[LowIndex];
	LowIndex = (LowIndex + 1) % Size;
	return k;
}
int & Turn::operator [](int index)
{
	return Mem[index];
}
ostream & operator<<(ostream &os, const Turn &v)
{
	for (int i = 0; i < v.Size; i++)
	{
		cout << v.Mem[i];
	}
	return os;
}