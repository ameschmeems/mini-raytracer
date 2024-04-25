#ifndef MATERIAL_HPP
# define MATERIAL_HPP

#include "Vector3.hpp"

class Material
{
public:

	Material() = default;
	Material(const Vector3 &ambient, const Vector3 &specular, const Vector3 &reflectance, float phong_exponent);

	Vector3 evaluate(const Vector3 &light_direction, const Vector3 &viewing_direction, const Vector3 &normal) const;

	Vector3 ambient {};

private:

	Vector3 _specular {};
	Vector3 _reflectance {};
	float _phong_exponent {};
};

#endif