#include <gtest/gtest.h>
#include "Sphere.hpp"

TEST(Sphere, intersection)
{
	Vector3 sphere_origin { 0.0, 0.0, 0.0 };
	Sphere sphere { sphere_origin, 1.0, Vector3 {} };
	
	Vector3 ray_origin { 1.0, 1.0, 1.0 };
	Vector3 ray_direction { -1.0, -1.0, -1.0 };
	Ray ray { ray_origin, ray_direction };

	HitRecord closer { sphere.hit(ray, 0.0, std::numeric_limits<float>::infinity()) };
	HitRecord further { sphere.hit(ray, 1.0, std::numeric_limits<float>::infinity()) };

	// checks if the value is equal, assuming 2 digit precision
	ASSERT_EQ(std::fabs(closer.t - 0.42) < 0.01, true);
	ASSERT_EQ(std::fabs(further.t - 1.57) < 0.01, true);
}

TEST(Sphere, get_normal)
{
	Vector3 sphere_origin { 0.0, 0.0, 0.0 };
	Sphere sphere { sphere_origin, 1.0, Vector3 {} };

	Vector3 ray_origin { 1.0, 1.0, 1.0 };
	Vector3 ray_direction { -1.0, -1.0, -1.0 };
	Ray ray { ray_origin, ray_direction };

	HitRecord closer { sphere.hit(ray, 0.0, std::numeric_limits<float>::infinity()) };
	HitRecord further { sphere.hit(ray, 1.0, std::numeric_limits<float>::infinity()) };

	for (int i = 0; i < 3; i++)
	{
		ASSERT_EQ(std::fabs(closer.normal[i] - 0.58) < 0.01, true);
		ASSERT_EQ(std::fabs(further.normal[i] + 0.58) < 0.01, true);
	}
}