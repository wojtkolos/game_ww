#include "dice.h"

//Init components
void Dice::initVariables(float x, float y)
{
	this->sides = 6;
	this->createSprite(texture, sf::Vector2f(x, y));
	this->setPosition(sf::Vector2f(x, y));
	this->setScale(sf::Vector2f(0.1f, 0.1f));
	dice = new sf::RectangleShape(sf::Vector2f(384.0f, 448.0f));
	dice->setPosition(x, y);
	dice->setTexture(&texture);
	
}

void Dice::initTextures()
{
	if (!this->texture.loadFromFile("Recources/Images/Sprites/Dice/dice_sheet.png"))
		throw "ERROR::DICE::COULD_NOT_LOAD_DICE_TEXTURE";
}

void Dice::initComponents()
{
	this->dice_animation = new DiceAnimation(dice, sf::Vector2u(6, 7), 0.01f);
	this->dice->setScale(0.1f, 0.1f);
	//this->createAnimationComponent(this->texture);
}

//Constructors / Destructors
Dice::Dice(float x, float y)
{
	this->initTextures();
	this->initVariables(x, y);
	this->initComponents();
	this->dice_animation->update(0.1f);
	this->dice->setTextureRect(dice_animation->uvRect);
	//this->animationComponent->addAnimation("IDLE_LEFT", 100.0f, 0, 0, 20, 0, 64, 64);
}

Dice::~Dice() 
{
	//delete dice_animation;
	delete dice;
}

void Dice::update(const float& dt, const sf::Vector2f mousePos)
{
	this->Entity::update(dt, mousePos);
}


void Dice::render(sf::RenderTarget* target)
{
	if (this->dice)
		target->draw(*this->dice);
}

int Dice::rollDice(const float& dt) {
	int roll = 0;
	roll = randomGenerator();

	this->dice_animation->setFrame(roll, dt);
	this->dice->setTextureRect(dice_animation->uvRect);

	return roll;
}


int Dice::randomGenerator()
{
	std::default_random_engine eng;
	std::uniform_int_distribution<unsigned int> dist(1, 6);
	eng.seed(std::chrono::steady_clock::now().time_since_epoch().count());
	return dist(eng);
}