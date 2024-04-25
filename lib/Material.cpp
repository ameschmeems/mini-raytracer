#include "Material.hpp"

constexpr float PI = 3.14;

Material::Material(const Vector3 &ambient, const Vector3 &specular, const Vector3 &reflectance, float phong_exponent, const Vector3 &mirror)
	: ambient { ambient }, _specular { specular }, _reflectance { reflectance }, _phong_exponent { phong_exponent }, mirror { mirror }
{
}

Vector3 Material::evaluate(const Vector3 &light_direction, const Vector3 &viewing_direction, const Vector3 &normal) const
{
	Vector3 diffuse { _reflectance / PI };
	Vector3 half { (light_direction + viewing_direction).normalized() };
	Vector3 specular { _specular * powf(std::max(0.0f, normal.dot(half)), _phong_exponent) };
	return diffuse + specular;
}