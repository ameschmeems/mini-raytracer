#ifndef PLANE_HPP
# define PLANE_HPP

#include "Surface.hpp"

class Plane : public Surface
{
public:

	Plane(const Vector3 &origin, const Vector3 &normal, const Material &material);

	HitRecord hit(Ray ray, float t0, float t1);

private:

	Vector3 _normal {};
	Vector3 _origin {};
};

#endif