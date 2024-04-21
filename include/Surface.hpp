#ifndef SURFACE_HPP
# define SURFACE_HPP

#include "HitRecord.hpp"
#include "Ray.hpp"

class Surface
{
public:

	Surface(const Vector3 &color);

	virtual HitRecord hit(Ray ray, float t0, float t1) = 0;
	const Vector3 &color() const;

private:

	Vector3 _color {};
};

#endif