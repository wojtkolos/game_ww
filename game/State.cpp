#include"State.h"


State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Event* sfEvent)
{
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->states = states;
	this->sfEvent = sfEvent;
	this->quit = false;
	this->paused = false;

	this->keytime = 0.f;
	this->keytimeMax = 10.f;

	this->music = new sf::Music;
}

State::~State() 
{
}

const bool& State::getQuit() const {
	return this->quit;
}

const bool State::getKeytime()
{
	if (this->keytime >= this->keytimeMax) {
		this->keytime = 0.f;
		return true;
	}
	return false;
}

void State::setMusicVolume(int volume)
{
	if(volume >= 0 and volume <=100)
		this->music->setVolume(volume);
}

int State::getMusicVolume()
{
	return this->music->getVolume();
}

void State::pauseMusic()
{
	this->music->pause();
}

void State::unpauseMusic()
{
	this->music->play();
}

void State::pauseState()
{
	this->paused = true;
}

void State::unpauseState()
{
	this->paused = false;
}

void State::endState()
{
	this->quit = true;
}

void State::updateMousePositions() 
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::updateKeytime(const float& dt)
{
	if (this->keytime < this->keytimeMax)
		this->keytime += 110.f * dt;
}

