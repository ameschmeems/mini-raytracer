#include "DirectionalLight.hpp"
#include "Surface.hpp"

DirectionalLight::DirectionalLight(const Vector3 &direction, const Vector3 &normal_irradiance)
	: _direction { direction }, _normal_irradiance { normal_irradiance }
{
}

Vector3 DirectionalLight::illuminate(Ray ray, HitRecord hrec) const
{
	Vector3 irradiance { std::max(0.0f, hrec.normal.dot(_direction.normalized())) * _normal_irradiance };
	
	return irradiance * hrec.surface->material.evaluate(_direction.normalized(), ray.direction(), hrec.normal);
}