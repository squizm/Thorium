#pragma once
#include "SFML\Graphics.hpp"

class AnimatedText : public sf::Drawable, public sf::Transformable
{
private:
	int x, y;
	float fadeInTime, fadeStaticTime, fadeOutTime;
	sf::Clock clock;
	sf::Color textColor, fadeColor, currColor;
	sf::Text txtObj;
	std::string text;
	sf::Font* font;
	bool doneAnimation;
public:
	AnimatedText() {};
	AnimatedText(int x, int y, const char* text, sf::Font* font, unsigned int characterSize, float fadeInTime, float fadeStaticTime, float fadeOutTime, sf::Color textColor = sf::Color::White, sf::Color fadeColor = sf::Color::Black);
	~AnimatedText();

	void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getGlobalBounds() const;
};

