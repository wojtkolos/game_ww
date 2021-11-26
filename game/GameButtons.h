#pragma once

#define GAMEBUTTONS_H
#include "Button.h"

class GameButtons
{
	sf::Font font;
	std::map<std::string, Button*> buttons;
public:
	GameButtons(sf::Font& font);
	virtual ~GameButtons();

	void initButtons();
	
	//functions
	void defaultButtonsStates();
	const bool isButtonPressed(const std::string key);
	const bool isButtonBlocked(const std::string key);
	void setButtonBlocked(const std::string key, bool action);
	void setButtonActive(const std::string key, bool action);
	


	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

