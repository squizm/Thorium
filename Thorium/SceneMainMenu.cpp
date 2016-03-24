#include "SceneMainMenu.h"
#include "SFML\Graphics.hpp"
#include "GameEngine.h"
#include <sstream>

void btnQuit()
{
	GameEngine::engineState = GAME_STATE_SHUTDOWN;
}

void btnSettings()
{
	GameEngine::activeScene = SCENE_SETTINGS;
}

void btnCampaign()
{
	GameEngine::activeScene = SCENE_CAMPAIGN;
}

SceneMainMenu::SceneMainMenu(GameEngine* gameEngine)
{
	game = gameEngine;

	if (!fntTitle.loadFromFile("fonts/RioGrande.ttf"))
		game->engineState = GAME_STATE_SHUTDOWN;
	if (!fntDebug.loadFromFile("fonts/Anderson Thunderbirds Are GO.ttf"))
		game->engineState = GAME_STATE_SHUTDOWN;
	if (!fntButton.loadFromFile("fonts/Anderson Thunderbirds Are GO.ttf"))
		game->engineState = GAME_STATE_SHUTDOWN;

	clkFPS = sf::Clock();

	txtTitle = AnimatedText(game->window->getSize().x/2, game->window->getSize().y * 0.2, "(sixGUNsound)", &fntTitle, 60, 1000.0f, 1000.0f, 0.0f);

	buttons.push_back(new Button(game->window->getSize().x / 2, game->window->getSize().y / 2, "Campaign", &fntButton, btnCampaign));
	buttons.push_back(new Button(game->window->getSize().x / 2, game->window->getSize().y / 2 + 40, "Settings", &fntButton, btnSettings));
	buttons.push_back(new Button(game->window->getSize().x / 2, game->window->getSize().y / 2 + 80, "Quit", &fntButton, btnQuit));
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
			GameEngine::engineState = GAME_STATE_SHUTDOWN;
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
			GameEngine::engineState = GAME_STATE_SHUTDOWN;
	}
	
	for each (Button* btn in buttons)
	{
		btn->update(game->window);
	}
	
	sf::Time time = clkFPS.restart();
	txtTitle.update();
}

void SceneMainMenu::render()
{
	game->window->clear();
	game->window->draw(txtTitle);

	for each (Button* btn in buttons)
	{
		game->window->draw(*btn);
	}

	// Draw Framerate
	/*
	float Framerate = 1.f / clkFPS.getElapsedTime().asSeconds();
	clkFPS.restart();
	std::ostringstream ss;
	ss << "FPS: " << int(Framerate);
	sf::Text txtFPS( ss.str(), fntDebug, 10);
	txtFPS.setPosition(2, 2);
	game->window->draw(txtFPS);
	*/

	// Display screen
	game->window->display();
}