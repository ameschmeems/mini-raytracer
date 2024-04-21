#ifndef SPHERE_HPP
# define SPHERE_HPP

#include "Surface.hpp"
#include "Ray.hpp"

class Sphere : public Surface
{
public:

	Sphere(Vector3 center, float radius, Vector3 color);

	HitRecord hit(Ray ray, float t0, float t1);

private:

	Vector3 _center {};
	float _radius {};
};

#endif