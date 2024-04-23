#include "DirectionalLight.hpp"

DirectionalLight::DirectionalLight(const Vector3 &direction, const Vector3 &normal_irradiance)
	: _direction { direction }, _normal_irradiance { normal_irradiance }
{
}

Vector3 DirectionalLight::illuminate(Ray ray, HitRecord hrec)
{
	return std::max(0.0f, hrec.normal.dot(_direction)) * _normal_irradiance;
}