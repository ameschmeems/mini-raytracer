#ifndef POINT_LIGHT_HPP
# define POINT_LIGHT_HPP

#include "Light.hpp"

class PointLight : public Light
{
public:

	PointLight(const Vector3 &point, const Vector3 &intensity);

	Vector3 illuminate(Ray ray, HitRecord hrec, Group &group) const;

private:

	Vector3 _point {};
	Vector3 _intensity {};
};

#endif