#ifndef IMAGE_HPP
# define IMAGE_HPP

#include "Vector3.hpp"

class Image
{
public:

	Image(const Image &rhs);
	Image(Image &&rhs) noexcept;
	Image(int width, int height);

	void write_pixel(const Vector3 &color);
	void write_to_file(std::string name) const;

private:

	std::string _bytes {};
	int _width {};
	int _height {};
};

#endif