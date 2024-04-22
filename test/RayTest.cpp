#include <gtest/gtest.h>
#include "Ray.hpp"

TEST(Ray, evaluate)
{
	Vector3 origin { 0.0, 0.0, 0.0 };
	Vector3 direction { 1.0, 1.0, 1.0 };
	Ray ray { origin, direction };

	ASSERT_EQ(ray.evaluate(0), origin);
	ASSERT_EQ(ray.evaluate(1), direction);
	ASSERT_EQ(ray.evaluate(0.5), Vector3(0.5, 0.5, 0.5) );
}