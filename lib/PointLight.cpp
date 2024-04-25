#include "PointLight.hpp"
#include "Surface.hpp"

PointLight::PointLight(const Vector3 &point, const Vector3 &intensity)
	: _point { point }, _intensity { intensity }
{
}

Vector3 PointLight::illuminate(Ray ray, HitRecord hrec) const
{
	float distance { (_point - ray.evaluate(hrec.t)).length() };
	Vector3 light_direction { (_point - ray.evaluate(hrec.t)).normalized() };

	Vector3 irradiance { (std::max(0.0f, hrec.normal.dot(light_direction)) * _intensity) / powf(distance, 2.0) };

	return irradiance * hrec.surface->material.evaluate(light_direction, ray.direction(), hrec.normal);
}