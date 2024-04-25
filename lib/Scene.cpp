#include "Scene.hpp"

Scene::Scene(Group &group) : _group { group }
{
}

void Scene::add_light(Light *light)
{
	_lights.push_back(light);
}

Vector3 Scene::raytrace(Ray ray, float t0, float t1)
{
	HitRecord hrec { _group.hit(ray, t0, t1) };
	if (hrec.t < std::numeric_limits<float>::infinity())
	{
		Vector3 color {};
		for (auto light : _lights)
			color = color + light->illuminate(ray, hrec);
		return color;
	}
	else
		return Vector3 { 0.67, 0.84, 0.9 };
}