#pragma once
#include "SFML\Graphics.hpp"
#include "Scene.h"

#define GAME_STATE_RUNNING	0
#define GAME_STATE_SHUTDOWN	1

#define SCENE_COUNT		3
#define SCENE_MAINMENU	0
#define SCENE_CAMPAIGN	1
#define SCENE_SETTINGS	2

class GameEngine
{
public:
	int width, height;
	Scene* sceneList[SCENE_COUNT];
	sf::RenderWindow* window;
	static int engineState;
	static int activeScene;

	GameEngine(int width, int size, std::string title);
	~GameEngine();
	void update();
	void render();
};