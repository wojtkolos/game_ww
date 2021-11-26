#include "House.h"

void House::initVariables()
{
	this->active = true;
}

void House::initComponents(sf::Texture& texture_sheet)
{
	this->createMovementComponent(100.f);
}

House::House(sf::Vector2f coords, sf::Texture& texture_sheet, float rotation)
{
	this->initVariables();

	this->createSprite(texture_sheet, sf::Vector2f(0.04f, 0.04f));
	this->setPosition(coords);
	if(rotation != 0)
		this->setRotation(rotation);

	this->initComponents(texture_sheet);
}

House::~House()
{
}

bool House::isActive()
{
	return this->active;
}

void House::setActive(bool state)
{
	this->active = state;
}
