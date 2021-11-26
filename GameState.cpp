#include "GameState.h"


//Init functions
void GameState::initVariables(unsigned short totalPlayers, sf::Font& font)
{
	this->total_players = totalPlayers;
	this->player_turn = 0;
	this->player_to_go = -1;

	this->dt_freeze = 0;

	this->font = font;

	this->actualPlayer = nullptr;
	
}

void GameState::initBackground()
{
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	if (!this->backgroundTexture.loadFromFile("Recources/Images/Backgrounds/Monopoly_sail1.png"))
	{
		throw"ERROR::GAMESTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);
}

void GameState::initMusic()
{
	if (!this->music->openFromFile("Recources/Music/Background/background.wav"))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_MUSIC";
	}
	this->music->setVolume(40);
	this->music->setLoop(true);
}


void GameState::initKeyBinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");
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
		this->keyBinds["SETTINGS"] = this->supportedKeys->at("Escape");
		this->keyBinds["MOVE_LEFT"] = this->supportedKeys->at("A");
		this->keyBinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
		this->keyBinds["MOVE_UP"] = this->supportedKeys->at("W");
		this->keyBinds["MOVE_DOWN"] = this->supportedKeys->at("S");
	}
}


void GameState::initBoardComponents()
{
	this->players = new GamePlayers(this->textures, this->total_players);
	this->dice = new Dice(590.0f, 400.0f);
	this->dice2 = new Dice(642.0f, 440.0f);
	this->bank = new Bank();
	this->card_deck = new CardDeck();
	this->score_board = new ScoreBoard(this->total_players, this->players->getPlayers(), this->bank, this->player_turn, this->font);
	this->operations = new OperationsComponent(this->bank, this->score_board, this->card_deck, this->total_players);
	this->gameButtons = new GameButtons(font);
	this->boardSpaces = new BoardSpaces();
	this->dialogboxes = new DialogBoxes(font);
	this->spaceActionHandler = new SpaceActionHandler(operations, card_deck, gameButtons, boardSpaces, players, dialogboxes, &player_turn, &player_to_go);
	this->trade_component = new TradeComponent(&font, this->players, this->operations);
	
}

void GameState::initPauseMenu()
{
	this->pmenu = new PauseMenu(*window, font, this);
}

//Constructors / Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, unsigned short totalPlayers, sf::Font& font, sf::Event* sfEvent, sf::Music* music)
	: State(window, supportedKeys, states, sfEvent)
{
	this->menuMusic = music;
	this->menuMusic->stop();
	this->initVariables(totalPlayers, font);
	this->initBackground();
	this->initMusic();
	this->initKeyBinds();
	this->initBoardComponents();
	this->initPauseMenu();
	this->music->play();
}

GameState::~GameState()
{

	delete players;
	delete dice;
	delete dice2;
	delete bank;
	delete operations;
	delete score_board;
	delete card_deck;
	delete gameButtons;
	delete boardSpaces;
}

//Functions
void GameState::updateInput(const float& dt)
{
	if (this->getKeytime()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("SETTINGS")))) {
			if (!this->paused)
				this->pauseState();
			else if(!this->dialogboxes->isBoxActive("EXIT"))
				this->unpauseState();
		}
	}
}

void GameState::updatePlayerInput(const float& dt)
{
	//this->checkForQuit();

	//Update Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT")))) {
		//actualPlayer->move(dt, -3.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT")))) {
		//actualPlayer->move(dt, 3.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP")))) {
		//actualPlayer->move(dt, 0.f, -3.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN")))) {
		//actualPlayer->move(dt, 0.f, 3.f);
	}
}

