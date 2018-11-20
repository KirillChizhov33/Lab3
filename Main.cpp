#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "Header.h"
#define ADD  1  /* Сложение */
#define SUB  2  /* Вычитание */
#define MUL  3  /* Умножение */
#define DIV  4  /* Деление */
int main()
{
	Stack A(100);//Стек для операндов
	Stack B(100);//Стек для операций
	Turn C(100);//Очередь стандартная
	Turn D(100);//Очередь польская запись
	int op = 0;
	int a;
	char b;
	int k = 0;
	int sum = 0;
	while (op != 7)
	{
		printf("\n");
		printf("1.Add(+)\n");
		printf("2.Subtract(-)\n");
		printf("3.Multiplication(*)\n");
		printf("4.Division(/)\n");
		printf("5.AGetSize\n");
		printf("6.BGetSize\n");
		scanf("%d", &op);
		switch (op)
		{
		case ADD:
			cin >> a;
			cout << a;
			b = '+';
			C.AddElement(a);
			D.AddElement(a);
			A.AddElement(a);
			B.AddElement(b);
			system("cls");
			sum += a;
			cout << sum;
			break;
		case SUB:
			cin >> a;
			cout << a;
			b = '-';
			C.AddElement(a);
			D.AddElement(a);
			A.AddElement(a);
			B.AddElement(b);
			system("cls");
			sum -= a;
			cout << sum;
			break;
		case MUL:
			cin >> a;
			cout << a;
			b = '*';
			C.AddElement(a);
			D.AddElement(a);
			A.AddElement(a);
			B.AddElement(b);
			system("cls");
			sum *= a;
			cout << sum;
			break;
		case DIV:
			cin >> a;
			cout << a;
			if (a == 0)
			{
				cout << "Div 0";
			}
			b = '/';
			C.AddElement(a);
			D.AddElement(a);
			A.AddElement(a);
			B.AddElement(b);
			system("cls");
			sum /= a;
			cout << sum;
			break;
		case 5:
			k = A.GetSize();
			cout << k + 1 <<"\n";
			cout << A;
			break;
		case 6:
			k = B.GetSize();
			cout << k + 1 << "\n";
			cout << B;
			break;
		}
	}
	return 0;
}
