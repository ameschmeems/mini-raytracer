#include "AmbientLight.hpp"
#include "Surface.hpp"

AmbientLight::AmbientLight(const Vector3 &intensity) : _intensity { intensity }
{
}

Vector3 AmbientLight::illuminate(Ray ray, HitRecord hrec) const
{
	return _intensity * hrec.surface->material.ambient;
}