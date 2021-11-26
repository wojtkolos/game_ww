#include "CounterTrade.h"
#include "Space.h"

void CounterTrade::initVariables()
{
	this->user_source = -1;
	this->user_destination = -1;
	this->space = nullptr;
	this->propose_value = 0;


	this->confirm = false;
	this->cancel = false;
	this->active = false;
}

void CounterTrade::initButtons(float pos_x)
{
	this->buttons["YES"] = new Button(pos_x - 150 / 2.f - 85, 550, 150, 50,
		this->font, "Accept Offer",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	this->buttons["NO"] = new Button(pos_x - 150 / 2.f + 85, 550, 150, 50,
		this->font, "Regret Offer",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
}

CounterTrade::CounterTrade(sf::Font* font)
{
	this->font = font;
	this->initVariables();

	this->background.setSize(sf::Vector2f(500, 400));
	this->background.setFillColor(sf::Color(0, 0, 0, 200));
	this->background.setPosition(390, 250);

	this->text.setFont(*this->font);
	this->text.setString("Player ID propose");
	this->text.setCharacterSize(20);
	this->text.setFillColor(sf::Color::Red);
	this->text.setPosition(this->background.getPosition().x + this->background.getSize().x / 2.f - this->text.getGlobalBounds().width / 2.f,
		this->background.getPosition().y + 15.f);


	this->value_text.setFont(*this->font);
	this->value_text.setString("000");
	this->value_text.setCharacterSize(20);
	this->value_text.setFillColor(sf::Color::Red);
	this->value_text.setPosition(this->background.getPosition().x + this->background.getSize().x / 2.f - this->value_text.getGlobalBounds().width / 2.f,
		this->background.getPosition().y + 45.f);

	this->space_name.setFont(*this->font);
	this->space_name.setString("");
	this->space_name.setCharacterSize(20);
	this->space_name.setFillColor(sf::Color::White);
	this->space_name.setPosition(this->background.getPosition().x + this->background.getSize().x / 2.f - this->space_name.getGlobalBounds().width / 2.f,
		this->background.getPosition().y + 105.f);

	this->initButtons(this->background.getPosition().x + this->background.getSize().x / 2.f);
}

CounterTrade::~CounterTrade()
{
	auto it = this->buttons.begin();
	for (; it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

bool CounterTrade::isConfirm()
{
	return this->confirm;
}

bool CounterTrade::isCancel()
{
	return this->cancel;
}

bool CounterTrade::isActive()
{
	return this->active;
}


void CounterTrade::setActive(bool state)
{
	this->active = state;
}


void CounterTrade::updateButtons(const sf::Vector2f mousePosView)
{
	//Updates all the buttons in the state and handles their functionality.
	for (auto& it : this->buttons)
	{
		it.second->update(mousePosView);
	}

	if (this->buttons["YES"]->isPressed()) {
		this->confirm = true;
		this->active = false;
	}
	if (this->buttons["NO"]->isPressed()) {
		this->cancel = true;
		this->active = false;
	}
}

void CounterTrade::resetState()
{
	this->confirm = false;
	this->cancel = false;
}

void CounterTrade::setUserSource(short usr)
{
	this->user_source = usr;
}

void CounterTrade::setUserDestination(short usr)
{
	this->user_destination = usr;
}

void CounterTrade::setPoposeValue(int value)
{
	this->propose_value = value;
}

void CounterTrade::setSpace(Space* space)
{
	this->space = space;
}

void CounterTrade::setTradeParameters(short usr_s, short usr_d, Space* space)
{
	this->user_source = usr_s;
	this->user_destination = usr_d;
	this->space = space;	
	this->active = true;
}

short CounterTrade::getUserSource()
{
	return this->user_source;
}

short CounterTrade::getUserDestination()
{
	return this->user_destination;
}

int CounterTrade::getPoposeValue()
{
	return this->propose_value;
}

Space* CounterTrade::getSpace()
{
	return this->space;
}

void CounterTrade::update(const sf::Vector2f mousePos)
{
	this->value_text.setString(std::to_string(this->propose_value));
	this->text.setString("Player " + std::to_string(this->user_source + 1) + " propose");

	this->space_name.setString("Space: " + this->space->getName(0) + " " + this->space->getName(1));
	this->space_name.setPosition(this->background.getPosition().x + this->background.getSize().x / 2.f - this->space_name.getGlobalBounds().width / 2.f,
		this->background.getPosition().y + 105.f);
	this->updateButtons(mousePos);
}

void CounterTrade::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void CounterTrade::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	target->draw(this->text);
	target->draw(this->value_text);
	target->draw(this->space_name);
	this->renderButtons(target);

}
