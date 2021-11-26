#pragma once


#define COUNTERTRADE_H
#include "DialogBoxes.h"
class Space;

class CounterTrade
{
	bool active;
	bool confirm;
	bool cancel;

	sf::RectangleShape background;
	sf::Text text;
	sf::Text value_text;
	sf::Text space_name;
	sf::Font* font;
	std::map<std::string, Button*> buttons;

	short user_source;
	short user_destination;
	int propose_value;
	Space* space;


	void initVariables();
	void initButtons(float pos_x);

public:
	CounterTrade(sf::Font* font);
	virtual ~CounterTrade();

	bool isConfirm();
	bool isCancel();
	bool isActive();
	void setActive(bool state);

	void resetState();

	void setUserSource(short usr);
	void setUserDestination(short usr);
	void setPoposeValue(int value);
	void setSpace(Space* space);
	void setTradeParameters(short usr_s, short usr_d, Space* space);

	short getUserSource();
	short getUserDestination();
	int getPoposeValue();
	Space* getSpace();


	void updateButtons(const sf::Vector2f mousePosView);
	void update(const sf::Vector2f mousePos);

	void renderButtons(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

