#include "CirclePointers.h"

void CirclePointers::initVariables(unsigned short totalPlayers)
{
	this->totalPlayers = totalPlayers;
	this->red = sf::Color(250, 50, 50);
	this->green = sf::Color(100, 250, 50);
}

void CirclePointers::initCirclePointers(unsigned short totalPlayers)
{
		this->playerTurnPointers["PLAYER1"] = new sf::CircleShape(10);
		this->playerTurnPointers["PLAYER2"] = new sf::CircleShape(10);
		this->playerTurnPointers["PLAYER3"] = new sf::CircleShape(10);
		this->playerTurnPointers["PLAYER4"] = new sf::CircleShape(10);

		this->playerTurnPointers["PLAYER1"]->setFillColor(this->green);
		this->playerTurnPointers["PLAYER2"]->setFillColor(this->red);
		this->playerTurnPointers["PLAYER3"]->setFillColor(this->red);
		this->playerTurnPointers["PLAYER4"]->setFillColor(this->red);

		this->playerTurnPointers["PLAYER1"]->setPosition(1155, 216);
		this->playerTurnPointers["PLAYER2"]->setPosition(1155, 256);
		this->playerTurnPointers["PLAYER3"]->setPosition(1155, 296);
		this->playerTurnPointers["PLAYER4"]->setPosition(1155, 336);
}

CirclePointers::CirclePointers(unsigned short totalPlayers)
{
	this->initVariables(totalPlayers);
	this->initCirclePointers(totalPlayers);
}

CirclePointers::~CirclePointers()
{
	
}

void CirclePointers::update(int player_turn)
{
	int i = 0;
	for (auto& it : this->playerTurnPointers)
	{
		if (i == player_turn)
			it.second->setFillColor(this->green);
		else
			it.second->setFillColor(this->red);
		i++;
	}
}

void CirclePointers::render(sf::RenderTarget* target)
{
	for (auto& it : this->playerTurnPointers)
	{
		target->draw(*it.second);
	}
}