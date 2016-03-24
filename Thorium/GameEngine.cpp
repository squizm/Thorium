#include "GameEngine.h"
#include "SceneMainMenu.h"
#include "SceneSettings.h"
#include "SceneCampaign.h"

int GameEngine::engineState = GAME_STATE_RUNNING;
int GameEngine::activeScene = SCENE_MAINMENU;

GameEngine::GameEngine(int width, int height, std::string title): width(width), height(height), window(window)
{
	// Create the main window
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	window->setVerticalSyncEnabled(true);

	sceneList[0] = new SceneMainMenu(this);
	sceneList[1] = new SceneCampaign(this);
	sceneList[2] = new SceneSettings(this);
	activeScene = SCENE_MAINMENU;
}

GameEngine::~GameEngine()
{
	delete window;
}

void GameEngine::update()
{
	sceneList[activeScene]->update();
}

void GameEngine::render()
{
	sceneList[activeScene]->render();
}