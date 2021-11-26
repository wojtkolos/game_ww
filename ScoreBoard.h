#pragma once

#define SCOREBOARD_H

#include "State.h"
#include "CirclePointers.h"
#include "Bank.h"


class ScoreBoard
{
    sf::Font font;
    int total_players;
    int player_turn;

    Bank* bank;
    std::vector<Player*> playerptr;
    std::map<std::string, Textbox*> textScore;
    std::map<std::string, MoneyBalanceTextbox*> textScoreBalance;
    //buttons & text
    CirclePointers* circlePointers;

public:
	ScoreBoard(unsigned short totalPlayers, std::vector<Player*> players, Bank* bank, int player_turn, sf::Font& font);
	virtual ~ScoreBoard();

    //init
    void initVariables(unsigned short totalPlayers, std::vector<Player*> players, Bank* bank, int player_turn, sf::Font& font);
    void initTextboxes();
    void initMoneyBalanceTextboxes();
    //update
    void updateAmountDisp();
    void updateNames(std::string space_name, short space_owner);
    void update(const float& dt, int player_turn, std::string space_name, short space_owner);

    void renderTextScore(sf::RenderTarget* target);
    void renderTextBalance(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);

    //other
    void changeScoreBalance(int playerNum, int ammount, bool hidden);
    void resetMoneyBalanceTextboxes();

    //CentralWidget(int tempNum, Player* tempPlayers);
    //void changeDiceImg(int rollNum1, int rollNum2);
    //void movePieces(int playerNum, Coordinates tempCoordinates);
   // void hidePiece(int playerNum);
   // void showCommunity(int cardNum);
   // void resetCommunity(int cardNum);
   // void showChance(int cardNum);
   // void resetChance(int cardNum);
    //void initializingCards(int tempArray[]);
};