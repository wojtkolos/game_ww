#include "MoneyBalanceTextbox.h"


MoneyBalanceTextbox::MoneyBalanceTextbox(float x, float y, float width, float height, int fontSize, sf::Font* font, std::string text,
	sf::Color idleColor)
	: Textbox(x, y, width, height, fontSize, font, text, idleColor)
{
	this->hidden = true;
}

MoneyBalanceTextbox::~MoneyBalanceTextbox()
{
	
}


void MoneyBalanceTextbox::setBalance(int balance)
{
	if (balance > 0)
	{
		this->setText("+" + std::to_string(balance) + "$");
		this->setFillColor(sf::Color::Green);
	}
	else if (balance < 0)
	{
		this->setText(std::to_string(balance) + "$");
		this->setFillColor(sf::Color::Red);
	}
}

void MoneyBalanceTextbox::setHidden(bool hidden)
{
	this->hidden = hidden;
}

bool MoneyBalanceTextbox::isHidden()
{
	return this->hidden;
}