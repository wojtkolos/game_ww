#pragma once
#define COMMUNITY_CARD_H

#include "ChanceCard.h"

class CommunityCard 
	: public Card 
{

private:
	string cardText;
	int ammount;

public:
	CommunityCard(sf::Vector2f pos, float rotation, sf::Texture& texture_sheet, 
				std::string name, std::string cardText, int moneyAmmount);
	void setAmount(int num);
	void setCardText(string text1);
	void cardAction(Bank* bank1, Player* player1);

	string getCardText(int num);
	int getAmmount();

	void update(const float& dt, const sf::Vector2f mousePos);
};