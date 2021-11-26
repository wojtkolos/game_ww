#include "ChanceCard.h"

ChanceCard::ChanceCard(sf::Vector2f pos, float rotation, sf::Texture& texture_sheet,
						std::string name, std::string cardText, int moneyAmmount)
	: Card(pos, rotation, texture_sheet, name)
{
	cardText = "Card Name";
	locationNum = -1;
	ammount = moneyAmmount;
}

void ChanceCard::setAmount(int num) 
{
	locationNum = num;
}

void ChanceCard::setCardText(string text1)
{
	cardText = text1;
}

void ChanceCard::cardAction(Bank* bank1, Player* player1)
{
	player1->setLocation(locationNum);
}

string ChanceCard::getCardText(int num) 
{
	return cardText;
}

int ChanceCard::getAmmount()
{
	return this->ammount;
}

void ChanceCard::update(const float& dt, const sf::Vector2f mousePos)
{
	this->Entity::update(dt, mousePos);
}