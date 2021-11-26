#include "Textbox.h"


Textbox::Textbox(float x, float y, float width, float height, int fontSize, sf::Font* font, std::string text,
	sf::Color idleColor, sf::Color textColor)
{
	if (fontSize < 2 and fontSize > 100) fontSize = 40;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(textColor);
	this->text.setCharacterSize(fontSize);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;

	this->shape.setFillColor(this->idleColor);
}

Textbox::~Textbox() 
{
}



//Accessors
//const bool isPressed() const;

//Functions
void Textbox::update(const sf::Vector2f mousePos)
{

}

void Textbox::render(sf::RenderTarget* target)
{
	//target->draw(this->shape);
	target->draw(this->text);
}

void Textbox::setText(std::string text)
{
	this->text.setString(text);
}

void Textbox::setFillColor(sf::Color textColor)
{
	this->text.setFillColor(textColor);
}