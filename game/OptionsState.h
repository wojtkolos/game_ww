#pragma once

#define OPTIONSSTATE_H
#include "SpaceActionHandler.h"

class OptionsState :
	public State
{
private:
	//Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;
	std::map<std::string, Button*> buttons;

	//Functions
	void initBackground();
	void initKeyBinds();
	void initButtons();
public:
	OptionsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::RectangleShape& background, sf::Font& font, sf::Event* sfEvent);
	virtual ~OptionsState();

	//Functions
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* traget = nullptr);
	void render(sf::RenderTarget* traget = nullptr);

};