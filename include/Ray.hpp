#ifndef RAY_HPP
# define RAY_HPP

#include "Vector3.hpp"

class Ray
{
public:

	Ray(const Vector3 &origin, const Vector3 &direction);

	Vector3 evaluate(float t);
	const Vector3 &origin() const;
	const Vector3 &direction() const;

private:

	Vector3 _origin;
	Vector3 _direction;
};

#endif