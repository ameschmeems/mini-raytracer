#ifndef SCENE_HPP
# define SCENE_HPP

#include "Group.hpp"
#include "Light.hpp"
#include "Image.hpp"

class Scene
{
public:

	Scene(Group &group);

	void add_light(Light &light);
	void raytrace(Image &image);

private:

	Group &_group;
	std::vector<Light &> _lights {};
};

#endif