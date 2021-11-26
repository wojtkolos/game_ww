#include "GameButtons.h"

void GameButtons::initButtons()
{
	this->buttons["ROLL"] = new Button(1103, 880, 150, 50,
		&this->font, "Roll",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["TRADE"] = new Button(1253, 880, 150, 50,
		&this->font, "Trade",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["PRISONEXIT"] = new Button(1403, 880, 150, 50,
		&this->font, "Exit Prison",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["BUY"] = new Button(1103, 950, 150, 50,
		&this->font, "Buy",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["UPGRADE"] = new Button(1253, 950, 150, 50,
		&this->font, "Upgrade",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["ENDTURN"] = new Button(1403, 950, 150, 50,
		&this->font, "End turn",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["PLAYERS1"] = new Button(1100, 1018, 30, 50,
		&this->font, "1",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["PLAYERS2"] = new Button(1143, 1018, 30, 50,
		&this->font, "2",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["PLAYERS3"] = new Button(1176, 1018, 30, 50,
		&this->font, "3",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["PLAYERS4"] = new Button(1209, 1018, 30, 50,
		&this->font, "4",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["RENT_COLLECT"] = new Button(1253, 1018, 150, 50,
		&this->font, "Collect rental fees",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["NULLA"] = new Button(1403, 1018, 150, 50,
		&this->font, "NULLA",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
}

GameButtons::GameButtons(sf::Font& font)
{
	this->font = font;
	this->initButtons();
	this->defaultButtonsStates();
}

GameButtons::~GameButtons()
{
	auto it = this->buttons.begin();
	for (; it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

void GameButtons::defaultButtonsStates()
{
	this->buttons["ROLL"]->setBlocked(0);
	this->buttons["ROLL"]->setActive(1);

	this->buttons["ENDTURN"]->setBlocked(1);
	this->buttons["ENDTURN"]->setActive(0);

	this->buttons["UPGRADE"]->setBlocked(1);
	this->buttons["UPGRADE"]->setActive(0);

	this->buttons["BUY"]->setBlocked(1);
	this->buttons["BUY"]->setActive(0);

	this->buttons["PRISONEXIT"]->setBlocked(true);
	this->buttons["PRISONEXIT"]->setActive(false);

	this->buttons["TRADE"]->setBlocked(true);
	this->buttons["TRADE"]->setActive(false);

	this->buttons["RENT_COLLECT"]->setBlocked(true);
	this->buttons["RENT_COLLECT"]->setActive(false);
}

const bool GameButtons::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}

const bool GameButtons::isButtonBlocked(const std::string key)
{
	return this->buttons[key]->isBlocked();
}

void GameButtons::setButtonBlocked(const std::string key, bool action)
{
	this->buttons[key]->setBlocked(action);
}

void GameButtons::setButtonActive(const std::string key, bool action)
{
	this->buttons[key]->setActive(action);
}


void GameButtons::update(const sf::Vector2f mousePos)
{
	for (auto& i : this->buttons)
		i.second->update(mousePos);
}

void GameButtons::render(sf::RenderTarget* target)
{
	for (auto& i : this->buttons)
		i.second->render(target);
}