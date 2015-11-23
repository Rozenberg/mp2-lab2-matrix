#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> a(4);
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; a[0][3] = 4;
	a[1][1] = 2; a[1][2] = 3; a[1][3] = 4;
	a[2][2] = 3; a[2][3] = 4;
	a[3][3] = 4;

	TMatrix<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> b;
	ASSERT_NO_THROW(TMatrix<int> b(b));
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> a(5);
	EXPECT_EQ(5, a.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(4);
	v[0][0] = 4;
	EXPECT_EQ(4, v[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> a(4);
	ASSERT_ANY_THROW(a[-5]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> a(4);
	ASSERT_ANY_THROW(a[MAX_MATRIX_SIZE + 1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> a(4);
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; a[0][3] = 4;
	 a[1][1] = 2; a[1][2] = 3; a[1][3] = 4;
	 a[2][2] = 3; a[2][3] = 4;
	 a[3][3] = 4;

	ASSERT_NO_THROW(a = a);
}

TEST(TMatrix, can_assign_matrixes_of_equal_size)
{
	TMatrix<int> a(4), b(4);
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; a[0][3] = 4;
	 a[1][1] = 2; a[1][2] = 3; a[1][3] = 4;
	 a[2][2] = 3; a[2][3] = 4;
	 a[3][3] = 4;
	
	b[0][0] = 1; b[0][1] = 2; b[0][2] = 3; b[0][3] = 4;
	 b[1][1] = 2; b[1][2] = 3; b[1][3] = 4;
	 b[2][2] = 3; b[2][3] = 4;
	 b[3][3] = 4;

	ASSERT_NO_THROW(a = b);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> a(4);
	a = 6;
	EXPECT_EQ(6, a.GetSize());
}

TEST(TMatrix, can_assign_matrixes_of_different_size)
{
	TMatrix<int> a(4), b(6);
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; a[0][3] = 4;
	 a[1][1] = 2; a[1][2] = 3; a[1][3] = 4;
	 a[2][2] = 3; a[2][3] = 4;
	 a[3][3] = 4;

	 b[0][0] = 1; b[0][1] = 2; b[0][2] = 3; b[0][3] = 4; b[0][4] = 4; b[0][5] = 4;
	 b[1][1] = 1; b[1][2] = 2; b[1][3] = 3; b[1][4] = 4; b[1][5] = 2;
	b[2][2] = 1; b[2][3] = 2; b[2][4] = 3; b[2][5] = 3;
	b[3][3] = 1; b[3][4] = 2; b[1][5] = 4;

	ASSERT_NO_THROW(a = b);
}

TEST(TMatrix, compare_equal_matrixes_return_true)
{
	TMatrix<int> a(4), b;
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; a[0][3] = 4;
	 a[1][1] = 2; a[1][2] = 3; a[1][3] = 4;
	 a[2][2] = 3; a[2][3] = 4;
	 a[3][3] = 4;
	b = a;
	ASSERT_TRUE(a == b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> a(4);
	ASSERT_TRUE(a == a);
}

TEST(TMatrix, matrixes_with_different_size_are_not_equal)
{
	TMatrix<int> a(2), b(4);
	ASSERT_FALSE(a == b);
}

TEST(TMatrix, can_add_matrixes_with_equal_size)
{
	TMatrix<int> a(2), b(2), c(2);
	//---//
	a[0][0] = 1; a[0][1] = 2; 	a[1][1] = 3;
	//---//
	b[0][0] = 4; b[0][1] = 5; 	b[1][1] = 6;
	//---//
	c[0][0] = 5; a[0][1] = 7; 	a[1][1] = 9;

	EXPECT_EQ(c, b + a);
}

TEST(TMatrix, cant_add_matrixes_with_not_equal_size)
{
	TMatrix<int> a(3), b(5);
	ASSERT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrixes_with_equal_size)
{
	TMatrix<int> a(2), b(2), c(2);
	//---//
	a[0][0] = 1; a[0][1] = 2; 	a[1][1] = 3;
	//---//
	b[0][0] = 4; b[0][1] = 5; 	b[1][1] = 6;
	//---//
	c[0][0] = 3; a[0][1] = 3; 	a[1][1] = 3;

	EXPECT_EQ(c, b - a);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> a(2), b(4);
	ASSERT_ANY_THROW(a - b);
}

