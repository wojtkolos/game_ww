#include "Entity.h"


void Entity::initVariables()
{
	this->defaultScaleX = 1.f;
	this->defaultScaleY = 1.f;
	this->movementComponent = nullptr;
	this->animationComponent = nullptr;

	this->entityState = false;
}

Entity::Entity() 
{
	this->initVariables();
}
Entity::~Entity() 
{
	delete this->animationComponent;
	delete this->movementComponent;
}


//Accessors
const bool Entity::isPressed() const
{
	if (this->entityState)
		return true;
	return false;
}

//Component functions
void Entity::createSprite(sf::Texture& texture, sf::Vector2f scale)
{
	this->defaultScaleX = scale.x;
	this->defaultScaleY = scale.y;
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->sprite.setScale(scale.x, scale.y);
}

void Entity::createMovementComponent(const float maxVelocity) 
{
	this->movementComponent = new MovementComponent(maxVelocity);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(sprite, texture_sheet);
}

//Regular functions
void Entity::setPosition(sf::Vector2f pos)
{
	this->sprite.setPosition(pos.x, pos.y);
}

void Entity::setRotation(const float x)
{
	this->sprite.setRotation(x);
}

void Entity::setScale(sf::Vector2f pos)
{
	this->sprite.setScale(pos.x, pos.y);
}

void Entity::setDefaultScale()
{
	this->sprite.setScale(this->defaultScaleX, this->defaultScaleY);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y) 
{
	if (this->movementComponent)
	{
		this->movementComponent->move(dir_x, dir_y); //Sets velovity
		this->sprite.move(this->movementComponent->getVelocity() * dt); //Uses velocity
	}
}

void  Entity::move(const sf::Vector2f& pointA, const sf::Vector2f& pointB, float factor)
{
	if (this->movementComponent)
	{
		sf::Vector2f tmp = this->movementComponent->interpolate(pointA, pointB, factor);
		this->sprite.setPosition(tmp);
	}
}

sf::Sprite* Entity::getSprite() 
{
	return &this->sprite;
}

sf::Vector2f Entity::getScale()
{
	return sf::Vector2f(this->defaultScaleX, this->defaultScaleY);
}

sf::Vector2f Entity::getPosition()
{
	return this->sprite.getPosition();
}




void Entity::update(const float& dt, const sf::Vector2f mousePos)
{
	//Idle
	this->entityState = false;

	//Hover
	if (this->sprite.getGlobalBounds().contains(mousePos))
	{
		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->entityState = true;
		}
	}

}

void Entity::render(sf::RenderTarget* target) 
{
	target->draw(this->sprite);
}