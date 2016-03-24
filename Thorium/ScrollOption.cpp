#include "ScrollOption.h"
#include <sstream>

ScrollOption::ScrollOption(sf::Vector2f location, sf::Vector2f size, std::string options, sf::Font* font) : location(location), size(size), fntText(font)
{
	background = new sf::RectangleShape(size);
	background->setFillColor(sf::Color::Black);

	currentSelection = 0;

	std::stringstream ss(options);
	std::string mode;
	while (ss >> mode)
		this->options.push_back(std::string(mode));

	displayText = sf::Text(this->options.at(currentSelection), *fntText, 18);
	correctSize();
}

void ScrollOption::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(*background, states);
	target.draw(displayText, states);
}

void ScrollOption::update(sf::Event* event)
{
	sf::Vector2i mousePos = sf::Vector2i(event->mouseButton.x, event->mouseButton.y);
	if (background->getGlobalBounds().contains(mousePos.x, mousePos.y))
			onClick();

	displayText = sf::Text(this->options.at(currentSelection), *fntText, 18);
	correctSize();
}

void ScrollOption::onClick()
{
	(currentSelection < options.size() - 1) ? currentSelection++ : currentSelection = 0;
}

void ScrollOption::correctSize()
{
	background->setSize(sf::Vector2f(displayText.getLocalBounds().width + 10, displayText.getLocalBounds().height + 20));
	background->setOrigin(background->getLocalBounds().width / 2, background->getLocalBounds().height / 2);
	background->setPosition(location.x, location.y + 15);	
	displayText.setOrigin(displayText.getLocalBounds().width / 2, displayText.getLocalBounds().height / 2);
	displayText.setPosition(background->getPosition().x, background->getPosition().y);	
}