#include "SceneSettings.h"
#include <vector>
#include <sstream>

SceneSettings::SceneSettings(GameEngine* gameEngine)
{
	game = gameEngine;
	
	if (!fntDefault.loadFromFile("fonts/Minecraft.ttf"))
		game->engineState = GAME_STATE_SHUTDOWN;

	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	std::ostringstream ss;
	for (std::vector<sf::VideoMode>::iterator iter = modes.begin(); iter != modes.end(); ++iter)
	{
		ss << iter->width << 'x' << iter->height << ' ';
	}

	videoMode = new ScrollOption(sf::Vector2f(game->window->getSize().x/2, game->window->getSize().y / 2), sf::Vector2f(200, 30), std::string(ss.str()), &fntDefault);
}

void SceneSettings::update()
{
	sf::Event event;
	while (game->window->pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed)
			GameEngine::engineState = GAME_STATE_SHUTDOWN;
		if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
			game->activeScene = SCENE_MAINMENU;
		if(event.type == sf::Event::MouseButtonReleased)
			videoMode->update(&event);
	}
}

void SceneSettings::render()
{
	// Clear render target
	game->window->clear(sf::Color(30,30,30));

	game->window->draw(*videoMode);
	// Display screen
	game->window->display();
}
