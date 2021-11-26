#include "CommunityCard.h"

CommunityCard::CommunityCard(sf::Vector2f pos, float rotation, sf::Texture& texture_sheet, 
							std::string name, std::string cardText, int moneyAmmount)
	: Card(pos, rotation, texture_sheet, name)
{
	cardText = "Card Name";
	ammount = moneyAmmount;
}

void CommunityCard::setAmount(int num)
{
	ammount = num;
}

void CommunityCard::setCardText(string text1)
{
	cardText = text1;
}

void CommunityCard::cardAction(Bank* bank1, Player* player1)
{
	bank1->take_money(ammount);
	player1->give_money(ammount);
}

string CommunityCard::getCardText(int num)
{
	return cardText;
}

int CommunityCard::getAmmount()
{
	return this->ammount;
}

void CommunityCard::update(const float& dt, const sf::Vector2f mousePos)
{
	this->Entity::update(dt, mousePos);
}