void GameState::updateButtons(const float& dt)
{
	//Updates all the buttons in the state and handles their functionality.
	this->gameButtons->update(mousePosView);

	if (this->gameButtons->isButtonPressed("ROLL") or this->dice->isPressed() or this->dice2->isPressed())
	{
		if (!this->actualPlayer->getDiced()) {
			short roll = this->dice->rollDice(dt);
			short roll2 = this->dice2->rollDice(dt);

			if (!this->actualPlayer->getJailed()) {
				this->player_to_go = roll + roll2;
				actualPlayer->setDiced(true);
				this->gameButtons->setButtonBlocked("ROLL", true);
			}
			else if (roll == roll2 and this->actualPlayer->getJailed()) {
				this->actualPlayer->setJailed(false);
				this->gameButtons->setButtonActive("PRISONEXIT", false);
				this->gameButtons->setButtonBlocked("PRISONEXIT", true);
				actualPlayer->setDiced(true);
				this->gameButtons->setButtonBlocked("ROLL", true);
			}
			else if (roll != roll2 and this->actualPlayer->getJailed()) {
				actualPlayer->setDiced(true);
				this->gameButtons->setButtonBlocked("ROLL", true);
				this->gameButtons->setButtonActive("PRISONEXIT", false);
				this->gameButtons->setButtonBlocked("PRISONEXIT", true);
			}
		}
	}

	else if (this->gameButtons->isButtonPressed("BUY") && !this->gameButtons->isButtonBlocked("BUY"))
	{
		if (actualPlayer->getDiced() && this->boardSpaces->getSpace(actualPlayer->getLocation())->getOwnership() == -1)
		{
			this->operations->buySpace(actualPlayer, this->boardSpaces->getSpace(actualPlayer->getLocation()), this->player_turn);
		}
		this->gameButtons->setButtonBlocked("BUY", true);
		this->gameButtons->setButtonActive("BUY", false);
	}

	else if (this->gameButtons->isButtonPressed("UPGRADE") && actualPlayer->ownedAllInColor(actualPlayer->getLocation()))
	{
		//upgrade house - only once per round!!

	}

	else if (this->gameButtons->isButtonPressed("TRADE") && !this->gameButtons->isButtonBlocked("TRADE"))
	{
		this->trade_component->setActive(true);
		this->trade_component->createOffer(this->player_turn, this->boardSpaces->getSpace(actualPlayer->getLocation())->getOwnership(), this->boardSpaces->getSpace(actualPlayer->getLocation()));
		this->gameButtons->setButtonBlocked("TRADE", true);
		this->trade_component->setActive(false);
	}

	else if (this->gameButtons->isButtonPressed("PRISONEXIT") && this->actualPlayer->getJailed() && !this->actualPlayer->getDiced()) {
		this->operations->playerToBank(this->actualPlayer, 200, this->player_turn);
		this->gameButtons->setButtonActive("PRISONEXIT", false);
		this->gameButtons->setButtonBlocked("PRISONEXIT", true);
	}
	
	else if (this->gameButtons->isButtonPressed("ENDTURN") && actualPlayer->getDiced() && !this->gameButtons->isButtonBlocked("ENDTURN"))
		this->nextPlayer();

	if (this->gameButtons->isButtonPressed("PLAYERS1"));

	if (this->gameButtons->isButtonPressed("PLAYERS2"));
		
	if (this->gameButtons->isButtonPressed("PLAYERS3"))
		
	if (this->gameButtons->isButtonPressed("PLAYERS4"));

}

void GameState::updatePauseMenuButtons()
{
	if (this->pmenu->isButtonPressed("RESUME") && !this->dialogboxes->isBoxActive("EXIT"))
		this->unpauseState();
	if (this->pmenu->isButtonPressed("BACK_STATE"))
		this->dialogboxes->setBoxActive("EXIT", true);
}


void GameState::updateDice(const float& dt)
{
	if (players->getPlayer(player_turn)->getDiced()) {
		dice->update(dt, this->mousePosView);
		dice2->update(dt, this->mousePosView);
	}
}

void GameState::moveCheck(const float& dt)
{
	if (actualPlayer->getDiced())
	{
		if (this->player_to_go > 0)
		{
			if (boardSpaces->getSpace(actualPlayer->getLocation())->getType() == "START") 
			{
				this->spaceActionHandler->spaceAction(actualPlayer);
			}
			this->playerMove(dt);
			this->player_to_go--;
		}
		else if (this->player_to_go == 0)
		{
			this->spaceActionHandler->spaceAction(actualPlayer);
			this->player_to_go--;
		}
		else
		{
			this->gameButtons->setButtonBlocked("ENDTURN", false);
			this->gameButtons->setButtonActive("ENDTURN", true);
		}
	}

}

