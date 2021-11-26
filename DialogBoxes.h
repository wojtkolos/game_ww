#pragma once

#define DIALOGBOXES_H
#include "DialogBox.h"


class DialogBoxes
{
	sf::Font font;
	std::map<std::string, DialogBox*> dialogboxes;

	void initDialogBoxes();
public:
	DialogBoxes(sf::Font& font);
	~DialogBoxes();

	bool isBoxConfirm(std::string key);
	bool isBoxCancel(std::string key);

	bool isBoxActive(std::string key);
	void setBoxActive(std::string key, bool state);

	void resetBoxState(std::string key);

	DialogBox* getDialogBox(std::string key);
	

	void update(sf::Vector2f mousePosView);
	void  render(sf::RenderTarget* target);
};

