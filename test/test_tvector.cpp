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
	TVector<int> a(4);
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
	TVector<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> b;
	ASSERT_NO_THROW(TVector<int> b(b));
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

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[-2]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[6]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> a(5);
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5;
	ASSERT_NO_THROW(a = a);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> a(4), b(4);
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
	b[0] = 1; b[1] = 2; b[2] = 3; b[3] = 4;
	a = b;
	EXPECT_EQ(a, b);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> a(4);
	a = 6;
	EXPECT_EQ(6, a.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> a(3), b(4);
	a[0] = 1; a[1] = 2; a[2] = 3;
	//b = (3, 5, 10, 7)
	b[0] = 3; b[1] = 5;
	b[2] = 10; b[3] = 7;
	a = b;
	EXPECT_EQ(a, b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> a(4), b(4);
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
	b = a;
	ASSERT_TRUE(a == b);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> a(4);
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
	ASSERT_TRUE(a == a);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> a(5), b(7);
	ASSERT_FALSE(a == b);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> a(4), b(4);
	//a = (7, 8, 9, 10)
	a[0] = 7; a[1] = 8;
	a[2] = 9; a[3] = 10;
	int k = 8;
	//b = (15, 16, 17, 18)
	b[0] = 15; b[1] = 16;
	b[2] = 17; b[3] = 18;

	EXPECT_EQ(b, a + k);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> a(4), b(4);
	//a = (5, 6, 7, 8)
	a[0] = 5; a[1] = 6;
	a[2] = 7; a[3] = 8;
	int k = 4;
	//b = (1, 2, 3, 4)
	b[0] = 1; b[1] = 2;
	b[2] = 3; b[3] = 4;
	EXPECT_EQ(b, a - k);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> a(4), b(4);
	//a = (1, 2, 3, 4)
	a[0] = 1; a[1] = 2;
	a[2] = 3; a[3] = 4;
	int k = 5;
	//b = (5, 10, 15, 20)
	b[0] = 5; b[1] = 10;
	b[2] = 15; b[3] = 20;
	EXPECT_EQ(b, a * k);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> a(4), b(4), c(4);
	//a = (2, 3, 4, 5)
	a[0] = 2; a[1] = 3;
	a[2] = 4; a[3] = 5;
	//b = (4, 3, 2, 1)
	b[0] = 4; b[1] = 3;
	b[2] = 2; b[3] = 1;
	//c = (6, 6, 6, 6)
	c[0] = 6; c[1] = 6;
	c[2] = 6; c[3] = 6;
	EXPECT_EQ(c, a + b);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> a(5), b(9);
	ASSERT_ANY_THROW(a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> a(4), b(4), c(4);
	//a = (9, 8, 7, 6)
	a[0] = 9; a[1] = 8;
	a[2] = 7; a[3] = 6;
	//b = (1, 3, 2, 4)
	b[0] = 1; b[1] = 3;
	b[2] = 2; b[3] = 4;
	//c = (8, 5, 5, 2)
	c[0] = 8; c[1] = 5;
	c[2] = 5; c[3] = 2;
	EXPECT_EQ(c, a - b);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> a(3), b(6);
	ASSERT_ANY_THROW(a - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> a(4), b(4);
	//a = (1, 2, 3, 4)
	a[0] = 1; a[1] = 2;
	a[2] = 3; a[3] = 4;
	//b = (1, 4, 7, 8)
	b[0] = 1; b[1] = 4;
	b[2] = 7; b[3] = 8;
	EXPECT_EQ(62, a*b);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> a(4), b(5);
	ASSERT_ANY_THROW(a*b);
}

