#include "Ray.hpp"

Ray::Ray(const Vector3 &origin, const Vector3 &direction) : _origin { origin }, _direction { direction }
{
}

Vector3 Ray::evaluate(float t)
{
	return _origin + t * _direction;
}

const Vector3 &Ray::origin() const
{
	return _origin;
}

const Vector3 &Ray::direction() const
{
	return _direction;
}