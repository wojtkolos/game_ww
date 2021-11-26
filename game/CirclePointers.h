#pragma once

#define CIRCLEPOINTERS_H
#include "TradeComponent.h"


class CirclePointers
{
	sf::Color red;
	sf::Color green;

	unsigned short totalPlayers;
	std::map<std::string, sf::CircleShape*> playerTurnPointers;
public:
	CirclePointers(unsigned short totalPlayers);
	virtual ~CirclePointers();
	
	void initVariables(unsigned short totalPlayers);
	void initCirclePointers(unsigned short totalPlayers);


	void update(int player_turn);
	void render(sf::RenderTarget* target);
};