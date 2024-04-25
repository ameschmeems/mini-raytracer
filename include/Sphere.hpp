#ifndef SPHERE_HPP
# define SPHERE_HPP

#include "Surface.hpp"
#include "Ray.hpp"

class Sphere : public Surface
{
public:

	Sphere(const Vector3 &center, float radius, const Material &material);

	HitRecord hit(Ray ray, float t0, float t1);

private:

	Vector3 _get_surface_normal(const Vector3 &p);

	Vector3 _center {};
	float _radius {};
};

#endif