#include "SceneMainMenu.h"
#include "SFML\Graphics.hpp"
#include "GameEngine.h"

SceneMainMenu::SceneMainMenu(GameEngine* gameEngine)
{
	game = gameEngine;

	if (!titleFont.loadFromFile("fonts/04B_19__.ttf"))
		game->engineState = game->SHUTDOWN;

	fade = 255;
}

SceneMainMenu::~SceneMainMenu()
{
	delete game;
}

void SceneMainMenu::update()
{
	sf::Event event;
	while (game->window->pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed)
			game->engineState = GameEngine::ENGINE_STATE::SHUTDOWN;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			game->engineState = GameEngine::ENGINE_STATE::SHUTDOWN;
	}

	(fade > 0) ? --fade : fade = 0;
}

void SceneMainMenu::render()
{
	game->window->clear();

	// Create background
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(game->window->getSize()));
	background.setFillColor(sf::Color(0, 0, 0, fade));


	// Create a graphical text to display
	sf::Text text("thoriumBREED", titleFont, 45);
	text.setOrigin(sf::Vector2f(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2));
	text.setPosition(game->window->getSize().x / 2, 50);
	
	game->window->draw(text);	
	game->window->draw(background);

	game->window->display();
}