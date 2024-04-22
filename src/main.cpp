#include <iostream>
#include "Vector3.hpp"
#include "Image.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"

const float PI = 3.14;

int main()
{
	int image_width { 1280 };
	int image_height { 720 };
	Image image { image_width, image_height };
	
	// Define orthonormal basis
	Vector3 u { 1.0, 0.0, 0.0 };
	Vector3 v { 0.0, 1.0, 0.0 };
	Vector3 w { 0.0, 0.0, 1.0 };

	// Camera position
	Vector3 origin { 0.0, 0.0, 0.0 };

	// Define the image plane
	float focal_length { 1.0 };
	float aspect_ratio { static_cast<float>(image_width) / image_height };
	float fov { PI / 2 };
	float viewport_height { 2 * tanf(fov / 2) * focal_length };
	float viewport_width { viewport_height * aspect_ratio };

	Vector3 viewport_u { viewport_width, 0.0, 0.0 };
	Vector3 viewport_v { 0.0, -viewport_height, 0.0 };
	Vector3 delta_u { viewport_u / image_width };
	Vector3 delta_v { viewport_v / image_height };

	Sphere sphere { Vector3 { 0.0, 3.0, -4.0 }, 1.0, Vector3 { 0.5, 0.0, 0.5 } };

	// Get position for upper left pixel
	Vector3 upper_left { origin - focal_length * w - 0.5 * viewport_u - 0.5 * viewport_v };
	upper_left = upper_left + 0.5 * (delta_u + delta_v);

	for (int j = 0; j < image_height; j++)
	{
		for (int i = 0; i < image_width; i++)
		{
			Vector3 pixel_pos = upper_left + i * delta_u + j * delta_v;
			Vector3 ray_direction { pixel_pos - origin };
			Ray ray { origin, ray_direction };
			HitRecord hrec { sphere.hit(ray, 0.0, 60.0) };
			if (hrec.t < std::numeric_limits<float>::infinity())
				image.write_pixel(hrec.surface->color());
			else
				image.write_pixel(Vector3 {});
		}
	}

	image.write_to_file("test");

	return 0;
}