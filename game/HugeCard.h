#pragma once
#include "Card.h"

#define HUGE_CARD_H

class HugeCard
	: public Card
{	
public:
	HugeCard(sf::Vector2f pos, float rotation, sf::Texture& texture_sheet);

	void setAmount(int num);
	void setCardText(string text1);
	void cardAction(Bank* bank1, Player* player1);
	string getCardText(int num);
	int getAmmount();
	void update(const float& dt, const sf::Vector2f mousePos);

};