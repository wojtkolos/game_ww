#include "OperationsComponent.h"


void OperationsComponent::initVariables(Bank* bank, ScoreBoard* scoreBoard, CardDeck* cardDeck)
{
	this->bank = bank;
	this->scoreBoard = scoreBoard;
	this->cardDeck = cardDeck;

	this->bought = false;
	this->upgraded = false;

	for (int i = 0; i < 4; i++)
		players[i] = 0;
}

OperationsComponent::OperationsComponent(Bank* bank, ScoreBoard* scoreBoard, CardDeck* cardDeck, int maxPlayers)
{
	this->initVariables(bank, scoreBoard, cardDeck);
}

OperationsComponent::~OperationsComponent()
{
	
}

//functions
void OperationsComponent::buySpace(Player* p, Space* s, short player)
{
	p->setOwnedProperty(p->getLocation(), true);
	this->playerToBank(p, s->getPropertyCost(), player);
	s->setOccupied(1);
	s->setOwnership(player);
	//s->setMortgaged(1);
}

void OperationsComponent::upgradeSpace()
{
	
}

void OperationsComponent::playerToBank(Player* p, int ammount, short player)
{
	p->take_money(ammount);
	this->bank->give_money(ammount);
	this->scoreBoard->changeScoreBalance(player, -1*ammount, 0);
}


void OperationsComponent::bankToPlayer(Player* p, int ammount, short player)
{
	this->bank->take_money(ammount);
	p->give_money(ammount);
	this->scoreBoard->changeScoreBalance(player, ammount, 0);
}

void OperationsComponent::playerToPlayer(Player* pTake, Player* pGive, int ammount, int playerTake, int playerGive)
{
	pTake->take_money(ammount);
	pGive->give_money(ammount);
	this->scoreBoard->changeScoreBalance(playerTake, -1 * ammount, 0);
	this->scoreBoard->changeScoreBalance(playerGive, ammount, 0);
}

void OperationsComponent::playerTrade(Player* pTake, Player* pGive, Space* s, int ammount, int playerTake, int playerGive)
{
	s->setOccupied(1);
	s->setOwnership(playerTake);
	pTake->setOwnedProperty(pTake->getLocation(), true);
	pTake->take_money(ammount);
	pGive->give_money(ammount);
	this->scoreBoard->changeScoreBalance(playerTake, -1 * ammount, 0);
	this->scoreBoard->changeScoreBalance(playerGive, ammount, 0);
}

void OperationsComponent::cardToPlayer(Player* p, short& player_to_go, short player)
{
	this->bankToPlayer(p, this->cardDeck->cardAction(this->bank, p, player_to_go), player);
}