#include "CardDeck.h"


card_community community_to_enum(const std::string& str)
{
	if (str == "CARD_COMMUNITY0") return CARD_COMMUNITY0;
	else if (str == "CARD_COMMUNITY1") return CARD_COMMUNITY1;
	else if (str == "CARD_COMMUNITY2") return CARD_COMMUNITY2;
	else if (str == "CARD_COMMUNITY3") return CARD_COMMUNITY3;
	else if (str == "CARD_COMMUNITY4") return CARD_COMMUNITY4;
	else if (str == "CARD_COMMUNITY5") return CARD_COMMUNITY5;
	else if (str == "CARD_COMMUNITY6") return CARD_COMMUNITY6;
	else if (str == "CARD_COMMUNITY7") return CARD_COMMUNITY7;
	else if (str == "CARD_COMMUNITY8") return CARD_COMMUNITY8;
	else if (str == "CARD_COMMUNITY9") return CARD_COMMUNITY9;
	return COMMUNITY_ERROR;
}

card_chance chance_to_enum(const std::string& str)
{
	if (str == "CARD_CHANCE0") return CARD_CHANCE0;
	else if (str == "CARD_CHANCE1") return CARD_CHANCE1;
	else if (str == "CARD_CHANCE2") return CARD_CHANCE2;
	else if (str == "CARD_CHANCE3") return CARD_CHANCE3;
	else if (str == "CARD_CHANCE4") return CARD_CHANCE4;
	else if (str == "CARD_CHANCE5") return CARD_CHANCE5;
	else if (str == "CARD_CHANCE6") return CARD_CHANCE6;
	else if (str == "CARD_CHANCE7") return CARD_CHANCE7;
	else if (str == "CARD_CHANCE8") return CARD_CHANCE8;
	else if (str == "CARD_CHANCE9") return CARD_CHANCE9;
	return CHANCE_ERROR;
}


// Init functions
void CardDeck::initVariables()
{
	//community
	this->card0_to_render = 0;
	this->default_rotation0 = 135.f;
	//chance
	this->card1_to_render = 0;
	this->default_rotation1 = 315.f;

	this->display_card0 = false;
	this->display_card1 = false;
	this->animation = false;

	defaultPosition0 = sf::Vector2f(525, 425);
	defaultPosition1 = sf::Vector2f(562, 655);
	centerPosition = sf::Vector2f(450, 450);//112 205 // 
}


