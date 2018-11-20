#pragma once
#include <iostream>
using namespace std;
class Stack
{
	int Size;
	int Index;
	int * Mem;
	Stack() {};
public:
	Stack(int _Size);
	Stack(const Stack &b);
	Stack & operator =(const Stack &b);
	bool IsStackEmpty();
	bool IsStackFull();
	int GetSize();
	void AddElement(int Elem);
	int DeleteElement();
	void DeleteAllElements();
	friend ostream & operator<<(ostream &os, const Stack &v);
};


class Turn
{
	int * Mem;
	int Size;
	int LowIndex;
	int HighIndex;
public:
	Turn() {};
	Turn(int _Size);
	Turn(const Turn &b);
	bool IsTurnEmpty();
	bool IsTurnFull();
	void AddElement(int Elem);
	int DeleteElement();
	int & operator [](int index);
	friend ostream & operator<<(ostream &os, const Turn &v);
};
