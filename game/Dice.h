#pragma once

#define DICE_H
#include "Entity.h"
#include "DiceAnimation.h"
//#include "AnimationComponent.h"

class Dice
	: public Entity
{
private:
	int sides;
	float totalTime;
	float switchTime;

	short unsigned diceState;

	sf::RectangleShape* dice;
	sf::Texture texture;
	DiceAnimation* dice_animation;
public:

	//Init components
	void initVariables(float x, float y);
	void initComponents();
	void initTextures();

	//constructor
	Dice(float x, float y);
	~Dice();

	//Accessors
	//const bool isPressed() const;


	//functions to get values
	int rollDice(const float& dt);
	int randomGenerator();
	void update(const float& dt, const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};