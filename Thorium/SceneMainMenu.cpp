#include "SceneMainMenu.h"
#include "SFML\Graphics.hpp"
#include "GameEngine.h"
#include <sstream>

SceneMainMenu::SceneMainMenu(GameEngine* gameEngine)
{
	game = gameEngine;

	if (!fntTitle.loadFromFile("fonts/04B_19__.ttf"))
		game->engineState = game->SHUTDOWN;
	if (!fntDebug.loadFromFile("fonts/Minecraft.ttf"))
		game->engineState = game->SHUTDOWN;

	clkFPS = sf::Clock();

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
	
	(fade > 0) ? fade -= 3 : fade = 0;
}

void SceneMainMenu::render()
{
	game->window->clear();

	// Create background
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(game->window->getSize()));
	background.setFillColor(sf::Color(0, 0, 0, fade));

	// Create a graphical text to display
	sf::Text text("thoriumBREED", fntTitle, 45);
	text.setOrigin(sf::Vector2f(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2));
	text.setPosition(game->window->getSize().x / 2, 50);

	// Draw Framerate
	float Framerate = 1.f / clkFPS.getElapsedTime().asSeconds();
	clkFPS.restart();
	std::ostringstream ss;
	ss << "FPS: " << Framerate;
	sf::Text txtFPS( ss.str(), fntDebug, 10);
	txtFPS.setPosition(2, 2);
	
	// fade in game logo
	game->window->draw(text);
	game->window->draw(background);
	game->window->draw(txtFPS);

	game->window->display();
}