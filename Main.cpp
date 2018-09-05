#include<iostream>
#include"Tmatrix.h"
#include<conio.h>
#include"E:\Visual Studio 2013\Projects\Vectors\Vectors\Tvector.h"
using namespace std;
void main()
{
	TMatrix <double> a(3), b(3), c(3);
	cout << "Enter the matrix A" << endl;
	cin >> a;
	cout << "A= \n" << a << endl;
	cout << "B=A" << endl;
	b = a;
	cout << "B= \n" << b << endl;
	cout << "C=A-B" << endl;
	c = a - b;
	cout << "C= \n" << c << endl;
	cout << "C=A+B" << endl;
	c = a + b;
	cout << "C= \n" << c << endl;
	cout << "C=A*B" << endl;
	c = a*b;
	cout << "C= \n" << c << endl;
	cout << "Compare matrix A and matrix B" << endl;
	if (a == b)
		cout << "A and B are equal" << endl;
	else
		cout << "A and B are unequal" << endl;
	cout << a[5][3] << endl;
	_getch();
}