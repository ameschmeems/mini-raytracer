#ifndef SURFACE_HPP
# define SURFACE_HPP

#include "HitRecord.hpp"
#include "Ray.hpp"
#include "Material.hpp"

class Surface
{
public:

	Surface() = default;
	Surface(const Material &material);

	virtual HitRecord hit(Ray ray, float t0, float t1) = 0;

	Material material {};
};

#endif