#pragma once

#define COORDINATES_H
#include "CardDeck.h"


class Coorinates
{
public:
	sf::Vector2f x, y;
	Coorinates(sf::Vector2f x, sf::Vector2f y) {
		this->x = x;
		this->y = y;
	}
};