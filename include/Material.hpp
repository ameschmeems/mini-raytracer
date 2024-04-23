#ifndef MATERIAL_HPP
# define MATERIAL_HPP

#include "Vector3.hpp"

class Material
{
public:

	Material(Vector3 specular, float reflectance, float phong_exponent);

	Vector3 evaluate(Vector3 light_direction, Vector3 viewing_direction, Vector3 normal) const;

private:

	Vector3 _specular {};
	float _reflectance {};
	float _phong_exponent {};
};

#endif