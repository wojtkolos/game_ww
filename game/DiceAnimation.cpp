#include "DiceAnimation.h"


//Init components
void DiceAnimation::initVariables()
{
	this->currentImage.x = 0;
	this->totalTime = 0.0f;
}


//Constructors / Destructors
DiceAnimation::DiceAnimation(sf::RectangleShape* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;

	this->initVariables();

	this->uvRect.width = texture->getSize().x / float(imageCount.x);
	this->uvRect.height = texture->getSize().y / (float(imageCount.y));
}


void DiceAnimation::update(const float& dt)
{
	currentImage.y = 5;

	totalTime += dt;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}

void DiceAnimation::setFrame(unsigned short pos, const float& dt)
{
	currentImage.y = 5;
	currentImage.x = pos - 1;

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}