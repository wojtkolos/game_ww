#pragma once

#define CARD_H
#include <string>
#include "Bank.h"
#include "Player.h"

class Card
	: public Entity
{

private:
	string name;

public:
	void initComponents();

	Card(sf::Vector2f pos, float rotation, sf::Texture& texture_sheet, std::string name);

	string getCardName();

	virtual void setAmount(int num) = 0;
	virtual void setCardText(string text1) = 0;
	virtual void cardAction(Bank* bank1, Player* player1) = 0;
	virtual string getCardText(int num) = 0;
	virtual int getAmmount() = 0;
};