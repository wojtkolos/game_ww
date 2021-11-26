#pragma once

#define HOUSE_H
#include "Dice.h"

class House
	:public Entity
{
	bool active;

	void initVariables();
	void initComponents(sf::Texture& texture_sheet);
public:
	House(sf::Vector2f coords, sf::Texture& texture_sheet, float rotation);
	virtual ~House();

	bool isActive();
	void setActive(bool state);

};

