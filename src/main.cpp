#include <iostream>
#include "Vector3.hpp"
#include "Image.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Group.hpp"
#include "Scene.hpp"
#include "AmbientLight.hpp"
#include "DirectionalLight.hpp"
#include "PointLight.hpp"

constexpr float PI = 3.14;

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
	float fov { PI / 3 };
	float viewport_height { 2 * tanf(fov / 2) * focal_length };
	float viewport_width { viewport_height * aspect_ratio };

	Vector3 viewport_u { viewport_width, 0.0, 0.0 };
	Vector3 viewport_v { 0.0, -viewport_height, 0.0 };
	Vector3 delta_u { viewport_u / image_width };
	Vector3 delta_v { viewport_v / image_height };

	Vector3 sphere_color { 0.8, 0.6, 1.0 };
	Vector3 sphere_ambient { sphere_color };
	Vector3 sphere_specular { sphere_color };
	Vector3 sphere_reflectance { sphere_color };
	Material sphere_material { sphere_color, sphere_specular, sphere_reflectance, 4.0f };

	Sphere sphere { Vector3 { 0.0, 0.0, -4.0 }, 1.0, sphere_material };

	Sphere sphere_2 {Vector3 { -2.5, 0.0, -4.0 }, 1.0, sphere_material};

	Group group {};
	group.add_surface(&sphere);
	group.add_surface(&sphere_2);

	Scene scene { group };

	AmbientLight ambient { Vector3 { 0.1, 0.1, 0.1 } };
	scene.add_light(&ambient);
	PointLight point_light { Vector3 { 0.5, 1.0, -2.9 }, Vector3 { 0.9, 0.9, 0.9 } };
	scene.add_light(&point_light);
	DirectionalLight directional_light { Vector3 { -1.0, 1.0, 0 }, Vector3 { 0.7, 0.7, 0.7 } };
	scene.add_light(&directional_light);

	// Get position for upper left pixel
	Vector3 upper_left { origin - focal_length * w - 0.5 * viewport_u - 0.5 * viewport_v };
	upper_left = upper_left + 0.5 * (delta_u + delta_v);

	for (int j = 0; j < image_height; j++)
	{
		for (int i = 0; i < image_width; i++)
		{
			Vector3 pixel_pos = upper_left + i * delta_u + j * delta_v;
			Vector3 ray_direction { (pixel_pos - origin).normalized() };
			Ray ray { origin, ray_direction };
			image.write_pixel(scene.raytrace(ray, 0.0, std::numeric_limits<float>::infinity()));
		}
	}

	image.write_to_file("test");

	return 0;
}