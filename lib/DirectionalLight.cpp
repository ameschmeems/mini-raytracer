#include "DirectionalLight.hpp"
#include "Surface.hpp"

constexpr float EPSILION = 0.001;

DirectionalLight::DirectionalLight(const Vector3 &direction, const Vector3 &normal_irradiance)
	: _direction { direction }, _normal_irradiance { normal_irradiance }
{
}

Vector3 DirectionalLight::illuminate(Ray ray, HitRecord hrec, Group &group) const
{
	HitRecord shadow_rec { group.hit(Ray { ray.evaluate(hrec.t), _direction }, EPSILION, std::numeric_limits<float>::infinity()) };
	if (shadow_rec.t < std::numeric_limits<float>::infinity())
		return Vector3 {};
	Vector3 irradiance { std::max(0.0f, hrec.normal.dot(_direction.normalized())) * _normal_irradiance };
	
	return irradiance * hrec.surface->material.evaluate(_direction.normalized(), ray.direction(), hrec.normal);
}