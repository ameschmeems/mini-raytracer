#include <gtest/gtest.h>
#include <vector>
#include "Vector3.hpp"

TEST(Vector3, brackets)
{
	Vector3 v { 1.0, 2.0, 3.0 };
	std::vector<float> expected { 1.0, 2.0, 3.0 };
	for (int i = 0; i < 3; i++)
		ASSERT_EQ(v[i], expected[i]);
	v[0] = 6.0;
	ASSERT_EQ(v[0], 6.0);
}

TEST(Vector3, addition)
{
	Vector3 v { 1.0, 2.0, 3.0 };
	Vector3 w { 2.0, 3.0, 1.0 };
	Vector3 expected { 3.0, 5.0, 4.0 };
	ASSERT_EQ(v + w, expected);
}

TEST(Vector3, subtraction)
{
	Vector3 v { 3.0, 3.0, 2.0 };
	Vector3 w { 1, 2, 3 };
	Vector3 expected { 2.0, 1.0, -1.0 };
	ASSERT_EQ(v - w, expected);
}

TEST(Vector3, scalarMultiplication)
{
	Vector3 v { 1.0, 2.0, 3.0 };
	Vector3 expected { 2.0, 4.0, 6.0 };
	ASSERT_EQ(v * 2, expected);
	ASSERT_EQ(2 * v, expected);
}

TEST(Vector3, assignment)
{
	Vector3 v { 1.0, 2.0, 3.0 };
	Vector3 w {};
	Vector3 x {};
	w = v;
	ASSERT_EQ(v, w);
	ASSERT_NE(v, x);
}

TEST(Vector3, length)
{
	Vector3 v { 2.0, 3.0, 6.0 };
	ASSERT_EQ(v.length(), 7.0);
}

TEST(Vector3, dotProduct)
{
	Vector3 v { 1.0, 0.0, 0.0 };
	Vector3 w { 0.0, 1.0, 0.0 };
	ASSERT_EQ(v.dot(v), 1.0);
	ASSERT_EQ(v.dot(w), 0.0);
}

TEST(Vector3, crossProduct)
{
	Vector3 v { 2.0, 3.0, 4.0 };
	Vector3 w { 5.0, 6.0, 7.0 };
	Vector3 expected { -3.0, 6.0, -3.0 };
	ASSERT_EQ(v.cross(w), expected);
}