void CardDeck::initTextures()
{
	//chance 0-9
	if (!this->card_textures["CARD_CHANCE0"].loadFromFile("Recources/Images/Sprites/Chance/chance0.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_CHANCE0_TEXTURE";
	if (!this->card_textures["CARD_CHANCE1"].loadFromFile("Recources/Images/Sprites/Chance/chance1.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_CHANCE1_TEXTURE";
	if (!this->card_textures["CARD_CHANCE2"].loadFromFile("Recources/Images/Sprites/Chance/chance2.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_CHANCE2_TEXTURE";
	if (!this->card_textures["CARD_CHANCE3"].loadFromFile("Recources/Images/Sprites/Chance/chance3.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_CHANCE3_TEXTURE";
	if (!this->card_textures["CARD_CHANCE4"].loadFromFile("Recources/Images/Sprites/Chance/chance4.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_CHANCE4_TEXTURE";
	if (!this->card_textures["CARD_CHANCE5"].loadFromFile("Recources/Images/Sprites/Chance/chance5.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_CHANCE5_TEXTURE";
	if (!this->card_textures["CARD_CHANCE6"].loadFromFile("Recources/Images/Sprites/Chance/chance6.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_CHANCE6_TEXTURE";
	if (!this->card_textures["CARD_CHANCE7"].loadFromFile("Recources/Images/Sprites/Chance/chance7.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_CHANCE7_TEXTURE";
	if (!this->card_textures["CARD_CHANCE8"].loadFromFile("Recources/Images/Sprites/Chance/chance8.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_CHANCE8_TEXTURE";
	if (!this->card_textures["CARD_CHANCE9"].loadFromFile("Recources/Images/Sprites/Chance/chance9.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_CHANCE9_TEXTURE";

	//community 0-9
	if (!this->card_textures["CARD_COMMUNITY0"].loadFromFile("Recources/Images/Sprites/CommunityChest/community0.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_COMMUNITY0_TEXTURE";
	if (!this->card_textures["CARD_COMMUNITY1"].loadFromFile("Recources/Images/Sprites/CommunityChest/community1.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_COMMUNITY1_TEXTURE";
	if (!this->card_textures["CARD_COMMUNITY2"].loadFromFile("Recources/Images/Sprites/CommunityChest/community2.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_COMMUNITY2_TEXTURE";
	if (!this->card_textures["CARD_COMMUNITY3"].loadFromFile("Recources/Images/Sprites/CommunityChest/community3.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_COMMUNITY3_TEXTURE";
	if (!this->card_textures["CARD_COMMUNITY4"].loadFromFile("Recources/Images/Sprites/CommunityChest/community4.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_COMMUNITY4_TEXTURE";
	if (!this->card_textures["CARD_COMMUNITY5"].loadFromFile("Recources/Images/Sprites/CommunityChest/community5.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_COMMUNITY5_TEXTURE";
	if (!this->card_textures["CARD_COMMUNITY6"].loadFromFile("Recources/Images/Sprites/CommunityChest/community6.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_COMMUNITY6_TEXTURE";
	if (!this->card_textures["CARD_COMMUNITY7"].loadFromFile("Recources/Images/Sprites/CommunityChest/community7.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_COMMUNITY7_TEXTURE";
	if (!this->card_textures["CARD_COMMUNITY8"].loadFromFile("Recources/Images/Sprites/CommunityChest/community8.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_COMMUNITY8_TEXTURE";
	if (!this->card_textures["CARD_COMMUNITY9"].loadFromFile("Recources/Images/Sprites/CommunityChest/community9.png"))
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_CARD_COMMUNITY9_TEXTURE";
}

void CardDeck::initCards()
{
	
	this->card_deck0.push_back(new CommunityCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY0"], 
		"CARD_COMMUNITY0", "Collect $200!", 200));
	this->card_deck0.push_back(new CommunityCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY1"],
		"CARD_COMMUNITY1", "Collect $75!", 75));
	this->card_deck0.push_back(new CommunityCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY2"],
		"CARD_COMMUNITY2", "Collect $150!", 150));
	this->card_deck0.push_back(new CommunityCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY3"],
		"CARD_COMMUNITY3", "Go to 25!", 0));
	this->card_deck0.push_back(new CommunityCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY4"],
		"CARD_COMMUNITY4", "Collect $100!", 100));
	this->card_deck0.push_back(new CommunityCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY5"],
		"CARD_COMMUNITY5", "Collect $20!", 20));
	this->card_deck0.push_back(new CommunityCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY6"],
		"CARD_COMMUNITY6", "Go to 40!", 0));
	this->card_deck0.push_back(new CommunityCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY7"],
		"CARD_COMMUNITY7", "Collect $15!", 15));
	this->card_deck0.push_back(new CommunityCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY8"],
		"CARD_COMMUNITY8", "Collect $200!", 200));
	this->card_deck0.push_back(new CommunityCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY9"],
		"CARD_COMMUNITY9", "Collect $20!", 20));

	this->card_deck1.push_back(new ChanceCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE0"],
		"CARD_CHANCE0", "Go to start & collect $200!", 200));
	this->card_deck1.push_back(new ChanceCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE1"],
		"CARD_CHANCE1", "Go to 29!", 0));
	this->card_deck1.push_back(new ChanceCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE2"],
		"CARD_CHANCE2", "Collect $50!", 50));;
	this->card_deck1.push_back(new ChanceCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE3"],
		"CARD_CHANCE3", "Go to 12!", 0));
	this->card_deck1.push_back(new ChanceCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE4"],
		"CARD_CHANCE4", "Collect $100!", 100));
	this->card_deck1.push_back(new ChanceCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE5"],
		"CARD_CHANCE5", "Collect $15!", 15));
	this->card_deck1.push_back(new ChanceCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE6"],
		"CARD_CHANCE6", "Go to 16!", 0));
	this->card_deck1.push_back(new ChanceCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE7"],
		"CARD_CHANCE7", "Collect $15!", 15));
	this->card_deck1.push_back(new ChanceCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE8"],
		"CARD_CHANCE8", "Go to 6!", 0));
	this->card_deck1.push_back(new ChanceCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE9"],
		"CARD_CHANCE9", "Collect $100!", 100));
	

	this->huge_card0 = new HugeCard(defaultPosition0, default_rotation0, this->card_textures["CARD_COMMUNITY0"]);
	this->huge_card1 = new HugeCard(defaultPosition1, default_rotation1, this->card_textures["CARD_CHANCE0"]);
}

CardDeck::CardDeck()
{
	this->initTextures();
	this->initVariables();

	this->initCards();
	std::shuffle(card_deck0.begin(), card_deck0.end(), std::random_device());
	std::shuffle(card_deck1.begin(), card_deck1.end(), std::random_device());
}

CardDeck::~CardDeck()
{
	for (auto& card : this->card_deck0)
		delete card;
	for (auto& card : this->card_deck1)
		delete card;
	this->card_textures.clear();

	delete this->huge_card0;
	delete this->huge_card1;
}

void CardDeck::drawCard(unsigned short type)
{
	this->card_type = type;
	//community
	if (type == 0)
	{
		this->huge_card0->getSprite()->setTexture(*card_deck0[card0_to_render]->getSprite()->getTexture());
		if (card0_to_render > 9)
		{
			card0_to_render -= 10;
		}
	}
	//chance
	else if (type == 1)
	{
		this->huge_card1->getSprite()->setTexture(*card_deck1[card1_to_render]->getSprite()->getTexture());
		if (card1_to_render > 9)
		{
			card1_to_render -= 10;
		}
	}
}

void CardDeck::animate(const float& dt)
{
	
	if (this->card_type == 0)
	{ //community
		
		Card* card = this->huge_card0;

		if (!(card->getPosition() == this->centerPosition))
		{
			card->setRotation(card->getSprite()->getRotation() + 9.f);
			card->setScale(card->getScale() + sf::Vector2f(0.4f, 0.4f));
			card->setPosition(card->getPosition() + sf::Vector2f(- 3, 1));
		}
		else
		{
			this->animation = false;
			card0_to_render++;
		}

	}
	else if (this->card_type == 1) 
	{ //chance
		Card* card = this->huge_card1;
		if (!((card->getPosition().x >= this->centerPosition.x - 1) and (card->getPosition().y >= this->centerPosition.y - 1)
			and (card->getPosition().y <= this->centerPosition.y + 1) and (card->getPosition().y <= this->centerPosition.y + 1)))
		{
			card->setRotation(card->getSprite()->getRotation() - 12.6f);
			card->setScale(card->getScale() + sf::Vector2f(0.4f, 0.4f));
			card->setPosition(card->getPosition() + sf::Vector2f(-4.48f, -8.2f));
		}
		else
		{
			this->animation = false;
			card1_to_render++;
		}
	}
}

int CardDeck::cardAction(Bank* bank, Player* player, short& player_to_go)
{
	//community
	if (this->card_type == 0)
	{
		switch (community_to_enum(card_deck0[card0_to_render]->getCardName()))
		{
		case 0:
		{ //move to start 1
			player_to_go = 40 - player->getLocation() + 1;
			//card_deck0[card0_to_render]->cardAction(bank, player); //?
			return 0;
		}
		case 1: //75
		case 2: //150
		case 4: //100
		case 5: //20
		case 7: //15
		case 8: //200
		case 9: //40
		{ //
			//card_deck0[card0_to_render]->cardAction(bank, player);
			return card_deck0[card0_to_render]->getAmmount();
		}
		case 3:
		{ //move to 25
			player_to_go = (player->getLocation() < 23)? 23 - player->getLocation() + 1 : 40 + 24 - player->getLocation() +1;
			return 0;
		}
		case 6:
		{ //move to 40
			player_to_go = (player->getLocation() < 39) ? 39 - player->getLocation() + 1 : 40 + 39 - player->getLocation() +1;
			return 0;
		}

		default:
			break;
		}		
	}
	//chance
	else if (this->card_type == 1)
	{
		switch (chance_to_enum(card_deck1[card1_to_render]->getCardName()))
		{
		case 0:
		{ //move to start 1
			player_to_go = 40 - player->getLocation() + 1;
			//card_deck0[card0_to_render]->cardAction(bank, player);;
			return 0;
		}
		case 1:
		{ //move to 29
			player_to_go = (player->getLocation() < 28)? 28 - player->getLocation() + 1 : 40 + 28 - player->getLocation() +1;
			return 0;
		}
		case 2: //50
		case 4: //100
		case 5: //15
		case 7: //15 
		case 9: //100
		{ 
			//card_deck1[card1_to_render]->cardAction(bank, player);
			return card_deck1[card1_to_render]->getAmmount();
		}
		case 3:
		{ //move to 12
			player_to_go = (player->getLocation() < 11)? 11 - player->getLocation() + 1 : 40 + 11 - player->getLocation() +1;
			return 0;
		}
		case 6:
		{ //move to 16
			player_to_go = (player->getLocation() < 15)? 15 - player->getLocation() + 1 : 40 + 15 - player->getLocation() +1;
			return 0;
		}
		case 8:
		{ //move to 6
			player_to_go = (player->getLocation() < 5)? 5 - player->getLocation() + 1 : 40 + 5 - player->getLocation() +1;
			return 0;
		}
		default:
			break;
		}
	}
	return 0;
}

void CardDeck::setAnimation(bool c)
{
	this->animation = c;
}

void CardDeck::setDisplay(bool c, bool state)
{
	if (c == 0)
	{
		if (state == 0)
		{
			this->huge_card0->setRotation(this->default_rotation0);
			this->huge_card0->setScale(sf::Vector2f(0.6f, 0.6f));
			this->huge_card0->setPosition(this->defaultPosition0);
		}
		this->display_card0 = state;
	}
	else if (c == 1)
	{
		if (state == 0)
		{
			this->huge_card1->setRotation(this->default_rotation1);
			this->huge_card1->setScale(sf::Vector2f(0.6f, 0.6f));
			this->huge_card1->setPosition(this->defaultPosition1);
		}
		this->display_card1 = state;

	}
}

bool CardDeck::isDisplayed(bool c)
{
	return (c == 0)? display_card0 : display_card1;
}

Card* CardDeck::getHuge(bool c)
{
	return (c == 0)? this->huge_card0 : this->huge_card1;
}

void CardDeck::update(const float& dt, const sf::Vector2f mousePos)
{
	if (animation)
	{
		animate(dt);
	}
	this->huge_card0->update(dt, mousePos);
	this->huge_card1->update(dt, mousePos);
}

void CardDeck::render(sf::RenderTarget* target)
{
	if(this->display_card0)
		this->huge_card0->render(target);
	if (this->display_card1)
		this->huge_card1->render(target);
}