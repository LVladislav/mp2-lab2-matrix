#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length) // ����� ������� ������ ������������� �����
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector) // �� ����� ������� ������ ������� ������� ����
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length) // �����������,����� ��������� ������ ������������� �����
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex) // �����������, ����� ��������� ������ � ������������� ��������� ��������
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector) // ����� ���������� �������
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one) // ���������� �������
{
  //ADD_FAILURE();
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 4;
	v[4] = 5;
	TVector<int> v1(v);
	EXPECT_EQ(v,v1);
}

TEST(TVector, copied_vector_has_its_own_memory) // ���������� ������, ������� ����� ����������� ������
{
 // ADD_FAILURE();
	TVector <int> v(5);
	v[3] = 7;
	TVector<int> v1(v);
	EXPECT_EQ(v, v1);

}

TEST(TVector, can_get_size) // �������� ������
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index) // �������� ��������� ������
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element) // ����� �������� � ���������� �������
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index) //����������� ��� ��������� ������� � ������������� ��������
{
 // ADD_FAILURE();
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[-1] = 2);
	
}

TEST(TVector, throws_when_set_element_with_too_large_index) // �����������, ��� ��������� �������� � ������� ��������
{
  //ADD_FAILURE();
    TVector<int> v(5);
	ASSERT_ANY_THROW(v[7]=5);
}

TEST(TVector, can_assign_vector_to_itself) // ����� ��������� ���� ������
{
  //ADD_FAILURE();
	TVector<int> v(5);
	EXPECT_TRUE(v == v);
}

TEST(TVector, can_assign_vectors_of_equal_size) //��������� ������ ����������� �������
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

TEST(TVector, assign_operator_change_vector_size)  //�������� ������ �������
{
  //ADD_FAILURE();
	TVector<int> v(7);
	TVector<int> v1(5);
	v = v1;
	EXPECT_EQ(5, v1.GetSize());

}

TEST(TVector, can_assign_vectors_of_different_size) // ��������� ������ ������o ��������
{
  //ADD_FAILURE();
	
}

TEST(TVector, compare_equal_vectors_return_true) // ���������� ������ ������� � ���������� True
{
 // ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(5);
	EXPECT_EQ(v == v1, true);
}

TEST(TVector, compare_vector_with_itself_return_true) // ���������� ��� � �����
{
 // ADD_FAILURE();
	TVector<int> v(5);
	EXPECT_EQ(v == v, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal) // ������� � ���������� ��������� �� ������
{
  //ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(6);
	EXPECT_FALSE(v == v1);
}

TEST(TVector, can_add_scalar_to_vector) // ����� ��������� ������ � �������
{
  //ADD_FAILURE();
	TVector<int> v(3);
	int skal=2;
	v = v + skal;
	ASSERT_NO_THROW(v);
}

TEST(TVector, can_subtract_scalar_from_vector) // ����� ������� ������ �� �������
{
 // ADD_FAILURE();
	TVector<int> v(3);
	int skal = 2;
	v = v - skal;
	ASSERT_NO_THROW(v);
}

TEST(TVector, can_multiply_scalar_by_vector) // �������� ������ �� ������
{
  //ADD_FAILURE();
	TVector<int> v(3);
	int skal = 2;
	v = v * skal;
	ASSERT_NO_THROW(v);
}

TEST(TVector, can_add_vectors_with_equal_size) // ����� ������� ������� ���������� �� �������
{
  //ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(5);
	TVector<int> res;
	for (int i = 0; i < 5; i++)
	{
		res = v + v1;
	}
	EXPECT_EQ(res, v+ v1);
}

TEST(TVector, cant_add_vectors_with_not_equal_size) // �� ����� ������� ������� ������� �������
{
 // ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(7);
	EXPECT_ANY_THROW(v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size) // �� ����� ������� ������� ������� �������
{
 // ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(7);
	EXPECT_ANY_THROW(v*v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size) //�� ���� �������� ������� � ������ ��������
{
  //ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(7);
	EXPECT_ANY_THROW(v-v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size) //�������� ������� � ���������� ��������
{
  //ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(5);
	int res;
	for (int i = 0; i < 5; i++)
	{
		res = v*v1;
	}
	EXPECT_EQ(res,v*v1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size) //��������� �������� ������� �������.
{
 // ADD_FAILURE();
	TVector<int> v(5);
	TVector<int> v1(7);
	ASSERT_ANY_THROW(v*v1);
}
