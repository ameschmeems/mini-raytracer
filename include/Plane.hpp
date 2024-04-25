#ifndef PLANE_HPP
# define PLANE_HPP

#include "Surface.hpp"

class Plane : public Surface
{
public:

	Plane(const Material &material);

	HitRecord hit(Ray ray, float t0, float t1);

private:

	Vector3 _get_surface_normal();
};

#endif