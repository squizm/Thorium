#include "GameEngine.h"
#include "SceneMainMenu.h"

GameEngine::GameEngine(int width, int height, std::string title): width(width), height(height)
{
	// Create the main window
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	window->setFramerateLimit(60);
	engineState = ENGINE_STATE::RUNNING;

	sceneList.push_back(new SceneMainMenu(this));
	activeScene = 0;
}

GameEngine::~GameEngine()
{
	delete window;
}

void GameEngine::update()
{
	sceneList.at(activeScene)->update();
}

void GameEngine::render()
{
	// Draw active screne
	sceneList.at(activeScene)->render();
}