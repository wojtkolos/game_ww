#include "ScoreBoard.h"


void ScoreBoard::initVariables(unsigned short totalPlayers, std::vector<Player*> players, Bank* bank, int player_turn, sf::Font& font)
{
	this->font= font;
	this->total_players = totalPlayers;
	this->playerptr = players;
	this->bank = bank;
	this->player_turn = player_turn;
}

void ScoreBoard::initTextboxes()
{
	if (total_players == 2) {
		this->textScore["PLAYER1"] = new Textbox(1415, 206, 100, 30, 20,
			&this->font, std::to_string(this->playerptr[0]->getMoneyAmount()),
			sf::Color(70, 70, 70, 200));
		this->textScore["PLAYER2"] = new Textbox(1415, 246, 100, 30, 20,
			&this->font, std::to_string(this->playerptr[1]->getMoneyAmount()),
			sf::Color(70, 70, 70, 200));
		this->textScore["PLAYER3"] = new Textbox(1415, 286, 100, 30, 20,
			&this->font, std::to_string(0),
			sf::Color(70, 70, 70, 200));
		this->textScore["PLAYER4"] = new Textbox(1415, 326, 100, 30, 20,
			&this->font, std::to_string(0),
			sf::Color(70, 70, 70, 200));
	}
	else if (total_players == 3) {
		this->textScore["PLAYER1"] = new Textbox(1415, 206, 100, 30, 20,
			&this->font, std::to_string(this->playerptr[0]->getMoneyAmount()),
			sf::Color(70, 70, 70, 200));
		this->textScore["PLAYER2"] = new Textbox(1415, 246, 100, 30, 20,
			&this->font, std::to_string(this->playerptr[1]->getMoneyAmount()),
			sf::Color(70, 70, 70, 200));
		this->textScore["PLAYER3"] = new Textbox(1415, 286, 100, 30, 20,
			&this->font, std::to_string(this->playerptr[2]->getMoneyAmount()),
			sf::Color(70, 70, 70, 200));
		this->textScore["PLAYER4"] = new Textbox(1415, 326, 100, 30, 20,
			&this->font, std::to_string(0),
			sf::Color(70, 70, 70, 200));
	}
	else if (total_players == 4) {
		this->textScore["PLAYER1"] = new Textbox(1415, 206, 100, 30, 20,
			&this->font, std::to_string(this->playerptr[0]->getMoneyAmount()),
			sf::Color(70, 70, 70, 200));
		this->textScore["PLAYER2"] = new Textbox(1415, 246, 100, 30, 20,
			&this->font, std::to_string(this->playerptr[1]->getMoneyAmount()),
			sf::Color(70, 70, 70, 200));
		this->textScore["PLAYER3"] = new Textbox(1415, 286, 100, 30, 20,
			&this->font, std::to_string(this->playerptr[2]->getMoneyAmount()),
			sf::Color(70, 70, 70, 200));
		this->textScore["PLAYER4"] = new Textbox(1415, 326, 100, 30, 20,
			&this->font, std::to_string(this->playerptr[3]->getMoneyAmount()),
			sf::Color(70, 70, 70, 200));


		
	}
	this->textScore["BANK"] = new Textbox(1418, 164, 100, 30, 20,
		&this->font, std::to_string(this->bank->getAmount()),
		sf::Color(70, 70, 70, 200));
	this->textScore["SPACE_NAME"] = new Textbox(1220, 450, 100, 40, 20,
		&this->font, "START",
		sf::Color(70, 70, 70, 200));
	this->textScore["SPACE_OWNER"] = new Textbox(1220, 500, 100, 40, 20,
		&this->font, "Space owner: x",
		sf::Color(70, 70, 70, 200));
}

