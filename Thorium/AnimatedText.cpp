#include "AnimatedText.h"

AnimatedText::AnimatedText(int x, int y, const char* text, sf::Font* font, unsigned int characterSize, float fadeInTime, float fadeStaticTime = 0, float fadeOutTime = 0, sf::Color textColor, sf::Color fadeColor) :
	fadeInTime(fadeInTime),
	fadeStaticTime(fadeStaticTime),
	fadeOutTime(fadeOutTime),
	text(text),
	font(font),
	textColor(textColor),
	fadeColor(fadeColor),
	x(x), 
	y(y)
{
	currColor = this->textColor;
	txtObj = sf::Text(this->text, *this->font, characterSize);
	setPosition(this->x, this->y);
	txtObj.setPosition(this->getPosition());
	txtObj.setOrigin(txtObj.getGlobalBounds().width / 2, txtObj.getGlobalBounds().height / 2);
	txtObj.setColor(currColor);
	clock.restart();
	doneAnimation = false;
}

AnimatedText::~AnimatedText()
{
}

void AnimatedText::update()
{
	if (!doneAnimation)
	{
		sf::Int32 elapsedTime = clock.getElapsedTime().asMilliseconds();
		if (elapsedTime <= fadeInTime) // Fade In
		{
			currColor.r = fadeColor.r + ((textColor.r - fadeColor.r) * (elapsedTime / fadeInTime));
			currColor.g = fadeColor.g + ((textColor.g - fadeColor.g) * (elapsedTime / fadeInTime));
			currColor.b = fadeColor.b + ((textColor.b - fadeColor.b) * (elapsedTime / fadeInTime));
		}
		else if (elapsedTime > fadeInTime && elapsedTime <= (fadeInTime + fadeStaticTime)) // Fade Static
		{
			currColor = textColor;
		}
		else if (elapsedTime > (fadeInTime + fadeStaticTime) && elapsedTime <= (fadeInTime + fadeStaticTime + fadeOutTime)) // Fade Out
		{
			currColor.r = textColor.r - ((textColor.r - fadeColor.r) * (elapsedTime / fadeOutTime));
			currColor.g = textColor.g - ((textColor.g - fadeColor.g) * (elapsedTime / fadeOutTime));
			currColor.b = textColor.b - ((textColor.b - fadeColor.b) * (elapsedTime / fadeOutTime));
		}
		else
		{
			(fadeOutTime > 0.0f) ? currColor = fadeColor : currColor = textColor;
			doneAnimation = true;
		}

		txtObj.setColor(currColor);
	}
}

void AnimatedText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(txtObj, states);
}

sf::FloatRect AnimatedText::getGlobalBounds() const
{
	return txtObj.getGlobalBounds();
}