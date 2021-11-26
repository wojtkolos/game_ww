#include "Game.h"

//Static functions

//Initializer functions
void Game::initVariables() 
{
	this->window = nullptr;
	this->fullscreen = false;
	this->dt = 0;
}


void Game::initWindow()
{
	//Creates a SFML window using .ini
	std::ifstream ifs("Config/window.ini");
	this->videoModes = sf::VideoMode::getFullscreenModes();

	std::string title = "None";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	bool fullscreen = false;
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	unsigned antialiasing_level = 0;

	if (ifs.is_open()) 
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
		ifs >> antialiasing_level;
	}

	ifs.close();

	
	this->fullscreen = false;
	windowSettins.antialiasingLevel = antialiasing_level;

	if (fullscreen)
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen , windowSettins);
	else
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, windowSettins);
		
	this->window->setFramerateLimit(framerate_limit);
	this->window->setKeyRepeatEnabled(false);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys()
{
	std::ifstream ifs("Config/supported_keys.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;
		while (ifs >> key >> key_value) 
		{
			this->supportedKeys[key] = key_value;
		}
	}
	else
	{
		this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
		this->supportedKeys["A"] = sf::Keyboard::Key::A;
		this->supportedKeys["D"] = sf::Keyboard::Key::D;
		this->supportedKeys["W"] = sf::Keyboard::Key::W;
		this->supportedKeys["S"] = sf::Keyboard::Key::S;
	}
	//DEBUG
	for (auto i : this->supportedKeys)
	{
		std::cout << i.first << " " << i.second << "\n";
	}
}

void Game::initStates() 
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states, &this->sfEvent));
}


//Constructors/Destructors
Game::Game() 
{
	this->initVariables();
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Game::~Game() 
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

//Functions
//sf::Clock Game::getDtClock()
//{
//	
//}


//Regular
void Game::endApplication()
{
	std::cout << "Ending app" << "\n";
}

//Update
void Game::updateDt()
{
	//Updates the dt variable with the time it takes to update and render one frame
	this->dt = this->dtClock.restart().asSeconds();

	system("cls");
	//std::cout << this->dt << "\n";
}

void Game::updateSFMLEvents() 
{
    while (this->window->pollEvent(this->sfEvent)) 
	{
        if (this->sfEvent.type == sf::Event::Closed)
		{
            this->window->close();
        }


    }
}

void Game::update() 
{
	this->updateSFMLEvents();

	if (!this->states.empty()) 
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) 
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//App end
	else 
	{
		this->endApplication();
		this->window->close();
	}
}

//Render
void Game::render() 
{
	this->window->clear();

	//Render items
	if (!this->states.empty())
		this->states.top()->render(this->window);


	this->window->display();
}

//Core
void Game::run() 
{
    while (this->window->isOpen()) 
	{
		this->updateDt();
		this->update();
		this->render();
    }
}