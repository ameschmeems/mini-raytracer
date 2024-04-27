#include "Sphere.hpp"

Sphere::Sphere(const Vector3 &center, float radius, const Material &material) : _center { center }, _radius { radius }, Surface { material }
{
}

HitRecord Sphere::hit(Ray ray, float t0, float t1)
{
	// Solve the quadratic equation for t
	float a { ray.direction().dot(ray.direction()) };
	float b { 2 * ray.direction().dot((ray.origin() - _center)) };
	float c { (ray.origin() - _center).dot(ray.origin() - _center) - _radius * _radius };
	float discriminant { b * b - 4 * a * c };
	// no existing solutions
	if (discriminant < 0)
		return HitRecord {};
	
	float t_first { (-b + sqrtf(discriminant)) / (2.0f * a) };
	float t_second { (-b - sqrtf(discriminant)) / (2.0f * a) };

	float smaller { t_first < t_second ? t_first : t_second };
	float bigger { t_first < t_second ? t_second : t_first };

	HitRecord rec {};

	if (smaller > t0 && smaller < t1)
	{
		rec.surface = this;
		rec.t = smaller;
		rec.normal = _get_surface_normal(ray.evaluate(rec.t)).normalized();
	}
	else if (bigger > t0 && bigger < t1)
	{
		rec.surface = this;
		rec.t = bigger;
		rec.normal = _get_surface_normal(ray.evaluate(rec.t)).normalized();
	}
	return rec;
}

Vector3 Sphere::_get_surface_normal(const Vector3 &p)
{
	return (p - _center) / _radius;
}