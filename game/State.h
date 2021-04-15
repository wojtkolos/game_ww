#pragma once
#define STATE_H

#include "Entity.h"

class State 
{
protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;
public:
	State(sf::RenderWindow* window);
	~State();

	const bool& getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* traget = nullptr) = 0;
};