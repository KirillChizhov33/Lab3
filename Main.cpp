#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "Header.h"
int main()
{
	Turn C(100);
	Turn D(100);
	char c[100] = "(28-7)*1-12/4*5-(1+3)*23-(67*88)";//== −5 982;
	char d[100] = "(12+8)*3/(2+13)+7*4-1";
	char e[100] = " 2+3*5-9";
	if (StrCor(c) == false)
	{
		cout << "False 1";
		return 0;
	}
	else
	{
		TLex R;
		C = R.convert(c);
		cout << "\n\n\n\n";
		cout << "     1)"<< C;
	}
	cout << "\n\n" << "Polish:" << endl;
	D = Polish(C);
	cout << D;
	int output = ExpressionResult(D);
	cout << " = " << output << "\n"<<endl;
	return 0;
}
