#include "Card.h"


void Card::initComponents()
{
	this->createMovementComponent(1000.f);
}


Card::Card(sf::Vector2f pos, float rotation, sf::Texture& texture_sheet, std::string name) 
{
	this->name = name;

	this->createSprite(texture_sheet, sf::Vector2f(0.6f, 0.6f));
	this->setPosition(pos);
	this->setRotation(rotation);
	this->initComponents();
}


string Card::getCardName()
{
	return this->name;
}
