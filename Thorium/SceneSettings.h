#pragma once
#include "Scene.h"
#include "GameEngine.h"
#include "ScrollOption.h"

class SceneSettings :
	public Scene
{
private:
	GameEngine* game;
	ScrollOption* videoMode;
	sf::Font fntDefault;
public:
	SceneSettings(GameEngine* gameEngine);
	SceneSettings() {};
	void update();
	void render();
};

