#include "PauseMenu.h"
#include "State.h"

void PauseMenu::initButtons()
{
	float width = 250.f;
	float height = 50.f;
	float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;

	this->buttons["RESUME"] = new Button(x, 200, width, height,
		&this->font, "Resume",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["VOLUME_10"] = new Button(x + 5.f, 400, width/5 - 10.f, height,
		&this->font, "10",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["VOLUME_20"] = new Button(x + 55.f, 400, width / 5 - 10.f, height,
		&this->font, "20",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["VOLUME_30"] = new Button(x + 105.f, 400, width / 5 - 10.f, height,
		&this->font, "30",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["VOLUME_40"] = new Button(x + 155.f, 400, width / 5 - 10.f, height,
		&this->font, "40",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["VOLUME_50"] = new Button(x + 205.f, 400, width / 5 - 10.f, height,
		&this->font, "50",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["VOLUME_MUTE"] = new Button(x, 460, width, height,
		&this->font, "MUTE",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["BACK_STATE"] = new Button(x, 800, width, height,
		&this->font, "Back",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));
}

void PauseMenu::initTextMenu()
{
	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(40);
	this->menuText.setString("PAUSED");
	this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + 40.f);


	this->volumeText.setFont(font);
	this->volumeText.setFillColor(sf::Color(255, 255, 255, 200));
	this->volumeText.setCharacterSize(20);
	this->volumeText.setString("---------\nVOLUME\n---------");
	this->volumeText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->volumeText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + 250.f);
}

PauseMenu::PauseMenu(sf::RenderWindow& window, sf::Font& font, State* parentState)
	:font(font)
{
	this->backgrund.setSize(sf::Vector2f(
			static_cast<float>(window.getSize().x),
			static_cast<float>(window.getSize().y)
		)
	);
	this->backgrund.setFillColor(sf::Color(20, 20, 20, 100));

	this->container.setSize(sf::Vector2f(
			static_cast<float>(window.getSize().x)/4.f,
			static_cast<float>(window.getSize().y - 100.f)
		)
	);
	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition(
		static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f,
		30.f);

	
	this->initTextMenu();
	this->initButtons();

	this->parentState = parentState;
}

PauseMenu::~PauseMenu()
{
	auto it = this->buttons.begin();
	for (; it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

//functions
const bool PauseMenu::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}

void PauseMenu::musicVolumeButtonsColor()
{
	switch (this->parentState->getMusicVolume())
	{
	case 0:
		this->buttons["VOLUME_MUTE"]->setActive(true);
		this->buttons["VOLUME_10"]->setActive(false);
		this->buttons["VOLUME_20"]->setActive(false);
		this->buttons["VOLUME_30"]->setActive(false);
		this->buttons["VOLUME_40"]->setActive(false);
		this->buttons["VOLUME_50"]->setActive(false);
		break;
	case 10-1:
		this->buttons["VOLUME_MUTE"]->setActive(false);
		this->buttons["VOLUME_10"]->setActive(true);
		this->buttons["VOLUME_20"]->setActive(false);
		this->buttons["VOLUME_30"]->setActive(false);
		this->buttons["VOLUME_40"]->setActive(false);
		this->buttons["VOLUME_50"]->setActive(false);
		break;
	case 20-1:
		this->buttons["VOLUME_MUTE"]->setActive(false);
		this->buttons["VOLUME_10"]->setActive(false);
		this->buttons["VOLUME_20"]->setActive(true);
		this->buttons["VOLUME_30"]->setActive(false);
		this->buttons["VOLUME_40"]->setActive(false);
		this->buttons["VOLUME_50"]->setActive(false);
		break;
	case 30-1:
		this->buttons["VOLUME_MUTE"]->setActive(false);
		this->buttons["VOLUME_10"]->setActive(false);
		this->buttons["VOLUME_20"]->setActive(false);
		this->buttons["VOLUME_30"]->setActive(true);
		this->buttons["VOLUME_40"]->setActive(false);
		this->buttons["VOLUME_50"]->setActive(false);
		break;
	case 40-1:
		this->buttons["VOLUME_MUTE"]->setActive(false);
		this->buttons["VOLUME_10"]->setActive(false);
		this->buttons["VOLUME_20"]->setActive(false);
		this->buttons["VOLUME_30"]->setActive(false);
		this->buttons["VOLUME_40"]->setActive(true);
		this->buttons["VOLUME_50"]->setActive(false);
		break;
	case 50:
		this->buttons["VOLUME_MUTE"]->setActive(false);
		this->buttons["VOLUME_10"]->setActive(false);
		this->buttons["VOLUME_20"]->setActive(false);
		this->buttons["VOLUME_30"]->setActive(false);
		this->buttons["VOLUME_40"]->setActive(false);
		this->buttons["VOLUME_50"]->setActive(true);
		break;
	default:
		break;
	}
}

void PauseMenu::musicVolumeSetButtons()
{
	if (this->buttons["VOLUME_10"]->isPressed())
		this->parentState->setMusicVolume(10);
	if (this->buttons["VOLUME_20"]->isPressed()) 
		this->parentState->setMusicVolume(20);
	if (this->buttons["VOLUME_30"]->isPressed())
		this->parentState->setMusicVolume(30);
	if (this->buttons["VOLUME_40"]->isPressed())
		this->parentState->setMusicVolume(40);
	if (this->buttons["VOLUME_50"]->isPressed())
		this->parentState->setMusicVolume(50);
	if (this->buttons["VOLUME_MUTE"]->isPressed()) {
		if (this->parentState->getMusicVolume() != 0) { this->prev_volume = this->parentState->getMusicVolume(); this->parentState->setMusicVolume(0); }
		else this->parentState->setMusicVolume(this->prev_volume);
	}
}


void PauseMenu::update(const sf::Vector2f mousePos)
{
	for (auto& i : this->buttons)
		i.second->update(mousePos);
	this->musicVolumeSetButtons();
	this->musicVolumeButtonsColor();
}

void PauseMenu::render(sf::RenderTarget& target)
{
	target.draw(this->backgrund);
	target.draw(this->container);

	for (auto& i : this->buttons)
		i.second->render(&target);

	target.draw(this->menuText);
	target.draw(this->volumeText);
}