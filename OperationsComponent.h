#pragma once

#define OPERATIONSCOMPONENT_H
#include "ScoreBoard.h"

class OperationsComponent 
{
	int players[4];
	bool bought;
	bool upgraded;

	Bank* bank;
	ScoreBoard* scoreBoard;
	CardDeck* cardDeck;
public:
	OperationsComponent(Bank* bank, ScoreBoard* scoreBoard, CardDeck* cardDeck, int maxPlayers);
	~OperationsComponent();


	void initVariables(Bank* bank, ScoreBoard* scoreBoard, CardDeck* cardDeck);

	//void go;
	void buySpace(Player* p, Space* s, short player);
	void upgradeSpace();

	void bankToPlayer(Player* p, int ammount, short player);
	void playerToBank(Player* p, int ammount, short player);
	
	void playerToPlayer(Player* pTake, Player* pGive, int ammount, int playerTake, int playerGive);
	void playerTrade(Player* pTake, Player* pGive, Space* s, int ammount, int playerTake, int playerGive);

	void cardToPlayer(Player* p, short& player_to_go, short player);
};