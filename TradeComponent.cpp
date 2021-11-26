#include "TradeComponent.h"
#include "GamePlayers.h"
#include "OperationsComponent.h"

void TradeComponent::initVariables()
{

}

void TradeComponent::initTrades()
{
	this->outtrades.push_back(new Trade(this->font));
	this->outtrades.push_back(new Trade(this->font));
	this->outtrades.push_back(new Trade(this->font));
	this->outtrades.push_back(new Trade(this->font));

	this->incometrades.push_back(new CounterTrade(this->font));
	this->incometrades.push_back(new CounterTrade(this->font));
	this->incometrades.push_back(new CounterTrade(this->font));
	this->incometrades.push_back(new CounterTrade(this->font));
}

TradeComponent::TradeComponent(sf::Font* font, GamePlayers* players, OperationsComponent* operations)
{
	this->font = font;
	this->players = players;
	this->operations = operations;

	this->initVariables();
	this->initTrades();
}

TradeComponent::~TradeComponent()
{
	for (auto& trades : this->incometrades)
		delete trades;
	for (auto& trades : this->outtrades)
		delete trades;
}

void TradeComponent::createOffer(short senderID, short recipientID, Space* space)
{
	this->outtrades[senderID]->setTradeParameters(senderID, recipientID, space);
	this->incometrades[recipientID]->setTradeParameters(senderID, recipientID, space);
}


void TradeComponent::setActive(bool state)
{
	this->active = state;
}

bool TradeComponent::isActive()
{
	return this->active;
}

void TradeComponent::updateIncomeTrade(const sf::Vector2f mousePos, short playerID)
{
	Trade* player_s = this->outtrades[this->incometrades[playerID]->getUserSource()];
	int ammount = player_s->getPoposeValue();
	short player_s_id = player_s->getUserSource();
	short player_d_id = player_s->getUserDestination();

	this->incometrades[playerID]->update(mousePos);
	if (this->incometrades[playerID]->isConfirm()) {
		this->operations->playerTrade(players->getPlayer(player_s_id), players->getPlayer(player_d_id), player_s->getSpace(), ammount, player_s_id, player_d_id);
		this->incometrades[playerID]->resetState();
	}
	else if (this->incometrades[playerID]->isCancel())
		this->incometrades[playerID]->resetState();
}

void TradeComponent::updateOutTrade(const sf::Vector2f mousePos, short playerID)
{
	this->outtrades[playerID]->update(mousePos);

	if (this->outtrades[playerID]->isConfirm()) {
		this->incometrades[this->outtrades[playerID]->getUserDestination()]->setPoposeValue(this->outtrades[playerID]->getPoposeValue());
		this->outtrades[playerID]->resetState();
	}
	if (this->outtrades[playerID]->isCancel())
		this->outtrades[playerID]->resetState();
}

void TradeComponent::update(const sf::Vector2f mousePos, short playerID)
{
	if (!this->outtrades[playerID]->isActive() && this->incometrades[playerID]->isActive())
		this->updateIncomeTrade(mousePos, playerID);
	if (this->outtrades[playerID]->isActive()) 
		this->updateOutTrade(mousePos, playerID);
}

void TradeComponent::render(sf::RenderTarget* target, short playerID)
{
	if (!this->outtrades[playerID]->isActive() && this->incometrades[playerID]->isActive()) this->incometrades[playerID]->render(target);
	if (this->outtrades[playerID]->isActive())	this->outtrades[playerID]->render(target);
}
