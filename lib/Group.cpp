#include "Group.hpp"

HitRecord Group::hit(Ray ray, float t0, float t1)
{
	HitRecord closest_hit {};

	for (auto s : _surfaces)
	{
		HitRecord rec { s.hit(ray, t0, t1) };
		if (rec.t < std::numeric_limits<float>::infinity())
		{
			closest_hit = rec;
			t1 = rec.t;
		}
	}
	return closest_hit;
}

void Group::add_surface(Surface &surface)
{
	_surfaces.push_back(surface);
}