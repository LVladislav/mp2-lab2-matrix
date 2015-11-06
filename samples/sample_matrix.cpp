// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
	//TMatrix<int> a(5), b(5), c(5);
	int i, j;

	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки представления треугольных матриц"
		<< endl;

	TVector<int> a(5), b(5), c;
	cout << "Input vector a: ";
	cin >> a;
	cout << "Input vector b: ";
	cin >> b;
	c = a + b;
	cout << "a+b= " << c << endl;
	c = a - b;
	cout << "a-b= " << c << endl;
	int z = a * b;
	cout << "a*b= " << z << endl;
	if (a == b)
	{
		cout << "Верно!\n";
	}
	else
	{
		cout << "Не верно!\n";
	}
	if (a != b)
	{
		cout << "Верно!\n";
	}
	else
	{
		cout << "Не верно!\n";
	}
	c = a + 2;
	cout << "a+2= " << c << endl;
	c = b - 2;
	cout << "b-2= " << c << endl;
	c = a * 2;
	cout << "a*2= " << c << endl;
	/*
	for (i = 0; i < 5; i++)
	for (j = i; j < 5; j++ )
	{
	a[i][j] =  i * 10 + j;
	b[i][j] = (i * 10 + j) * 100;
	}
	c = a + b;
	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "Matrix c = a + b" << endl << c << endl;
	*/
}
//---------------------------------------------------------------------------
