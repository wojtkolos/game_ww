#pragma once

#define SPACEHOUSES
#include "House.h"

class SpaceHouses
{
	std::vector<House*> houses;
public:
	SpaceHouses(sf::Texture& house, sf::Texture& hotel, sf::Vector2f house1, 
		sf::Vector2f house2, sf::Vector2f house3, float rotation);
	virtual ~SpaceHouses();

	bool isHouseActive(short a);
	void setHouseActive(short a, bool state);

	void update(const float& dt, sf::Vector2f mousePosView);
	void render(sf::RenderTarget* target);

};

