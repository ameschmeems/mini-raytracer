#ifndef GROUP_HPP
# define GROUP_HPP

#include <vector>
#include "Surface.hpp"
#include "HitRecord.hpp"
#include "Ray.hpp"

class Group : public Surface
{
public:

	HitRecord hit(Ray ray, float t0, float t1);
	void add_surface(Surface &surface);

private:

	std::vector<Surface&> _surfaces {};
};

#endif