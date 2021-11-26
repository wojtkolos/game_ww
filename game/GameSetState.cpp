#include "GameSetState.h"


//Init functions
void GameSetState::initKeyBinds()
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

void GameSetState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(715, 200, 150, 50,
		&this->font, "Start",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	
	this->buttons["PLAYERS2"] = new Button(715, 300, 40, 50,
		&this->font, "2",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["PLAYERS3"] = new Button(770, 300, 40, 50,
		&this->font, "3",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["PLAYERS4"] = new Button(825, 300, 40, 50,
		&this->font, "4",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["BACK_STATE"] = new Button(715, 400, 150, 50,
		&this->font, "Back",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

}


GameSetState::GameSetState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::RectangleShape& background, sf::Font& font, sf::Event* sfEvent, sf::Music* music)
	: State(window, supportedKeys, states, sfEvent)
{
	this->music = music;
	this->font = font;
	this->background = background;
	//this->initKeyBinds(); no needed - in mainmenu same
	this->initButtons();
}

GameSetState::~GameSetState()
{
	auto it = this->buttons.begin();
	for (; it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

//Functions
void GameSetState::updateInput(const float& dt)
{
	//this->checkForQuit();
}

void GameSetState::updateButtons()
{
	
	//Updates all the buttons in the state and handles their functionality.
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//New game
	(this->number_of_players < 2)?
		this->buttons["GAME_STATE"]->setBlocked(true) 
		: this->buttons["GAME_STATE"]->setBlocked(false);

	if (this->buttons["GAME_STATE"]->isPressed() && this->number_of_players >= 2)
		this->states->push(new GameState(this->window, this->supportedKeys, this->states, number_of_players, this->font, this->sfEvent, this->music));
	//2 Players
	if (this->buttons["PLAYERS2"]->isPressed()) {
		this->number_of_players = 2;
		this->buttons["PLAYERS2"]->setActive(true);
		this->buttons["PLAYERS3"]->setActive(false);
		this->buttons["PLAYERS4"]->setActive(false);
	}
	//3 Players
	if (this->buttons["PLAYERS3"]->isPressed()) {
		this->number_of_players = 3;
		this->buttons["PLAYERS2"]->setActive(false);
		this->buttons["PLAYERS3"]->setActive(true);
		this->buttons["PLAYERS4"]->setActive(false);
	}
	//4 Players
	if (this->buttons["PLAYERS4"]->isPressed()) {
		this->number_of_players = 4;
		this->buttons["PLAYERS2"]->setActive(false);
		this->buttons["PLAYERS3"]->setActive(false);
		this->buttons["PLAYERS4"]->setActive(true);
	}
	//Quit the game
	if (this->buttons["BACK_STATE"]->isPressed())
		this->endState();
}

void GameSetState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeytime(dt);
	this->updateInput(dt);

	this->updateButtons();
}

void GameSetState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void GameSetState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);
}

