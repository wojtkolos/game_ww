#pragma once

#define ENTITY_H

#include "MovementComponent.h"
#include "AnimationComponent.h"

class Entity
{
private:
	void initVariables();
protected:
	bool entityState;
	sf::Texture texture;
	sf::Sprite sprite;
	float defaultScaleX, defaultScaleY;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;

public:
	Entity();
	~Entity();

	virtual const bool isPressed() const;
	//Component functions
	void createSprite(sf::Texture& texture, sf::Vector2f pos);
	void createMovementComponent(const float maxVelocity);
	void createAnimationComponent(sf::Texture& texture_sheet);
	sf::Sprite* getSprite();
	sf::Vector2f getScale();
	sf::Vector2f getPosition();
	//Regular functions
	virtual void setPosition(sf::Vector2f pos);
	virtual void setRotation(const float x);
	virtual void setScale(sf::Vector2f scale);
	virtual void setDefaultScale();
	virtual void move(const float& dt, const float x, const float y);
	virtual void move(const sf::Vector2f& pointA, const sf::Vector2f& pointB, float factor);

	virtual void update(const float& dt, const sf::Vector2f mousePos);
	virtual void render(sf::RenderTarget* target);
};