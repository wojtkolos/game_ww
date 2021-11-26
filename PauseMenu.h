#pragma once

#define PAUSEMENU_H
#include "AnimationComponent.h"
#include "Button.h"

class State;

class PauseMenu
{
	sf::Font& font;
	sf::Text menuText;
	sf::Text volumeText;
	sf::RectangleShape backgrund;
	sf::RectangleShape container;
	State* parentState;

	short prev_volume;
	std::map<std::string, Button*> buttons;
public:
	PauseMenu(sf::RenderWindow& window, sf::Font& font, State* parentState);
	virtual ~PauseMenu();

	void initButtons();
	void initTextMenu();
	//functions
	const bool isButtonPressed(const std::string key);
	void musicVolumeButtonsColor();
	void musicVolumeSetButtons();

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget& target);
};

