#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  //ADD_FAILURE();
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 4;
	v[4] = 5;
	TVector<int> a(v);
	EXPECT_EQ(v,a);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
 // ADD_FAILURE();
	TVector <int> v(5);
	v[3] = 7;
	TVector<int> s(v);
	EXPECT_EQ(v, s);

}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index) //выбрасывает при установке эемента с отрицательным индексом
{
 // ADD_FAILURE();
	
	
}

TEST(TVector, throws_when_set_element_with_too_large_index) // выбрасывает, при установке элемента с большим индексом
{
  //ADD_FAILURE();
TVector<int> v(4);

	ASSERT_ANY_THROW(v[7]=5);

}

TEST(TVector, can_assign_vector_to_itself)
{
  //ADD_FAILURE();
	TVector<int> v(5);
	EXPECT_TRUE(v == v);
}

TEST(TVector, can_assign_vectors_of_equal_size) //назначить вектор одинакового размера
{
 // ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 4;
	v[4] = 5;
	
	v1 = v;

	EXPECT_EQ(v1,v);


}

TEST(TVector, assign_operator_change_vector_size)  //изменить размер вектора
{
  //ADD_FAILURE();
	TVector<int> v(7);
	TVector<int> v1(5);
	v = v1;
	EXPECT_EQ(5, v1.GetSize());

}

TEST(TVector, can_assign_vectors_of_different_size) // назначить вектор разногo оразмера
{
  //ADD_FAILURE();
	
}

TEST(TVector, compare_equal_vectors_return_true) // сравниваем равные вектора и возвращаем True
{
 // ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(5);
	EXPECT_EQ(v == v1, true);
}

TEST(TVector, compare_vector_with_itself_return_true) // сравниваем сам с собой
{
 // ADD_FAILURE();
	TVector<int> v(5);
	EXPECT_EQ(v == v, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal) // вектора с различными размерами не равные
{
  //ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(6);
	EXPECT_FALSE(v == v1);
}

TEST(TVector, can_add_scalar_to_vector) // добавить скаляр и вектор
{
  //ADD_FAILURE();

}

TEST(TVector, can_subtract_scalar_from_vector)
{
  ADD_FAILURE();
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  ADD_FAILURE();
}

TEST(TVector, can_add_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size) //не могу вычитать векторы с разным размером
{
  //ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(7);
	EXPECT_EQ(v - v1, false);
}

TEST(TVector, can_multiply_vectors_with_equal_size) //умножать векторы с одинаковым размером
{
  //ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(5);
	EXPECT_ANY_THROW(v*v1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size) //умножение векторов разного размера.
{
 // ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(7);
	ASSERT_ANY_THROW(v*v1);
}

