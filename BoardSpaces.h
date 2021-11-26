#pragma once

#define BOARDSPACES_H
#include "Space.h"

#include "Coordinates.h"
class BoardSpaces
{
	std::vector<Space*> spaces;
	std::vector<Coorinates> boardSpace;

	std::map<std::string, sf::Texture> textures;
	std::vector<SpaceHouses*> houses;

	void initSpaceLocations();
	void initSpaceParam();
	void initTextures();
	void initHouses();

public:
	BoardSpaces();
	~BoardSpaces();

	sf::Vector2f getSpacePos1(int element);
	sf::Vector2f getSpacePos2(int element);

	Space* getSpace(int element);

	void update(const float& dt, sf::Vector2f mousePosView);
	void render(sf::RenderTarget* target);

};

