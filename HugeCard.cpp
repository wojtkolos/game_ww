#include "HugeCard.h"


HugeCard::HugeCard(sf::Vector2f pos, float rotation, sf::Texture& texture_sheet)
	: Card(pos, rotation, texture_sheet, "Huge Card")
{
	
}


void HugeCard::setAmount(int num) {}
void HugeCard::setCardText(string text1) {}
void HugeCard::cardAction(Bank* bank1, Player* player1) {}

string HugeCard::getCardText(int num) 
{ 
	return ""; 
}

int HugeCard::getAmmount()
{
	return 0;
}

void HugeCard::update(const float& dt, const sf::Vector2f mousePos)
{
	this->Entity::update(dt, mousePos);
}
