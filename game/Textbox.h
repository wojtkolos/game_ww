#pragma once
#define TEXTBOX_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>
#include <chrono>
#include <thread>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"

class Textbox {
private:
	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
public:
	Textbox(float x, float y, float width, float height, int fontSize, sf::Font* font, std::string text,
		sf::Color idleColor, sf::Color textColor = sf::Color::White);
	virtual ~Textbox();

	//Accessors
	//const bool isPressed() const;

	//Functions
	virtual void update(const sf::Vector2f mousePos);
	virtual void render(sf::RenderTarget* target);

	virtual void setText(std::string text);
	virtual void setFillColor(sf::Color textColor);
};