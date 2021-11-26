#include "OptionsState.h"


//Init functions
void OptionsState::initBackground()
{
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	if (!this->backgroundTexture.loadFromFile("Recources/Images/Backgrounds/bg2.png"))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->backgroundTexture);
}

void OptionsState::initKeyBinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
		{
			this->keyBinds[key] = this->supportedKeys->at(key2);
		}
	}
	else
	{
		this->keyBinds["CLOSE"] = this->supportedKeys->at("Escape");
		this->keyBinds["MOVE_UP"] = this->supportedKeys->at("W");
		this->keyBinds["MOVE_DOWN"] = this->supportedKeys->at("S");
	}
}

void OptionsState::initButtons()
{
	this->buttons["UNKNOWN"] = new Button(715, 200, 150, 50,
		&this->font, "Nic tu jeszcze nie ma",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));



	this->buttons["BACK_STATE"] = new Button(715, 400, 150, 50,
		&this->font, "Back",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

}


OptionsState::OptionsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::RectangleShape& background, sf::Font& font, sf::Event* sfEvent)
	: State(window, supportedKeys, states, sfEvent)
{
	this->font = font;
	this->background = background;
	//this->initKeyBinds(); no needed - in mainmenu same
	this->initBackground();
	this->initButtons();
	this->initKeyBinds();
}

OptionsState::~OptionsState()
{
	auto it = this->buttons.begin();
	for (; it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

//Functions
void OptionsState::updateInput(const float& dt)
{
	if (this->getKeytime()) {
		//this->checkForQuit();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))))
			this->endState();
	}
}

void OptionsState::updateButtons()
{

	//Updates all the buttons in the state and handles their functionality.
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	
	//Quit the game
	if (this->buttons["BACK_STATE"]->isPressed())
		this->endState();
}

void OptionsState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeytime(dt);
	this->updateInput(dt);

	this->updateButtons();
}

void OptionsState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void OptionsState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);
}

