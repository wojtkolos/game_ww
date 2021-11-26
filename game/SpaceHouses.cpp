#include "SpaceHouses.h"


SpaceHouses::SpaceHouses(sf::Texture& house, sf::Texture& hotel, sf::Vector2f house1, 
	sf::Vector2f house2, sf::Vector2f house3, float rotation)
{
	this->houses.push_back(new House(house1, house, rotation));
	this->houses.push_back(new House(house2, house, rotation));
	this->houses.push_back(new House(house3, house, rotation));
	this->houses.push_back(new House(house2, hotel, rotation));
}

SpaceHouses::~SpaceHouses()
{
	for (auto& house : this->houses)
		delete house;
}

bool SpaceHouses::isHouseActive(short a)
{
	return this->houses[a]->isActive();
}

void SpaceHouses::setHouseActive(short a, bool state)
{
	this->houses[a]->setActive(state);
}

void SpaceHouses::update(const float& dt, sf::Vector2f mousePosView)
{
	for (auto& house : this->houses)
		if (house->isActive())
			house->update(dt, mousePosView);
}

void SpaceHouses::render(sf::RenderTarget* target)
{
	for (auto& house : this->houses)
		if(house->isActive())
			house->render(target);
}


