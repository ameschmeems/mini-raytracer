#ifndef AMBIENT_LIGHT_HPP
# define AMBIENT_LIGHT_HPP

#include "Light.hpp"

class AmbientLight : public Light
{
public:

	AmbientLight(const Vector3 &intensity);

	Vector3 illuminate(Ray ray, HitRecord hrec);

private:

	Vector3 _intensity {};
};

#endif