#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length) // можно создавать матрицы продолжительной длины
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix) // не может создать матрицы слишком большой длины
{
 ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length) // отбрасывает, когда создаются матрицы отрицательной длины
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix) // создает скопированную матрицу
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one) //скопировал матрицу в первый источник
{
  //ADD_FAILURE();
	TMatrix<int> m(3);
	/*m[0][0] = 1;
	m[0][1] = 2;
	m[0][2] = 3;
	m[1][1] = 4;
	m[1][2] = 5;
	m[2][2] = 6;*/
	for (int i = 0; i < 3; i++)
	{
		m[i][i] = i;
	}
	TMatrix<int> m1(m);
	EXPECT_EQ(m1,m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory) // копирует матрицу, имеющую собственную память   //???????????????????????????????????????????????????????????????????????
{
 // ADD_FAILURE();
	TMatrix<int> m(5);
	m[1][2] = 3;
	TMatrix<int> m1(m);
	m1[1][2] = 4;
	EXPECT_NE(m[1][2],m1[1][2]);
}

TEST(TMatrix, can_get_size) // можем получить размер
{
 // ADD_FAILURE();
	TMatrix<int> m(3);
	EXPECT_EQ(3, m.GetSize());

}

TEST(TMatrix, can_set_and_get_element) //можно установить и получить элемент
{
 //ADD_FAILURE();
	TMatrix<int> m(3);
	m[0][0] = 1;
	EXPECT_EQ(m[0][0] = 1, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index) //выкидывает, при установки элемента с отрицательным индексом
{
 // ADD_FAILURE();
	TMatrix<int> m(3);
	ASSERT_ANY_THROW(m[1][-1] = 3);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index) // выкидывать, при установке слишком большого индекса
{
  //ADD_FAILURE();
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[3][5] = 6);
}

TEST(TMatrix, can_assign_matrix_to_itself) // матрица может присваиваться сама себе
{
  //ADD_FAILURE();
	TMatrix<int> m(3);
	/*m[0][0] = 1;
	m[0][1] = 2;
	m[0][2] = 3;
	m[1][1] = 4;
	m[1][2] = 5;
	m[2][2] = 6;*/
	for (int i = 0; i < 3; i++)
	{
		m[i][i] = i;
	}
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size) // можем присвать матрицы одинакого размера
{
  //ADD_FAILURE();
	TMatrix<int> m(3);
	/*m[0][0] = 1;
	m[0][1] = 2;
	m[0][2] = 3;
	m[1][1] = 4;
	m[1][2] = 5;
	m[2][2] = 6;*/
	for (int i = 0; i < 3; i++)
	{
		m[i][i] = i;
	}
	TMatrix<int> m1(3);
	ASSERT_NO_THROW(m1 = m);
}

TEST(TMatrix, assign_operator_change_matrix_size) //назначить оператору матрицу измененного размера
{
  //ADD_FAILURE();
	TMatrix<int> m(5);
	TMatrix<int> m1(7);
	for (int i = 0; i < 5; i++)
	{
		m[i][i] = i;
	}
	ASSERT_NO_THROW(m1 = m);
}

TEST(TMatrix, can_assign_matrices_of_different_size) // можем присвоить матрицы разного размера
{
 // ADD_FAILURE();
	TMatrix<int> m(3);
	TMatrix<int> m1(4);
	/*m[0][0] = 1;
	m[0][1] = 2;
	m[0][2] = 3;
	m[1][1] = 4;
	m[1][2] = 5;
	m[2][2] = 6;*/
	for (int i = 0; i < 3; i++)
	{
		m[i][i] = i;
	}
	ASSERT_NO_THROW(m1 = m);
}

TEST(TMatrix, compare_equal_matrices_return_true) // сравниваем матрицы и возвращает TRUE
{
 // ADD_FAILURE();
	TMatrix<int> m(3);
	TMatrix<int> m1(3);
	m[1][1] = 4;
	m1[1][1] = 4;
	ASSERT_TRUE(m == m1);
	
}

TEST(TMatrix, compare_matrix_with_itself_return_true) // сравниваем матрицу с  самой собой и возвращаем TRUE
{
  //ADD_FAILURE();
	TMatrix<int> m(3);
	m[1][1] = 4;
	ASSERT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal) // матрицы с различными размерами не равны
{
  //ADD_FAILURE();
	TMatrix<int> m(5);
	TMatrix<int> m1(3);
	m[1][1] = 4;
	m1[1][1] = 4;
	EXPECT_NE(m, m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size) //можем сложить матрицы одинакового размера
{
  //ADD_FAILURE()
	TMatrix<int> m(3);
	TMatrix<int> m1(3);
	m[1][1] = 4;
	m1[1][1] = 4;
	ASSERT_NO_THROW(m+m1);

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size) // можем сложить матрицы разного размера
{
	//ADD_FAILURE();
	TMatrix<int> m(3);
	TMatrix<int> m1(5);
	m[1][1] = 4;
	m1[2][2] = 4;
	EXPECT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size) // можем вычесть матрицы одинакового размера
{
 // ADD_FAILURE();
	TMatrix<int> m(5);
	TMatrix<int> m1(5);
	m[1][1] = 4;
	m1[1][1] = 4;
	EXPECT_NO_THROW(m - m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size) // можем вычесть матрицы разного размера
{
  //ADD_FAILURE();
	TMatrix<int> m(5);
	TMatrix<int> m1(3);
	m[1][1] = 4;
	m1[2][2] = 4;
	EXPECT_ANY_THROW(m - m1);
}
