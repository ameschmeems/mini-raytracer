#ifndef LIGHT_HPP
# define LIGHT_HPP

#include "Vector3.hpp"
#include "Ray.hpp"
#include "HitRecord.hpp"
#include "Group.hpp"

class Light
{
public:

	virtual Vector3 illuminate(Ray ray, HitRecord hrec, Group &group) const = 0;
};

#endif