#include "Trade.h"

void Trade::initVariables()
{
	this->user_source = -1;
	this->user_destination = -1;
	this->space = nullptr;
	this->propose_value = 0;

	this->active = false;
	this->confirm = false;
	this->cancel = false;
}

void Trade::initRowOfButtons(float x, float y, int val)
{
	int button_size_x = 50, button_size_y = 50;
	//1
	this->buttons[std::to_string(val)] = new Button(x, y, button_size_x, button_size_y,
		this->font, std::to_string(val),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	//2
	this->buttons[std::to_string(2 * val)] = new Button(x + button_size_x, y, button_size_x, button_size_y,
		this->font, std::to_string(2 * val),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	//3
	this->buttons[std::to_string(3 * val)] = new Button(x + 2 * button_size_x, y, button_size_x, button_size_y,
		this->font, std::to_string(3 * val),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	//4
	this->buttons[std::to_string(4 * val)] = new Button(x + 3 * button_size_x, y, button_size_x, button_size_y,
		this->font, std::to_string(4 * val),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	//5
	this->buttons[std::to_string(5 * val)] = new Button(x + 4 * button_size_x, y, button_size_x, button_size_y,
		this->font, std::to_string(5 * val),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	//6
	this->buttons[std::to_string(6 * val)] = new Button(x + 5 * button_size_x, y, button_size_x, button_size_y,
		this->font, std::to_string(6 * val),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	//7
	this->buttons[std::to_string(7 * val)] = new Button(x + 6 * button_size_x, y, button_size_x, button_size_y,
		this->font, std::to_string(7 * val),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	//8
	this->buttons[std::to_string(8 * val)] = new Button(x + 7 * button_size_x, y, button_size_x, button_size_y,
		this->font, std::to_string(8 * val),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	//9
	this->buttons[std::to_string(9 * val)] = new Button(x + 8 * button_size_x, y, button_size_x, button_size_y,
		this->font, std::to_string(9 * val),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
}


void Trade::initButtons(float pos_x)
{
	this->buttons["YES"] = new Button(pos_x - 150 / 2.f - 85, 550, 150, 50,
		this->font, "Send Offer",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
	this->buttons["NO"] = new Button(pos_x - 150 / 2.f + 85, 550, 150, 50,
		this->font, "Cancel Offer",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->initRowOfButtons(pos_x - 450 / 2.f, 330, 100);
	this->initRowOfButtons(pos_x - 450 / 2.f, 380, 10);
	this->initRowOfButtons(pos_x - 450 / 2.f, 430, 1);
}


Trade::Trade(sf::Font* font)
{
	this->font = font;
	this->initVariables();

	this->background.setSize(sf::Vector2f(500, 400));
	this->background.setFillColor(sf::Color(0, 0, 0, 200));
	this->background.setPosition(390, 250);

	this->text.setFont(*this->font);
	this->text.setString("Your propose");
	this->text.setCharacterSize(20);
	this->text.setFillColor(sf::Color::Red);
	this->text.setPosition(this->background.getPosition().x + this->background.getSize().x / 2.f - this->text.getGlobalBounds().width / 2.f,
		this->background.getPosition().y + 15.f);


	this->value_text.setFont(*this->font);
	this->value_text.setString("0");
	this->value_text.setCharacterSize(20);
	this->value_text.setFillColor(sf::Color::Red);
	this->value_text.setPosition(this->background.getPosition().x + this->background.getSize().x / 2.f - this->value_text.getGlobalBounds().width / 2.f,
		this->background.getPosition().y + 45.f);

	this->initButtons(this->background.getPosition().x + this->background.getSize().x / 2.f);
}

Trade::~Trade()
{
	auto it = this->buttons.begin();
	for (; it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

bool Trade::isConfirm()
{
	return this->confirm;
}

bool Trade::isCancel()
{
	return this->cancel;
}

bool Trade::isActive()
{
	return this->active;
}


void Trade::setActive(bool state)
{
	this->active = state;
}

void Trade::priceButtonsActionCheck()
{
	this->rowButtonActionCheck(100);
	this->rowButtonActionCheck(10);
	this->rowButtonActionCheck(1);
}

void Trade::rowButtonActionCheck(int val)
{
	if (this->buttons[std::to_string(val)]->isPressed()) {
		this->buttons[std::to_string(val)]->setActive((this->buttons[std::to_string(val)]->isActive()) ? false : true);
		(this->buttons[std::to_string(val)]->isActive()) ? this->buttonAddValue(val) : this->buttonOddValue(val);
	}
	if (this->buttons[std::to_string(2 * val)]->isPressed()) {
		this->buttons[std::to_string(2 * val)]->setActive((this->buttons[std::to_string(2 * val)]->isActive()) ? false : true);
		(this->buttons[std::to_string(2 * val)]->isActive()) ? this->buttonAddValue(2 * val) : this->buttonOddValue(2 * val);
	}
	if (this->buttons[std::to_string(3 * val)]->isPressed()) {
		this->buttons[std::to_string(3 * val)]->setActive((this->buttons[std::to_string(3 * val)]->isActive()) ? false : true);
		(this->buttons[std::to_string(3 * val)]->isActive()) ? this->buttonAddValue(3 * val) : this->buttonOddValue(3 * val);
	}
	if (this->buttons[std::to_string(4 * val)]->isPressed()) {
		this->buttons[std::to_string(4 * val)]->setActive((this->buttons[std::to_string(4 * val)]->isActive()) ? false : true);
		(this->buttons[std::to_string(4 * val)]->isActive()) ? this->buttonAddValue(4 * val) : this->buttonOddValue(4 * val);
	}
	if (this->buttons[std::to_string(5 * val)]->isPressed()) {
		this->buttons[std::to_string(5 * val)]->setActive((this->buttons[std::to_string(5 * val)]->isActive()) ? false : true);
		(this->buttons[std::to_string(5 * val)]->isActive()) ? this->buttonAddValue(5 * val) : this->buttonOddValue(5 * val);
	}
	if (this->buttons[std::to_string(6 * val)]->isPressed()) {
		this->buttons[std::to_string(6 * val)]->setActive((this->buttons[std::to_string(6 * val)]->isActive()) ? false : true);
		(this->buttons[std::to_string(6 * val)]->isActive()) ? this->buttonAddValue(6 * val) : this->buttonOddValue(6 * val);
	}
	if (this->buttons[std::to_string(7 * val)]->isPressed()) {
		this->buttons[std::to_string(7 * val)]->setActive((this->buttons[std::to_string(7 * val)]->isActive()) ? false : true);
		(this->buttons[std::to_string(7 * val)]->isActive()) ? this->buttonAddValue(7 * val) : this->buttonOddValue(7 * val);
	}
	if (this->buttons[std::to_string(8 * val)]->isPressed()) {
		this->buttons[std::to_string(8 * val)]->setActive((this->buttons[std::to_string(8 * val)]->isActive()) ? false : true);
		(this->buttons[std::to_string(8 * val)]->isActive()) ? this->buttonAddValue(8 * val) : this->buttonOddValue(8 * val);
	}
	if (this->buttons[std::to_string(9 * val)]->isPressed()) {
		this->buttons[std::to_string(9 * val)]->setActive((this->buttons[std::to_string(9 * val)]->isActive()) ? false : true);
		(this->buttons[std::to_string(9 * val)]->isActive()) ? this->buttonAddValue(9 * val) : this->buttonOddValue(9 * val);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
}

void Trade::buttonAddValue(int val)
{
	this->propose_value += val;
}

void Trade::buttonOddValue(int val)
{
	this->propose_value -= val;
}


void Trade::updateButtons(const sf::Vector2f mousePosView)
{
	//Updates all the buttons in the state and handles their functionality.
	for (auto& it : this->buttons)
	{
		it.second->update(mousePosView);
	}

	std::thread first([this] {priceButtonsActionCheck();  });
	first.join();

	if (this->buttons["YES"]->isPressed()) {
		this->confirm = true;
		this->active = false;
	}
	if (this->buttons["NO"]->isPressed()) {
		this->cancel = true;
		this->active = false;
	}
}

void Trade::resetState()
{
	this->confirm = false;
	this->cancel = false;
}

void Trade::setUserSource(short usr)
{
	this->user_source = usr;
}

void Trade::setUserDestination(short usr)
{
	this->user_destination = usr;
}

void Trade::setPoposeValue(int value)
{
	this->propose_value = value;
}

void Trade::setSpace(Space* space)
{
	this->space = space;
}

void Trade::setTradeParameters(short usr_s, short usr_d, Space* space)
{
	this->user_source = usr_s;
	this->user_destination = usr_d;
	this->space = space;
	this->active = true;
}

short Trade::getUserSource()
{
	return this->user_source;
}

short Trade::getUserDestination()
{
	return this->user_destination;
}

int Trade::getPoposeValue()
{
	return this->propose_value;
}

Space* Trade::getSpace()
{
	return this->space;
}


void Trade::update(const sf::Vector2f mousePos)
{
	this->value_text.setString(std::to_string(this->propose_value));
	this->updateButtons(mousePos);
}

void Trade::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void Trade::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	target->draw(this->text);
	target->draw(this->value_text);
	this->renderButtons(target);

}
