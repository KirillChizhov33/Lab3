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
	char c[100] = "(28-7)*111+23-(67*88)";
	TLex R(C);
	C = R.convert(c);
	cout << C;
	return 0;
}