void GameState::actionFreezeUpdate(const float& dt)
{
	if (this->card_deck->isDisplayed(0) or this->card_deck->isDisplayed(1))
	{
		if (this->card_deck->getHuge(0)->isPressed())
			this->card_deck->setDisplay(0, 0);
		else if (this->card_deck->getHuge(1)->isPressed())
			this->card_deck->setDisplay(1, 0);
	}
	else
	{
		dt_freeze -= dt;
		if (dt_freeze <= 0)
		{
			dt_freeze = dt * 7;
			moveCheck(dt);
		}
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeytime(dt);
	this->updateInput(dt);

	this->dialogboxes->update(mousePosView);
	

	if (!this->paused) { //unpaused
		this->trade_component->update(mousePosView, player_turn);
		if (this->dialogboxes->isBoxActive("INCOME_TAX"))
		{
			if (this->dialogboxes->isBoxConfirm("INCOME_TAX")) {
				this->operations->playerToBank(actualPlayer, this->boardSpaces->getSpace(actualPlayer->getLocation())->getTax(), this->player_turn);
				this->dialogboxes->resetBoxState("INCOME_TAX");
			}
			if (this->dialogboxes->isBoxCancel("INCOME_TAX")) {
				this->operations->playerToBank(actualPlayer, actualPlayer->getMoneyAmount() * 0.1, this->player_turn);
				this->dialogboxes->resetBoxState("INCOME_TAX");
			}
		}	
		else
		{
			actualPlayer = this->players->getPlayer(player_turn);
			
			this->updatePlayerInput(dt);
			this->actionFreezeUpdate(dt);
			this->updateButtons(dt);
			this->updateDice(dt);
			this->boardSpaces->update(dt, this->mousePosView);
			this->players->update(dt, this->mousePosView);

			score_board->update(dt, this->player_turn, this->boardSpaces->getSpace(actualPlayer->getLocation())->getName(0)
				+ " " + boardSpaces->getSpace(actualPlayer->getLocation())->getName(1)
				+ " " + this->boardSpaces->getSpace(actualPlayer->getLocation())->getType(),
				this->boardSpaces->getSpace(actualPlayer->getLocation())->getOwnership());
			this->gameButtons->update(this->mousePosView);

			//mouse update
			this->dice->update(dt, this->mousePosView);
			this->dice->update(dt, this->mousePosView);
			card_deck->update(dt, this->mousePosView);

			
		}
	}
	else //paused
	{
		this->pmenu->update(this->mousePosView);
		this->updatePauseMenuButtons();

		if (this->dialogboxes->isBoxActive("EXIT"))
		{
			if (this->dialogboxes->isBoxConfirm("EXIT")) {
				this->music->stop();
				this->menuMusic->play();
				this->endState();
			}
			if (this->dialogboxes->isBoxCancel("EXIT")) {
				this->dialogboxes->resetBoxState("EXIT");
			}
		}
	}


	//TO REMOVE LATER!! this is for get position to place buttons
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\r\n";

}


void GameState::nextPlayer() 
{
	this->player_to_go = -1;
	actualPlayer->setDiced(0);
	this->player_turn++;
	if (this->player_turn >= this->total_players)
		this->player_turn -= this->total_players;

	//color button reset
	this->gameButtons->defaultButtonsStates();

	if (this->players->getPlayer(player_turn)->getJailed()) {
		this->gameButtons->setButtonBlocked("PRISONEXIT", false);
		this->gameButtons->setButtonBlocked("PRISONEXIT", true);
	}

	//balance text reset;
	this->score_board->resetMoneyBalanceTextboxes();
}

void GameState::playerMove(const float& dt)
{
	actualPlayer->setLocation(actualPlayer->getLocation() + 1);
	if (actualPlayer->getLocation() > 39)
	{
		actualPlayer->setLocation(actualPlayer->getLocation() - 40);
	}
	actualPlayer->setPosition(boardSpaces->getSpacePos1(actualPlayer->getLocation()));
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);

	this->dice->render(target);
	this->dice2->render(target);
	this->score_board->render(target);
	this->gameButtons->render(target);
	this->boardSpaces->render(target);
	this->card_deck->render(target);

	this->players->render(target);

	if (this->paused) //pause menu render
		this->pmenu->render(*target);

	this->dialogboxes->render(target);
	this->trade_component->render(target, player_turn);
}