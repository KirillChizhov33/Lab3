#pragma once
#include <string>
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

class TValue
{
public:
	TValue(){}
	virtual int prior() = 0;
};

class Top : public TValue
{
public:
	Top(char c) {};
	int prior()
	{
		return 0;
	}
};

class Tint : public TValue
{
public:
	Tint(int v) {};
	int prior()
	{
		return 0;
	}
};

class Turn
{
	TValue * TMem;
	int TSize;
	int LowIndex;
	int HighIndex;
public:
	Turn() {};
	Turn(int _TSize);
	Turn(const Turn &b);
	bool IsTurnEmpty();
	bool IsTurnFull();
	void TAddElement(TValue * Elem);
	TValue & TDeleteElement();
	TValue  & operator [](int index);
	friend ostream & operator<<(ostream &os, const Turn &v);
	void push(TValue *v)
	{

	}

};


class TLex
{
	Turn queue;
	std::string s;
public:
	TLex(Turn _queue)
	{
		queue = _queue;
	}
	int pos(char *s, char c)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == c)
			{
				return i;
				i++;
			}
		}
		return -1;
	}
	Turn & convert(char * str)
	{
		int st = 0;
		int i = 0;
		char c;
		char op[] = "+-*/()";
		while (str[i] != '\0')
		{
			c = str[i];
			i++;
			if (st == 0)
			{
				if (c == ' ') {}
				if (pos(op, c) >= 0)
				{
					queue.push(new Top(c));
				}
			}
			if ((c >= '0') && (c <= '9'))
			{
				s = c;
				st = 1;
			}
			if (st == 1)
			{
				if ((c >= '0') && (c <= '9'))
				{
					s += c;
				}
				if (c == ' ')
				{
					queue.push(new Tint(atoi(s.c_str())));
					st = 0;
				}
				if (pos(op, c) >= 0)
				{
					queue.push(new Tint(atoi(s.c_str())));
					queue.push(new Top(c));
					st = 0;
				}
			}
		}
		if (st == 1)
		{
			queue.push(new Tint(atoi(s.c_str())));
			return queue;
		}
	}
};
