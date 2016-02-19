#pragma once
#include "Scene.h"
#include "GameEngine.h"

class SceneMainMenu : public Scene
{
public:
	GameEngine* game;
	sf::Font titleFont;
	int fade;

	SceneMainMenu(GameEngine* gameEngine);
	~SceneMainMenu();
	void update();
	void render();
};

