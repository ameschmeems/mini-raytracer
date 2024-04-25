#include "Plane.hpp"

Plane::Plane(const Material &material) : Surface { material }
{
}

HitRecord Plane::hit(Ray ray, float t0, float t1)
{
	return HitRecord {};
}