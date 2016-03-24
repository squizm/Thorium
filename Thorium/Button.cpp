#include "Button.h"

Button::Button(int x, int y, char* text, sf::Font* font, void(*onclick)(void), sf::Color buttonColor, sf::Color hoverColor, sf::Color textColor) :
	hoverColor(hoverColor),
	color(buttonColor),
	textColor(textColor),
	onclick(onclick)
{	
	label = sf::Text(text, *font, 24);
	width = label.getGlobalBounds().width + 15;
	height = label.getGlobalBounds().height + 15;
	label.setColor(textColor);
	label.setOrigin(label.getLocalBounds().width / 2, label.getLocalBounds().height / 2);
	label.setPosition(x, y);
	isMouseOver = false;
	btnShape = new sf::RectangleShape(sf::Vector2f(width, height));
	btnShape->setOrigin(width / 2, height / 2);
	btnShape->setPosition(sf::Vector2f(label.getPosition().x, label.getPosition().y));
}

Button::~Button(){}

void Button::update(sf::Window* window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	if (btnShape->getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		isMouseOver = true;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			onclick();
	}
	else
		isMouseOver = false;		
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	isMouseOver ? btnShape->setFillColor(hoverColor) : btnShape->setFillColor(color);
	target.draw(*btnShape);
	target.draw(label);
}