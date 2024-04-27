#include "PointLight.hpp"
#include "Surface.hpp"

constexpr float EPSILON = 0.001;

PointLight::PointLight(const Vector3 &point, const Vector3 &intensity)
	: _point { point }, _intensity { intensity }
{
}

Vector3 PointLight::illuminate(Ray ray, HitRecord hrec, Group &group) const
{
	Vector3 light_direction { (_point - ray.evaluate(hrec.t)).normalized() };
	float distance { (_point - ray.evaluate(hrec.t)).length() };
	HitRecord shadow_rec { group.hit(Ray { ray.evaluate(hrec.t), light_direction }, EPSILON, distance) };
	if (shadow_rec.t < std::numeric_limits<float>::infinity())
		return Vector3 {};

	Vector3 irradiance { (std::max(0.0f, hrec.normal.dot(light_direction)) * _intensity) / powf(distance, 2.0) };

	return irradiance * hrec.surface->material.evaluate(light_direction, ray.direction(), hrec.normal);
}