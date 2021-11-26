#pragma once
#include "Textbox.h"

class MoneyBalanceTextbox
	:public Textbox 
{
	bool hidden;
public:
	MoneyBalanceTextbox(float x, float y, float width, float height, int fontSize, sf::Font* font, std::string text,
		sf::Color idleColor);
	virtual ~MoneyBalanceTextbox();

	void setBalance(int balance);
	void setHidden(bool hidden);
	bool isHidden();
};