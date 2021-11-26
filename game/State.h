#pragma once

#define STATE_H
#include "GamePlayers.h"


class State 
{
protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	sf::Music* music;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keyBinds;
	sf::Event* sfEvent;
	bool quit;
	bool paused;
	float keytime;
	float keytimeMax;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Recources
	std::map<std::string, sf::Texture> textures;

	
	virtual void initKeyBinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Event* sfEvent);
	~State();

	//Accessors
	const bool& getQuit() const;
	const bool getKeytime();

	//Functions
	void endState();
	void setMusicVolume(int volume);
	int getMusicVolume();
	void pauseMusic();
	void unpauseMusic();
	void pauseState();
	void unpauseState();

	virtual void updateMousePositions();
	virtual void updateKeytime(const float& dt);
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* traget = nullptr) = 0;
};