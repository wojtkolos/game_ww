#pragma once
#define GAMESTATE_H

#include "OptionsState.h"
#include "PauseMenu.h"


class GameState :
	public State
{
private:
	PauseMenu* pmenu;

	sf::Font font;
	int total_players;
	short player_turn;
	short player_to_go;
	float dt_freeze;
	Player* actualPlayer;

	sf::Music* menuMusic;
	//objects
	Dice* dice;
	Dice* dice2;
	Bank* bank;
	ScoreBoard* score_board;
	CardDeck* card_deck;
	TradeComponent* trade_component;

	//players
	GamePlayers* players;
	//board
	BoardSpaces* boardSpaces;

	//buttons & text
	GameButtons* gameButtons;

	OperationsComponent* operations;
	SpaceActionHandler* spaceActionHandler;
	
	//background
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	//DialogBox
	DialogBoxes* dialogboxes;

	//Init functions
	void initVariables(unsigned short totalPlayers, sf::Font& font);
	void initBackground();
	void initMusic();
	void initKeyBinds();
	void initBoardComponents();

	void initPauseMenu();

public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, 
		unsigned short totalPlayers, sf::Font& font, sf::Event* sfEvent, sf::Music* music);
	virtual ~GameState();

	//Functions
	void updateButtons(const float& dt);
	void updatePauseMenuButtons();
	void updateDice(const float& dt);
	void moveCheck(const float& dt);
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void actionFreezeUpdate(const float& dt);
	void update(const float& dt);
	
	//Player
	void playerTurn(const float& dt);
	void playerMove(const float& dt);
	void nextPlayer();

	void renderButtons(sf::RenderTarget* target);
	void renderTextScore(sf::RenderTarget* target);
	void render(sf::RenderTarget* target = nullptr);
};