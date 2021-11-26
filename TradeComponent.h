#pragma once

#define TRADECOMPONENT_H
#include "Trade.h"
class GamePlayers;
class OperationsComponent;

class TradeComponent
{
	bool active;
	sf::Font* font;
	GamePlayers* players;
	OperationsComponent* operations;
	std::vector<Space*> spaces;

	std::vector<CounterTrade*> incometrades;
	std::vector<Trade*> outtrades;

	void initVariables();
	void initTrades();
public:
	TradeComponent(sf::Font* font, GamePlayers* players, OperationsComponent* operations);
	virtual ~TradeComponent();

	void setActive(bool state);
	bool isActive();

	void createOffer(short senderID, short recipientID, Space* space);

	void updateIncomeTrade(const sf::Vector2f mousePos, short playerID);
	void updateOutTrade(const sf::Vector2f mousePos, short playerID);
	void update(const sf::Vector2f mousePos, short playerID);

	void render(sf::RenderTarget* target, short playerID);
};

