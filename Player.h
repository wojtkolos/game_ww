#pragma once
#define PLAYER_H
#include "SpaceHouses.h"

class Player :
    public Entity
{
private:
    //Variables
	std::string player_name;
	char game_piece;
	int money_amount;
	int location;
	bool index_of_properties[40];

	//std::map<std::string, int, bool> index_of_properties;
	bool alive;
	std::string game_piece_name;

	bool jailed;
	bool diced;

	//float pixel_location_x; 
	//float pixel_location_y;
	
    //Init components
	void initProperties();
    void initVariables();
    void initComponents(sf::Texture& texture_sheet);
public:
    Player(float x, float y, sf::Texture& texture);
    ~Player();

	//functions to set values
	void setPlayerName(std::string inputName);
	void setGamePiece(char inputPiece);
	void setOwnedProperty(int inputIndex, bool isOwned);
	void setLocation(int spaceNum);
	void setGamePieceName(std::string inputPieceName);
	//void setPixelLocation(const float x, const float y);
	void setMoneyAmount(int inputNum);
	void setDiced(bool set);
	void setJailed(bool set);

	//functions to get values
	std::string getPlayerName();
	char getGamePiece();
	int getMoneyAmount();
	bool isPropertyOwned(int inputIndex);
	int getLocation();
	bool isAlive();
	std::string getGamePieceName();
	bool getDiced();
	bool getJailed();
	bool ownedAllInColor(int pos);
	short ownedInColor(int pos);
	//Coordinates getPixelLocation();

	//other functions
	void give_money(int amount);
	void take_money(int amount);
	//void move_player(int amount);
	void reset();
};

