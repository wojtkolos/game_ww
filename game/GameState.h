#pragma once

#define GAMESTATE_H

#include "State.h"

class GameState :
	public State
{
	Entity player;
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();


	//Functions
	void endState();

	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* traget = nullptr);
};
