#include "SpaceActionHandler.h"


SpaceActionHandler::SpaceActionHandler(OperationsComponent* operations, CardDeck* cardDeck, 
	GameButtons* buttons, BoardSpaces* boardSpaces, GamePlayers* players, DialogBoxes* dialogboxes,
	short* player_turn, short* player_to_go)
{
	this->operations = operations;
	this->cardDeck = cardDeck;
	this->buttons = buttons;
	this->boardSpaces = boardSpaces;
	this->players = players;
	this->dialogboxes = dialogboxes;
	this->player_turn = player_turn;
	this->player_to_go = player_to_go;
}

SpaceActionHandler::~SpaceActionHandler()
{

}


void SpaceActionHandler::spaceAction(Player* actualPlayer)
{
	int spaceId = actualPlayer->getLocation();
	Space* actualSpace = this->boardSpaces->getSpace(spaceId);
	int owner = actualSpace->getOwnership();
	//START
	if (actualSpace->getType() == "START")
		this->operations->bankToPlayer(actualPlayer, 200, *player_turn);

	//Property
	else if (actualSpace->getType() == "Property")
	{
		if (owner == -1)
		{
			this->buttons->setButtonBlocked("BUY", false);
			this->buttons->setButtonActive("BUY", true);
		}
		//no taxes
		else if (owner == *player_turn)
		{
			//
		}
		else if (owner == 0 or owner == 1 or owner == 2 or owner == 3)
		{
			//take money without houses
			if (!actualSpace->getMortgaged())
			{
				this->operations->playerToPlayer(actualPlayer, this->players->getPlayer(owner), actualSpace->getRent() * 2, *this->player_turn, owner);
			}
			else
			{
				//take money with one house
				if (actualSpace->getHouses() == 1);
				//take money with two house
				else if (actualSpace->getHouses() == 2);
				//take money with three house
				else if (actualSpace->getHouses() == 3);
				//take money with hotel
				else if (actualSpace->getHouses() == 4);
			}
			//enable trades
			this->buttons->setButtonActive("TRADE", true);
			this->buttons->setButtonBlocked("TRADE", false);
		}
	}
	//Community Chest
	else if (actualSpace->getType() == "Community Chest")
	{
		cardDeck->setAnimation(1);
		cardDeck->setDisplay(0, true);
		cardDeck->drawCard(0);

		this->operations->cardToPlayer(actualPlayer, *this->player_to_go, *this->player_turn);
	}
	//Tax
	else if (actualSpace->getType() == "Tax")
	{
		if (actualSpace->getTax() == 200)
			this->dialogboxes->setBoxActive("INCOME_TAX", true);
		else 
			this->operations->playerToBank(actualPlayer, actualSpace->getTax(), *this->player_turn);
	}
	//RailRoad
	else if (actualSpace->getType() == "RailRoad")
	{
		if (owner == -1) {
			this->buttons->setButtonBlocked("BUY", false);
			this->buttons->setButtonActive("BUY", true);
		}
		else if (owner == *this->player_turn);
		else if (owner == 0 or owner == 1 or owner == 2 or owner == 3) {
			//tax  depends of owner comute
												 //////////////to do  
			this->operations->playerToPlayer(actualPlayer, this->players->getPlayer(owner), actualSpace->getTax(), *this->player_turn, owner);
			//2 x2
			//3 x3
			//4 x4
			
			//enable trades
			this->buttons->setButtonActive("TRADE", true);
			this->buttons->setButtonBlocked("TRADE", false);
		}
	}
	//Chance
	else if (actualSpace->getType() == "Chance")
	{
		cardDeck->setAnimation(1);
		cardDeck->setDisplay(1, true);
		cardDeck->drawCard(1);

		this->operations->cardToPlayer(actualPlayer, *this->player_to_go, *this->player_turn);
	}
	//Jail
	else if (actualSpace->getType() == "Jail" and actualPlayer->getJailed())
	{
		//nothing to do
	}
	//Utility
	else if (actualSpace->getType() == "Utility")
	{
		if (owner == -1) {
			this->buttons->setButtonBlocked("BUY", false);
			this->buttons->setButtonActive("BUY", true);
		}
		else if (owner == *this->player_turn);

		else if (owner == 0 or owner == 1 or owner == 2 or owner == 3) { //to do - player dice and number is counter of tax
			//tax  depends of owner utilities
			//take money with one utilities
			this->operations->playerToPlayer(actualPlayer, this->players->getPlayer(owner), actualSpace->getTax(), *this->player_turn, owner);

			//enable trades
			this->buttons->setButtonActive("TRADE", true);
			this->buttons->setButtonBlocked("TRADE", false);


			//take money with two utilities

			//take money with three utilities

		}
	}
	//FreeParking
	else if (actualSpace->getType() == "FreeParking")
	{
		//NaN
	}
	//GoJail
	else if (actualSpace->getType() == "GoJail")
	{
		actualPlayer->setPosition(this->boardSpaces->getSpacePos2(10));
		actualPlayer->setLocation(10);
		actualPlayer->setJailed(true);
	}
}
