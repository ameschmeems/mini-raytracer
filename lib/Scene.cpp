#include "Scene.hpp"

constexpr float EPSILON = 0.001;

Scene::Scene(Group &group) : _group { group }
{
}

void Scene::add_light(Light *light)
{
	_lights.push_back(light);
}

Vector3 Scene::raytrace(Ray ray, float t0, float t1, int recursive_depth)
{
	HitRecord hrec { _group.hit(ray, t0, t1) };
	if (hrec.t < std::numeric_limits<float>::infinity())
	{
		Vector3 color {};
		for (auto light : _lights)
			color = color + light->illuminate(ray, hrec);
		if (hrec.surface->material.mirror.length() != 0 && recursive_depth > 0)
		{
			Vector3 reflected_dir { ray.direction() - 2 * (ray.direction().dot(hrec.normal) * hrec.normal) };
			Ray reflection_ray { ray.evaluate(hrec.t), reflected_dir };
			color = color + this->raytrace(reflection_ray, EPSILON, std::numeric_limits<float>::infinity(), recursive_depth - 1);
		}
		return color;
	}
	else
		return Vector3 { 0, 0, 0 };
}