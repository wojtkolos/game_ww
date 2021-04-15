#include "Game.h"

//Static functions

//Initializer functions
void Game::initWindow()
{
	//Creates a SFML window using .ini
	std::ifstream ifs("Config/window.ini");

	std::string title = "None";
	sf::VideoMode window_bounds(650, 650);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (ifs.is_open()) 
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	//sf::ContextSettings::
	this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Default | sf::Style::Close);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates() 
{
	this->states.push(new GameState(this->window));
}

//Constructors/Destructors
Game::Game() 
{
	this->initWindow();
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