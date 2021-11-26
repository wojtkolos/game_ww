#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color readyColor, sf::Color blockColor)
{
	this->buttonState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
	this->readyColor = readyColor;
	this->blockColor = blockColor;

	this->blocked = false;
	this->active = false;
	this->hover = false;

	this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{
	
}

//Accessors
const bool Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;
	return false;
}

const bool Button::isBlocked() const
{
	return this->blocked;
}

const bool Button::isActive() const
{
	return this->active;
}

//Functions
void Button::changeState()
{
	this->blocked = (this->blocked) ? false : true;
	this->active = (this->blocked) ? false : true;
}

void Button::setBlocked(bool t)
{
	this->blocked = t;
}

void Button::setHover(bool t)
{
	this->hover = t;
}

void Button::setActive(bool t)
{
	this->active = t;
}

void Button::setText(std::string text)
{
	this->text.setString(text);
}

void Button::setColor(unsigned short toSet)
{
	switch (toSet)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;

	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;
	case  BTN_READY:
		this->shape.setFillColor(this->readyColor);
		break;
	case  BTN_BLOCK:
		this->shape.setFillColor(this->blockColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::update(const sf::Vector2f mousePos)
{
	//Update the booleans for hover and pressed

	//Idle
	this->buttonState = BTN_IDLE;

	//Hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}
	if (blocked == true)
		setColor(4);
	else
	{
		switch (this->buttonState)
		{
		case BTN_IDLE:
			if (active == true)
				setColor(3);
			else if (hover == true)
				setColor(1);
			else
				setColor(0);
			break;

		case BTN_HOVER:
			setColor(1);
			break;

		case BTN_ACTIVE:
			setColor(2);
			break;

		default:
			this->shape.setFillColor(sf::Color::Red);
			break;
		}
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}