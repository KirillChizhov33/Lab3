#pragma once
#include <string>
#include <iostream>
using namespace std;
class TValue
{
public:
	TValue() {}
	virtual int operation() = 0;
	virtual int prior() = 0;
	virtual void print(ostream &os) = 0;
	friend ostream & operator <<(ostream &os, TValue &v);
	virtual bool operator ==(const TValue & b) { return true; }
	virtual operator int() const = 0 ;
};


class Top : public TValue
{
	char c;
public:
	Top(char _c)
	{
		c = _c;
	}
	int prior()
	{
		if (c == '+' || c == '-')
		{
			return 2;
		}
		if (c == '*' || c == '/')
		{
			return 3;
		}
		if (c == '(')
		{
			return 0;
		}
		if (c == ')')
		{
			return 1;
		}
	}
	int operation()
	{
		if (c == '+')
		{
			return 1;
		}
		if (c == '-')
		{
			return 2;
		}
		if (c == '*')
		{
			return 3;
		}
		if (c == '/')
		{
			return 4;
		}
	}
	void print(ostream &os)
	{
		os << c;
	}
	bool operator ==(const Top & b)
	{
		if (c == b.c)
		{
			return true;
		}
		return false;
	}
	operator int() const
	{
		return 21;
	}
};

class Tint : public TValue
{
	int v;
public:
	Tint(int _v)
	{
		v = _v;
	}
	int prior()
	{
		return -1;
	}
	int operation()
	{
		return 0;
	}
	void print(ostream &os)
	{
		os << v;
	}
	bool operator ==(const Tint & b)
	{
		if (v == b.v)
		{
			return true;
		}
		return false;
	}
	operator int() const
	{
		return v;
	}
};
class Stack
{
	TValue ** Mem;
	int Size;
	int Index;
public:
	Stack() {};
	Stack(int _Size);
	Stack(const Stack &b);
	TValue * RetCur()
	{
		return Mem[Index];
	}
	Stack & operator =(const Stack &b);
	bool IsStackEmpty();
	bool IsStackFull();
	int GetSize();
	void AddElement(TValue *Elem);
	TValue * DeleteElement();
	void DeleteAllElements();
	friend ostream & operator<<(ostream &os, const Stack &v);
};

class Turn
{
	TValue ** TMem;
	int TSize;
	int LowIndex;
	int HighIndex;
public:
	Turn() {};
	Turn(int _TSize);
	Turn(const Turn &b);
	bool IsTurnEmpty();
	bool IsTurnFull();
	int TGetSize();
	Turn Polish();
	int ExpressionResult();
	void TAddElement(TValue * Elem);
	TValue * TDeleteElement();
	TValue *& operator [](int index);
	friend ostream & operator<<(ostream &os, const Turn &v);
};


class TLex
{
	Turn queue;
	std::string s;
public:
	TLex()
	{
		queue = Turn(100);
	}
	int pos(char *s, char c)
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
					queue.TAddElement(new Top(c));
				}
				if ((c >= '0') && (c <= '9'))
				{
					s = c;
					st = 1;
				}
				continue;
			}
			if (st == 1)
			{
				if ((c >= '0') && (c <= '9'))
				{
					s += c;
				}
				if (c == ' ')
				{
					queue.TAddElement(new Tint(atoi(s.c_str())));
					st = 0;
				}
				if (pos(op, c) >= 0)
				{
					queue.TAddElement(new Tint(atoi(s.c_str())));
					queue.TAddElement(new Top(c));
					st = 0;
				}
			}
		}
		if (st == 1)
		{
			queue.TAddElement(new Tint(atoi(s.c_str())));
		}
		return queue;
	}
};
bool StrCor(char *string);
