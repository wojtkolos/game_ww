#pragma once
#define BUTTON_H

#include "MoneyBalanceTextbox.h"


enum button_states {BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE, BTN_READY, BTN_BLOCK};

class Button
{
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
	sf::Color readyColor;
	sf::Color blockColor;

	bool blocked;
	bool active;
	bool hover;
public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, 
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color readyColor, sf::Color blockColor);
	virtual ~Button();

	//Accessors
	const bool isPressed() const;
	const bool isBlocked() const;
	const bool isActive() const;
	//Functions
	void changeState();
	void setBlocked(bool);
	void setActive(bool);
	void setHover(bool);
	void setText(std::string text);
	void setColor(unsigned short toSet);


	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};