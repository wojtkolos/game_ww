#pragma once

#define DIALOGBOX_H
#include "GameButtons.h"

class DialogBox
{
	bool paused;
	bool confirm;
	bool cancel;
	bool active;
	//unsigned short id;
	sf::RectangleShape background;
	sf::Text text;
	sf::Font* font;
	std::map<std::string, Button*> buttons;
public:
	//DialogBox(sf::Font* font, std::string text, std::string textButtonYES, std::string textButtonNO);
	DialogBox(sf::Font* font, std::string text, std::string textButtonYES, std::string textButtonNO);
	~DialogBox();

	void initVariables();
	void initButtons(std::string textButtonYES, std::string textButtonNO);
	void initButton();

	bool isConfirm();
	bool isCancel();

	bool isActive();
	void setActive(bool state);

	void resetState();

	/*void setId(unsigned short id);
	unsigned short getId();*/

	void updateButtons(const sf::Vector2f mousePosView);
	void update(const sf::Vector2f mousePos);

	void renderButtons(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

};