void ScoreBoard::initMoneyBalanceTextboxes()
{
	this->textScoreBalance["PLAYER1"] = new MoneyBalanceTextbox(1315, 206, 100, 30, 20,
		&this->font, std::to_string(0),
		sf::Color(70, 70, 70, 200)), sf::Color::Green;
	this->textScoreBalance["PLAYER2"] = new MoneyBalanceTextbox(1315, 246, 100, 30, 20,
		&this->font, std::to_string(0),
		sf::Color(70, 70, 70, 200)), sf::Color::Green;
	this->textScoreBalance["PLAYER3"] = new MoneyBalanceTextbox(1315, 286, 100, 30, 20,
		&this->font, std::to_string(0),
		sf::Color(70, 70, 70, 200)), sf::Color::Green;
	this->textScoreBalance["PLAYER4"] = new MoneyBalanceTextbox(1315, 326, 100, 30, 20,
		&this->font, std::to_string(0),
		sf::Color(70, 70, 70, 200)), sf::Color::Green;
}


ScoreBoard::ScoreBoard(unsigned short totalPlayers, std::vector<Player*> players, Bank* bank, int player_turn, sf::Font& font)
{
	this->initVariables(totalPlayers, players, bank, player_turn, font);
	this->initTextboxes();
	this->initMoneyBalanceTextboxes();

	this->circlePointers = new CirclePointers(this->total_players);
}

ScoreBoard::~ScoreBoard()
{
	for (auto& text : this->textScore)
		delete text.second;

	this->textScore.clear();

	for (auto& text : this->textScoreBalance)
		delete text.second;

	this->textScoreBalance.clear();
}


//Functions
void ScoreBoard::updateAmountDisp()
{
	if (this->player_turn == 0)
		textScore["PLAYER1"]->setText(std::to_string(this->playerptr[this->player_turn]->getMoneyAmount()));
	else if (this->player_turn == 1)
		textScore["PLAYER2"]->setText(std::to_string(this->playerptr[this->player_turn]->getMoneyAmount()));
	else if (this->player_turn == 2)
		textScore["PLAYER3"]->setText(std::to_string(this->playerptr[this->player_turn]->getMoneyAmount()));
	else if (this->player_turn == 3)
		textScore["PLAYER4"]->setText(std::to_string(this->playerptr[this->player_turn]->getMoneyAmount()));

	textScore["BANK"]->setText(std::to_string(this->bank->getAmount()));
}

void ScoreBoard::updateNames(std::string space_name, short space_owner)
{
	textScore["SPACE_NAME"]->setText(space_name);
	textScore["SPACE_OWNER"]->setText("Space owner: " + std::to_string(space_owner + 1));
}
void ScoreBoard::update(const float& dt, int player_turn, std::string space_name, short space_owner)
{
	this->player_turn = player_turn;
	this->updateAmountDisp();
	this->updateNames(space_name, space_owner);
	circlePointers->update(player_turn);
}

void ScoreBoard::renderTextScore(sf::RenderTarget* target)
{
	for (auto& it : this->textScore)
	{
		it.second->render(target);
	}
}

void ScoreBoard::renderTextBalance(sf::RenderTarget* target)
{
	for (auto& it : this->textScoreBalance)
	{
		if(it.second->isHidden() == 0)
			it.second->render(target);
	}
}

void ScoreBoard::render(sf::RenderTarget* target)
{
	this->renderTextScore(target);
	this->renderTextBalance(target);
	this->circlePointers->render(target);
}

void ScoreBoard::changeScoreBalance(int playerNum, int ammount, bool hidden)
{
	switch (playerNum)
	{
	case 0:
		this->textScoreBalance["PLAYER1"]->setHidden(hidden);
		this->textScoreBalance["PLAYER1"]->setBalance(ammount);
		break;
	case 1:
		this->textScoreBalance["PLAYER2"]->setHidden(hidden);
		this->textScoreBalance["PLAYER2"]->setBalance(ammount);
		break;
	case 2:
		this->textScoreBalance["PLAYER3"]->setHidden(hidden);
		this->textScoreBalance["PLAYER3"]->setBalance(ammount);
		break;
	case 3:
		this->textScoreBalance["PLAYER4"]->setHidden(hidden);
		this->textScoreBalance["PLAYER4"]->setBalance(ammount);
		break;
	default:
		break;
	}
}

void ScoreBoard::resetMoneyBalanceTextboxes()
{
	for (int i = 0; i<4; i++)
	{
		changeScoreBalance(i, 0, true);
	}
}