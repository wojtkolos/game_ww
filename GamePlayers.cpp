#include "GamePlayers.h"

void GamePlayers::initTextures()
{
	if (!this->textures["PLAYER_SHIP"].loadFromFile("Recources/Images/Sprites/Player/ship.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_SHIP_TEXTURE";
	if (!this->textures["PLAYER_SOCCER"].loadFromFile("Recources/Images/Sprites/Player/soccer.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_SOCCER_TEXTURE";
	if (!this->textures["PLAYER_DOG"].loadFromFile("Recources/Images/Sprites/Player/dog.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_DOG_TEXTURE";
	if (!this->textures["PLAYER_HAT"].loadFromFile("Recources/Images/Sprites/Player/hat.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_HAT_TEXTURE";
}

void GamePlayers::initPlayers()
{
	if (total_players == 2) {
		this->players.push_back(new Player(1000, 920, this->textures["PLAYER_SHIP"]));
		this->players.push_back(new Player(980, 1000, this->textures["PLAYER_SOCCER"]));
	}
	else if (total_players == 3) {
		this->players.push_back(new Player(1000, 920, this->textures["PLAYER_SHIP"]));
		this->players.push_back(new Player(980, 1000, this->textures["PLAYER_SOCCER"]));
		this->players.push_back(new Player(960, 940, this->textures["PLAYER_DOG"]));
	}
	else if (total_players == 4) {
		this->players.push_back(new Player(1000, 920, this->textures["PLAYER_SHIP"]));
		this->players.push_back(new Player(980, 1000, this->textures["PLAYER_SOCCER"]));
		this->players.push_back(new Player(960, 940, this->textures["PLAYER_DOG"]));
		this->players.push_back(new Player(960, 1000, this->textures["PLAYER_HAT"]));
	}
}

GamePlayers::GamePlayers(std::map<std::string, sf::Texture>& textures, int total_players)
{
	this->total_players = total_players;
	this->textures = textures;
	this->initTextures();
	this->initPlayers();
}

GamePlayers::~GamePlayers()
{
	for (auto& player : this->players)
		delete player;
}


std::vector<Player*>& GamePlayers::getPlayers()
{
	return this->players;
}

Player* GamePlayers::getPlayer(int index)
{
	return this->players[index];
}

void GamePlayers::update(const float& dt, sf::Vector2f mousePosView)
{
	for (auto & player : this->players)
		player->update(dt, mousePosView);
}

void GamePlayers::render(sf::RenderTarget* target)
{
	for (auto& player : this->players)
		player->render(target);
}