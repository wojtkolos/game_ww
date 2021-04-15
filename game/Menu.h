#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu {
	int selectedItemIndex;
	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS]; 

public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	int getPressedItem();
};