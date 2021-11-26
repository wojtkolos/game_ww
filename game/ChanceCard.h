#pragma once
#define CHANCE_CARD_H

#include "HugeCard.h"

class ChanceCard 
	: public Card 
{

private:
	string cardText;
	int locationNum;
	int ammount; //???

public:
	ChanceCard(sf::Vector2f pos, float rotation, sf::Texture& texture_sheet, 
				std::string name, std::string cardText, int moneyAmmount);
	void setAmount(int num);
	void setCardText(string text1);
	void cardAction(Bank* bank1, Player* player1);
	string getCardText(int num);
	int getAmmount();
	void update(const float& dt, const sf::Vector2f mousePos);

};