#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

class ScrollOption :public sf::Drawable, public sf::Transformable
{
private:
	sf::RectangleShape* background;
	sf::Text displayText;
	sf::Font* fntText;
	int currentSelection;
	void correctSize();
public:
	sf::Vector2f location;
	sf::Vector2f size;
	std::vector<std::string> options;
	ScrollOption(sf::Vector2f location, sf::Vector2f size, std::string options, sf::Font* font);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Event* event);
	void onClick();
};