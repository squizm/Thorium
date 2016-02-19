#pragma once
#include "SFML\Graphics.hpp"
#include "Scene.h"
#include <vector>

class GameEngine
{
public:

	enum ENGINE_STATE
	{
		RUNNING = 0x01,
		SHUTDOWN = 0x02,
	};

	int width, height;
	int activeScene;
	std::vector<Scene*> sceneList;
	sf::RenderWindow* window;
	ENGINE_STATE engineState;

	GameEngine(int width, int size, std::string title);
	~GameEngine();
	void update();
	void render();
};

