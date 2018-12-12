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
	char c[100] = "(28-7)*1-12/4*5-(1+3)*23-(67*88)";//== −5 982;
	//char c[100] = "(2+3)*5-2";//23+5*2-
	//char c[100] = "2+3";
	if (StrCor(c) == false)
	{
		cout << "False 1";
		return 0;
	}
	else
	{
		TLex R;
		C = R.convert(c);
		cout << C;
	}
	cout << "\n\n" << "Polish:" << endl;
	D = C.Polish();
	cout << D;
	int output = D.ExpressionResult();
	cout <<"\n\n"<< output;
	return 0;
}
