#pragma once
#include "Scene.h"
#include "GameEngine.h"

class SceneMainMenu : public Scene
{
public:
	GameEngine* game;
	sf::Font fntTitle;
	sf::Font fntDebug;
	sf::Clock clkFPS;
	int fade;

	SceneMainMenu(GameEngine* gameEngine);
	~SceneMainMenu();
	void update();
	void render();
};

