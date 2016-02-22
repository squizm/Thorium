#pragma once
#include "SFML\Graphics.hpp"

class AnimatedText : public sf::Text
{
private:
	sf::Text textObj;
public:
	float fadeInTime;
	float fadeStaticTime;
	float fadeOutTime;
	int fade;
	sf::Color fadeColor;

	AnimatedText(std::string &text, sf::Font &font, float fadeInTime, float fadeStaticTime, float fadeOutTime);
	~AnimatedText();

	void update(float delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

