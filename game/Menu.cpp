#include "Menu.h"


Menu::Menu(float width, float height)
{
	//sf::Font font;
	if (!font.loadFromFile("Fonts/Roboto-Black.ttf"))
	{
		// handle error
	}

	text[0].setFont(font);
	text[0].setCharacterSize(100); 
	text[0].setFillColor(sf::Color::Red);
	text[0].setString("Play");
	text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	

	text[1].setFont(font);
	text[1].setCharacterSize(100);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("Options");
	text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	text[2].setFont(font);
	text[2].setCharacterSize(100);
	text[2].setFillColor(sf::Color::White);
	text[2].setString("Exit");
	text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


Menu::~Menu() {
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) 
	{
		window.draw(text[i]);
	}
}

void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		text[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		text[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) 
	{
		text[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		text[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

int Menu::getPressedItem() 
{
	return selectedItemIndex;
}