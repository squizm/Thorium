#pragma once
#include "SFML\Graphics.hpp"

class Scene
{
public:
	Scene() {};
	~Scene() {};
	virtual void update() {};
	virtual void render() {};
};
