#include "Plane.hpp"

Plane::Plane(const Vector3 &origin, const Vector3 &normal, const Material &material) 
	: _origin { origin }, _normal { normal }, Surface { material }
{
}

HitRecord Plane::hit(Ray ray, float t0, float t1)
{
	HitRecord hrec {};
	float t { ((_origin - ray.origin()).dot(_normal)) / (ray.direction().dot(_normal)) };
	if (t >= t0 && t <= t1)
	{
		hrec.t = t;
		hrec.normal = _normal;
		hrec.surface = this;
	}
	return hrec;
}