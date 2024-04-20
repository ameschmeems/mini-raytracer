#include "Image.hpp"
#include <fstream>
#include <string>

Image::Image(const Image &rhs) : _bytes { rhs._bytes }, _width { rhs._width }, _height { rhs._height }
{
}

Image::Image(Image &&rhs) noexcept : _bytes { std::move(rhs._bytes) }, _width { rhs._width }, _height { rhs._height }
{
}

Image::Image(int width, int height) : _bytes {}, _width { width }, _height { height }
{
	_bytes += "P3\n";
	_bytes += std::to_string(_width);
	_bytes += " ";
	_bytes += std::to_string(_height);
	_bytes += "\n255\n";
}

void Image::write_pixel(const Vector3 &color)
{
	int r = static_cast<int>(255 * color.x());
	int g = static_cast<int>(255 * color.y());
	int b = static_cast<int>(255 * color.z());

	_bytes += std::to_string(r);
	_bytes += " ";
	_bytes += std::to_string(g);
	_bytes += " ";
	_bytes += std::to_string(b);
	_bytes += "\n";
}

void Image::write_to_file(std::string name) const
{
	std::ofstream os { name + ".ppm" };
	os << _bytes;
	os.close();
}