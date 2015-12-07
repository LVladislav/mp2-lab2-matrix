// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include <time.h>
//---------------------------------------------------------------------------

void main()
{
  
  int i, j;
  clock_t time;
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"<< endl;

  /*TVector<int> A(5), B(5), C;
  cout << "Input vector a: ";
  cin >> A;
  cout << "Input vector b: ";
  cin >> B;
  C = A + B;
  cout << "a+b= " << C << endl;
  C = A - B;
  cout << "a-b= " << C << endl;
  int Z = A * B;
  cout << "a*b= " << Z << endl;
  if (A == B)
  {
	  cout << "Верно!\n";
  }
  else
  {
	  cout << "Не верно!\n";
  }
  if (A != B)
  {
	  cout << "Верно!\n";
  }
  else
  {
	  cout << "Не верно!\n";
  }
  C = A + 2;
  cout << "a+2= " << C << endl;
  C = B - 2;
  cout << "b-2= " << C << endl;
  C = A * 2;
  cout << "a*2= " << C << endl;
  */
  cout << endl;
  cout << endl;
  TMatrix<int> a(10), b(10), c(10);
  time = clock();
  for (i = 0; i < 10; i++)
    for (j = i; j < 10; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 10;
   time = clock() - time;
    }
  c = a + b;

  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  
  printf("time=%f\n", (double)time / CLOCKS_PER_SEC);
  
}
//---------------------------------------------------------------------------
