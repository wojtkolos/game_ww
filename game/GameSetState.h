#pragma once
#define GAMESETSTATE_H

#include "GameState.h"

class GameSetState :
	public State
{
private:
	//Variables
	sf::RectangleShape background;
	sf::Font font;
	unsigned short number_of_players;

	std::map<std::string, Button*> buttons;

	//Functions
	void initKeyBinds();
	void initButtons();
public:
	GameSetState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::RectangleShape& background, sf::Font& font, sf::Event* sfEvent, sf::Music* music);
	virtual ~GameSetState();

	//Functions
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* traget = nullptr);
	void render(sf::RenderTarget* traget = nullptr);

};