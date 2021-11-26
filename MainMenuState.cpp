#include "MainMenuState.h"



//Init functions
void MainMenuState::initVariables()
{
	this->selectedIndex = 0;
}
void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	if (!this->backgroundTexture.loadFromFile("Recources/Images/Backgrounds/bg2.png")) 
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initMusic()
{
	if (!this->music->openFromFile("Recources/Music/Background/background_main.wav"))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_MUSIC";
	}
	this->music->setVolume(40);
	this->music->setLoop(true);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Roboto-Black.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeyBinds()
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
		this->keyBinds["ENTER"] = this->supportedKeys->at("Enter");
		this->keyBinds["EXIT"] = this->supportedKeys->at("Escape");
		this->keyBinds["MOVE_UP"] = this->supportedKeys->at("W");
		this->keyBinds["MOVE_DOWN"] = this->supportedKeys->at("S");
		this->keyBinds["MOVE_ARROW_UP"] = this->supportedKeys->at("Up");
		this->keyBinds["MOVE_ARROW_DOWN"] = this->supportedKeys->at("Down");
	}
}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(715, 200, 150, 50,
		&this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["ONLINE_STATE"] = new Button(715, 300, 150, 50,
		&this->font, "Online - no active yet",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["SETTINGS"] = new Button(715, 400, 150, 50,
		&this->font, "Settings",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["EXIT_STATE"] = new Button(715, 500, 150, 50,
		&this->font, "Quit",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(153, 206, 143), sf::Color(245, 80, 76));

	this->buttons["GAME_STATE"]->setHover(true);

}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Event* sfEvent)
	: State(window, supportedKeys, states, sfEvent)
{
	this->initVariables();
	this->initBackground();
	this->initMusic();
	this->initFonts();
	this->initKeyBinds();
	this->initButtons();

	this->music->play();
}


MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (; it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

//Functions
void MainMenuState::moveUp()
{

	switch (this->selectedIndex)
	{
	case 1:
		this->buttons["SETTINGS"]->setHover(false);
		this->selectedIndex--;
		this->buttons["GAME_STATE"]->setHover(true);
		break;
	case 2:
		this->buttons["EXIT_STATE"]->setHover(false);
		this->selectedIndex--;
		this->buttons["SETTINGS"]->setHover(true);
		break;
	default:
		break;
	}
}

void MainMenuState::moveDown()
{

	switch (this->selectedIndex)
	{
	case 0:
		this->buttons["GAME_STATE"]->setHover(false);
		this->selectedIndex++;
		this->buttons["SETTINGS"]->setHover(true);
		break;
	case 1:
		this->buttons["SETTINGS"]->setHover(false);
		this->selectedIndex++;
		this->buttons["EXIT_STATE"]->setHover(true);
		break;
	default:
		break;
	}
}

void MainMenuState::updateInput(const float& dt)
{

	if (this->getKeytime()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_ARROW_UP"))))
			this->moveUp();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_ARROW_DOWN"))))
			this->moveDown();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("ENTER"))))
		{
			switch (this->selectedIndex)
			{
			case 0: //GameState
				this->states->push(new GameSetState(this->window, this->supportedKeys, this->states, this->background, this->font, this->sfEvent, this->music));
				break;
			case 1:	//Options
				this->states->push(new OptionsState(this->window, this->supportedKeys, this->states, this->background, this->font, this->sfEvent));
				break;
			case 2:	//Quit the game
				this->endState();
				break;
			default:
				break;
			}
		}
	}
}

void MainMenuState::updateButtons()
{
	
	//Updates all the buttons in the state and handles their functionality.
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//New game
	if (this->buttons["GAME_STATE"]->isPressed()) {
		this->states->push(new GameSetState(this->window, this->supportedKeys, this->states, this->background, this->font, this->sfEvent, this->music));
	}
	//Options
	if (this->buttons["SETTINGS"]->isPressed())
		this->states->push(new OptionsState(this->window, this->supportedKeys, this->states, this->background, this->font, this->sfEvent));
	//Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed()) {
		this->music->stop();
		this->endState();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeytime(dt);
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);

	//TO REMOVE LATER!! this is for get position to place buttons
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	
	target->draw(mouseText);
}

