#include "DialogBox.h"

void DialogBox::initVariables()
{
	this->confirm = false;
	this->cancel = false;
	this->active = false;
	this->paused = false;
	//this->id = 0;
}

void DialogBox::initButtons(std::string textButtonYES, std::string textButtonNO)
{
	this->buttons["YES"] = new Button(715, 330, 150, 50,
		this->font, textButtonYES,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	this->buttons["NO"] = new Button(715, 400, 150, 50,
		this->font, textButtonNO,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
}

void DialogBox::initButton()
{
	this->buttons["YES"] = new Button(715, 365, 150, 50,
		this->font, "OK",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
}


DialogBox::DialogBox(sf::Font* font, std::string text, std::string textButtonYES, std::string textButtonNO)
{
	this->font = font;
	this->initVariables();
	this->initButtons(textButtonYES, textButtonNO);

	this->background.setSize(sf::Vector2f(400, 250));
	this->background.setFillColor(sf::Color(0, 0, 0, 200));
	this->background.setPosition(590, 250);

	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setCharacterSize(20);
	this->text.setFillColor(sf::Color::Red);
	//this->text.setPosition(sf::Vector2f(690, 265));

	this->text.setPosition(this->background.getPosition().x + this->background.getSize().x / 2.f - this->text.getGlobalBounds().width / 2.f,
		this->background.getPosition().y + 15.f);
}



DialogBox::~DialogBox()
{
	auto it = this->buttons.begin();
	for (; it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

bool DialogBox::isConfirm()
{
	return this->confirm;
}

bool DialogBox::isCancel()
{
	return this->cancel;
}

void DialogBox::updateButtons(const sf::Vector2f mousePosView)
{
	//Updates all the buttons in the state and handles their functionality.
	for (auto& it : this->buttons)
	{
		it.second->update(mousePosView);
	}
	if (this->buttons["YES"]->isPressed())
		this->confirm = true;
	if (this->buttons["NO"]->isPressed())
		this->cancel = true;
}

bool DialogBox::isActive()
{
	return this->active;
}

void DialogBox::setActive(bool state)
{
	this->active = state;
}

void DialogBox::resetState()
{
	this->active = false;
	this->confirm = false;
	this->cancel = false;
}

//void DialogBox::setId(unsigned short id)
//{
//	this->id = id;
//}
//
//unsigned short DialogBox::getId()
//{
//	return this->id;
//}

void DialogBox::update(const sf::Vector2f mousePos)
{
	this->updateButtons(mousePos);
}

void DialogBox::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void DialogBox::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	target->draw(this->text);
	this->renderButtons(target);
	
}