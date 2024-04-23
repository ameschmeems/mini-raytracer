#include "Scene.hpp"

Scene::Scene(Group &group) : _group { group }
{
}

void Scene::add_light(Light &light)
{
	_lights.push_back(light);
}

void Scene::raytrace(Image &image)
{
	// TODO
}