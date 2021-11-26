#pragma once
#define MOVEMENTCOMPONENT_H

//#include "Animation.h"

#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Network.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"

class MovementComponent
{
private:
	float maxVelocity;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;

public:
	MovementComponent(float maxVelocity);
	~MovementComponent();

	//Accessors
	const sf::Vector2f& getVelocity() const;

	//Function
	void move(const float dir_x, const float dir_y);
	sf::Vector2f interpolate(const sf::Vector2f& pointA, const sf::Vector2f& pointB, float factor);
	void update(const float& dt);
};