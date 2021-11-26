#pragma once
#define MAINMENUSTATE_H

#include "GameSetState.h"




class MainMenuState :
	public State
{ 
private:
	
	//Variables
	sf::Texture backgroundTexture;
	sf::Font font;
	sf::RectangleShape background;
	std::map<std::string, Button*> buttons;

	short selectedIndex;
	//Functions
	void moveDown();
	void moveUp();

	void initVariables();
	void initBackground();
	void initMusic();
	void initFonts();
	void initKeyBinds();
	void initButtons();
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Event* sfEvent);
	virtual ~MainMenuState();

	//Functions
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* traget = nullptr);
	void render(sf::RenderTarget* traget = nullptr);
};