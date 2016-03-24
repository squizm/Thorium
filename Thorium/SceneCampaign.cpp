#include "SceneCampaign.h"

SceneCampaign::SceneCampaign()
{
}

SceneCampaign::SceneCampaign(GameEngine* gameEngine)
{
	game = gameEngine;
	map = new Map();
	map->setPosition(5.0f, 5.0f);
}

SceneCampaign::~SceneCampaign()
{
	delete game;
}

void SceneCampaign::update()
{
	sf::Event event;
	while (game->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			GameEngine::engineState = GAME_STATE_SHUTDOWN;
		else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
			GameEngine::activeScene = SCENE_MAINMENU;
		else if (event.type == sf::Event::MouseButtonReleased)
			if(event.mouseButton.button == sf::Mouse::Left)
				map->generateMap(TERRAIN_TYPE_WOS);
	}
}

void SceneCampaign::render()
{
	game->window->clear();
	game->window->draw(*map);
	game->window->display();
}
