#include "HitRecord.hpp"

HitRecord::HitRecord(const HitRecord &rhs) : surface { rhs.surface }, t { rhs.t }, normal { rhs.normal }
{
}

HitRecord &HitRecord::operator=(const HitRecord &rhs)
{
	surface = rhs.surface;
	t = rhs.t;
	normal = rhs.normal;
	return *this;
}