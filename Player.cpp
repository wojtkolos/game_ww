#include "Player.h"

void Player::initProperties()
{
	for (int i = 0; i < 40; i++) {
		index_of_properties[i] = false;
	}
}

//Init components
void Player::initVariables()
{
	this->location = 0;
	this->money_amount = 2500;
	
	this->alive = true;
	this->diced = false;
	//player_name = "John";
	this->jailed = false;
}

void Player::initComponents(sf::Texture& texture_sheet)
{
	this->createMovementComponent(100.f);
	//this->createAnimationComponent(texture_sheet);
}


//Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();
	
	this->createSprite(texture_sheet, sf::Vector2f(0.07f, 0.07f));
	this->setPosition(sf::Vector2f(x, y));

	this->initComponents(texture_sheet);

	//this->animationComponent->addAnimation("IDLE_LEFT", 100.0f, 0, 0, 13, 0, 64, 64);
}

Player::~Player()
{
	
}

void Player::setMoneyAmount(int inputNum) {
	this->money_amount = inputNum;
}

//Set
void Player::setPlayerName(std::string inputName) {
	this->player_name = inputName;
}

void Player::setGamePiece(char inputPiece) {
	this->game_piece = inputPiece;
}

void Player::setGamePieceName(std::string inputPieceName) {
	this->game_piece_name = inputPieceName;
}

void Player::setLocation(int spaceNum) {
	this->location = spaceNum;
}

void Player::setOwnedProperty(int inputIndex, bool isOwned) {
	this->index_of_properties[inputIndex] = isOwned;
}

void Player::setDiced(bool set)
{
	this->diced = set;
}

void Player::setJailed(bool set)
{
	this->jailed = set;
}

//Get
std::string Player::getPlayerName() {
	return this->player_name;
}

char Player::getGamePiece() {
	return this->game_piece;
}

int Player::getMoneyAmount() {
	return this->money_amount;
}

int Player::getLocation() {
	return this->location;
}

std::string Player::getGamePieceName() {
	return this->game_piece_name;
}

bool Player::isPropertyOwned(int inputIndex) {
	return this->index_of_properties[inputIndex];
}

bool Player::isAlive() {
	return this->alive;
}

bool Player::getDiced()
{
	return this->diced;
}

bool Player::getJailed()
{
	return this->jailed;
}

bool Player::ownedAllInColor(int pos)
{
	if (pos == 1 or pos == 3) 
	{
		if (index_of_properties[1] == 1 && index_of_properties[3] == 1) return true;
	}
	else if (pos == 6 or pos == 8 or pos == 9)
	{
		if (index_of_properties[6] == 1 && index_of_properties[8] == 1 && index_of_properties[9] == 1) return true;
	}
	else if (pos == 11 or pos == 13 or pos == 14)
	{
		if (index_of_properties[11] == 1 && index_of_properties[13] == 1 && index_of_properties[14] == 1) return true;
	}
	else if (pos == 16 or pos == 18 or pos == 19)
	{
		if (index_of_properties[16] == 1 && index_of_properties[18] == 1 && index_of_properties[19] == 1) return true;
	}
	else if (pos == 16 or pos == 18 or pos == 19)
	{
		if (index_of_properties[16] == 1 && index_of_properties[18] == 1 && index_of_properties[19] == 1) return true;
	}
	else if (pos == 21 or pos == 23 or pos == 24)
	{
		if (index_of_properties[21] == 1 && index_of_properties[23] == 1 && index_of_properties[24] == 1) return true;
	}
	else if (pos == 26 or pos == 27 or pos == 29)
	{
		if (index_of_properties[26] == 1 && index_of_properties[27] == 1 && index_of_properties[29] == 1) return true;
	}
	else if (pos == 31 or pos == 32 or pos == 34)
	{
		if (index_of_properties[31] == 1 && index_of_properties[32] == 1 && index_of_properties[34] == 1) return true;
	}
	else if (pos == 37 or pos == 39)
	{
		if (index_of_properties[37] == 1 && index_of_properties[39] == 1) return true;
	}
	else if (pos == 5 or pos == 15 or pos == 25 or pos == 35)
	{//cargo
		if (index_of_properties[5] == 1 && index_of_properties[15] == 1 && index_of_properties[25] == 1 && index_of_properties[35] == 1) return true;
	}//utilities
	else if (pos == 12 or pos == 28)
	{
		if (index_of_properties[12] == 1 && index_of_properties[28] == 1) return true;
	}
	return false;
}

short Player::ownedInColor(int pos)
{
	int counter = 0;
	if (pos == 1 or pos == 3)
	{
		if (index_of_properties[1] == 1) counter++;
		if(index_of_properties[3] == 1) counter++;
		return counter;
	}
	else if (pos == 6 or pos == 8 or pos == 9)
	{
		if (index_of_properties[6] == 1) counter++;
		if (index_of_properties[8] == 1) counter++;
		if (index_of_properties[9] == 1) counter++;
		return counter;
	}
	else if (pos == 11 or pos == 13 or pos == 14)
	{
		if (index_of_properties[11] == 1) counter++;
		if (index_of_properties[13] == 1) counter++;
		if (index_of_properties[14] == 1) counter++;
		return counter++;
	}
	else if (pos == 16 or pos == 18 or pos == 19)
	{
		if (index_of_properties[16] == 1) counter++;
		if (index_of_properties[18] == 1) counter++;
		if (index_of_properties[19] == 1) counter++;
			return counter++;
	}
	else if (pos == 16 or pos == 18 or pos == 19)
	{
		if (index_of_properties[16] == 1) counter++; 
		if (index_of_properties[18] == 1) counter++;
		if (index_of_properties[19] == 1) counter++;
		return counter;
	}
	else if (pos == 21 or pos == 23 or pos == 24)
	{
		if (index_of_properties[21] == 1) counter++; 
		if (index_of_properties[23] == 1) counter++;
		if (index_of_properties[24] == 1) counter++;
		return counter;
	}
	else if (pos == 26 or pos == 27 or pos == 29)
	{
		if (index_of_properties[26] == 1) counter++;
		if (index_of_properties[27] == 1) counter++;
		if (index_of_properties[29] == 1) counter++;
		return counter;
	}
	else if (pos == 31 or pos == 32 or pos == 34)
	{
		if (index_of_properties[31] == 1) counter++;
		if (index_of_properties[32] == 1) counter++;
		if (index_of_properties[34] == 1) counter++;
		return counter;
	}
	else if (pos == 37 or pos == 39)
	{
		if (index_of_properties[37] == 1) counter++;
		if (index_of_properties[39] == 1) counter++; 
		return counter;
	}
	else if (pos == 5 or pos == 15 or pos == 25 or pos == 35)
	{//cargo
		if (index_of_properties[5] == 1) counter++;
		if (index_of_properties[15] == 1) counter++;
		if (index_of_properties[25] == 1) counter++;
		if(index_of_properties[35] == 1) counter++; 
		return counter;
	}//utilities
	else if (pos == 12 or pos == 28)
	{
		if (index_of_properties[12] == 1) counter++;
		if (index_of_properties[28] == 1) counter++; 
		return counter;
	}
	return 0;
}

//other
void Player::give_money(int amount) {
	this->money_amount += amount;
}

void Player::take_money(int amount) {
	this->money_amount -= amount;
}

void Player::reset() {
	this->money_amount = 0;
	this->location = 0;
	this->game_piece = ' ';
	this->alive = false;
}

