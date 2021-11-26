#pragma once

#define SPACEACTIONHANDLER_H
#include "OperationsComponent.h"

class SpaceActionHandler
{
	OperationsComponent* operations;
	CardDeck* cardDeck;
	GameButtons* buttons;
	BoardSpaces* boardSpaces;
	GamePlayers* players;
	DialogBoxes* dialogboxes;

	short* player_turn;
	short* player_to_go;
public: 
	SpaceActionHandler(OperationsComponent* operations, CardDeck* cardDeck, 
		GameButtons* buttons, BoardSpaces* boardSpaces, GamePlayers* players, DialogBoxes* dialogboxes,
		short* player_turn, short* player_to_go);
	virtual ~SpaceActionHandler();

	void spaceAction(Player* actualPlayer);
};