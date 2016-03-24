#pragma once
#include "SFML\Graphics.hpp"
#include "GameEngine.h"

class Button : public sf::Drawable, public sf::Transformable
{
private:
	int width, height;
	void (*onclick)(void);
	sf::Text label;
	sf::RectangleShape* btnShape;
	sf::Color hoverColor, color, textColor;
	bool isMouseOver;
public:
	Button(int x, int y, char* text, sf::Font* font, void(*onclick)(void), sf::Color buttonColor = sf::Color::Black, sf::Color hoverColor = sf::Color::Blue , sf::Color textColor = sf::Color::White);
	~Button();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Window* window);
};