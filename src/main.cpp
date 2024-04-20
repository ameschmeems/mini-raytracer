#include <iostream>
#include "Vector3.hpp"
#include "Image.hpp"

int main()
{
	std::cout << "Hello" << std::endl;

	int width { 256 };
	int height { 256 };

	Image image { width, height };

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			Vector3 color { static_cast<float>(i) / (width - 1), static_cast<float>(j) * (height - 1), 0.0 };
			image.write_pixel(color);
		}
	}

	image.write_to_file("test");

	return 0;
}