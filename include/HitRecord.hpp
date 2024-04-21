#ifndef HIT_RECORD_HPP
# define HIT_RECORD_HPP

#include <limits>
#include "Vector3.hpp"

class Surface;

class HitRecord
{
public:

	HitRecord() = default;
	HitRecord(const HitRecord &rhs);

	HitRecord &operator=(const HitRecord &rhs);

	Surface *surface {}; // Surface that was hit
	float t { std::numeric_limits<float>::infinity() }; // where along the ray the hit happens
	Vector3 normal {}; // surface normal

};

#endif