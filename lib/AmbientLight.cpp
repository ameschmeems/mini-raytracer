#include "AmbientLight.hpp"

AmbientLight::AmbientLight(const Vector3 &intensity) : _intensity { intensity }
{
}

Vector3 AmbientLight::illuminate(Ray ray, HitRecord hrec)
{
	return _intensity;
}