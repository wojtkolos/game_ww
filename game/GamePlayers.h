#pragma once

#define GAMEPLAYERS_H
#include "BoardSpaces.h"


class GamePlayers
{
	std::map<std::string, sf::Texture> textures;
	std::vector<Player*> players;
	int total_players;
	void initTextures();
	void initPlayers();

public:
	GamePlayers(std::map<std::string, sf::Texture>& textures, int total_players);
	~GamePlayers();

	std::vector<Player*>& getPlayers();
	Player* getPlayer(int index);

	void update(const float& dt, sf::Vector2f mousePosView);
	void render(sf::RenderTarget* target);
};

