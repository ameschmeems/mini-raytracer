#include "Surface.hpp"

Surface::Surface(const Vector3 &color) : _color { color }
{
}

const Vector3 &Surface::color() const
{
	return _color;
}