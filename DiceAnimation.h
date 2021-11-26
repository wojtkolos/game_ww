#pragma once

#define DICEANIMATION_H

#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>


#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Network.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"

class DiceAnimation
{
private:
	float totalTime;
	float switchTime;

	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
public:
	sf::IntRect uvRect;

	//Init components
	void initVariables();
	void initComponents();
	void initTextures();

	//constructor
	DiceAnimation(sf::RectangleShape* texture, sf::Vector2u imageCount, float switchTime);
	~DiceAnimation() {}

	//functions
	void update(const float& dt);
	void setFrame(unsigned short pos, const float& dt);
};