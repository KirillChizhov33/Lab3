#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "Header.h"
int main()
{
	Stack A(100);//Стек для операндов
	Stack B(100);//Стек для операций
	Turn C(100);//Очередь стандартная
	Turn D(100);//Очередь польская запись
	char c[100] = "(28-7)*1-(1)-1+23-(67*88)";
	if (StrCor(c) == false)
	{
		cout << "False 1";
		return 0;
	}
	else
	{
		TLex R(C);
		C = R.convert(c);
		if (C.IsStringCorrect() == false)
		{
			cout << "False 2";
			return 0;
		}
		cout << C;
	}
	return 0;
}
