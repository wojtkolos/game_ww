#include "MovementComponent.h"


MovementComponent::MovementComponent(float maxVelocity)
{
	this->maxVelocity = maxVelocity;
}
MovementComponent::~MovementComponent()
{
	
}

//Accessors
const sf::Vector2f& MovementComponent::getVelocity() const 
{
	return this->velocity;
}

//Functions
void MovementComponent::move(const float dir_x, const float dir_y)
{
	this->velocity.x = this->maxVelocity * dir_x;
	this->velocity.y = this->maxVelocity * dir_y;
}

sf::Vector2f MovementComponent::interpolate(const sf::Vector2f& pointA, const sf::Vector2f& pointB, float factor) 
{
	if (factor > 1.f)
		factor = 1.f;

	else if (factor < 0.f)
		factor = 0.f;

	return pointA + (pointB - pointA) * factor;
}

void MovementComponent::update(const float& dt)
{
	
	
}