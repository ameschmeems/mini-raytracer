#ifndef DIRECTIONAL_LIGHT_HPP
# define DIRECTIONAL_LIGHT_HPP

#include "Light.hpp"

class DirectionalLight : public Light
{
public:

	DirectionalLight(const Vector3 &direction, const Vector3 &normal_irradiance);

	Vector3 illuminate(Ray ray, HitRecord hrec);

private:

	Vector3 _direction {};
	Vector3 _normal_irradiance {};
};

#endif