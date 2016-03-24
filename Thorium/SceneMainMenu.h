#pragma once
#include <vector>
#include "Scene.h"
#include "GameEngine.h"
#include "AnimatedText.h"
#include "Button.h"

class SceneMainMenu : public Scene
{
private:
	GameEngine* game;
	sf::Font fntTitle, fntDebug, fntButton;
	sf::Clock clkFPS;
	AnimatedText txtTitle;
	std::vector<Button*> buttons;
public:
	SceneMainMenu(GameEngine* gameEngine);
	~SceneMainMenu();
	void update();
	void render();
};