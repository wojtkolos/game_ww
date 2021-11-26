#pragma once
#define CARD_DECK_H

//#include "Player.h"
#include "CommunityCard.h"

enum card_community 
{
	CARD_COMMUNITY0 = 0, CARD_COMMUNITY1, CARD_COMMUNITY2, CARD_COMMUNITY3, CARD_COMMUNITY4,
	CARD_COMMUNITY5, CARD_COMMUNITY6, CARD_COMMUNITY7, CARD_COMMUNITY8, CARD_COMMUNITY9, COMMUNITY_ERROR
};

enum card_chance
{
	CARD_CHANCE0 = 0, CARD_CHANCE1, CARD_CHANCE2, CARD_CHANCE3, CARD_CHANCE4,
	CARD_CHANCE5, CARD_CHANCE6, CARD_CHANCE7, CARD_CHANCE8, CARD_CHANCE9, CHANCE_ERROR
};

class CardDeck 
{
	Card* huge_card0;
	Card* huge_card1;

	std::vector<Card*> card_deck0;
	std::vector<Card*> card_deck1;
	std::map<std::string, sf::Texture> card_textures;

	unsigned short int card0_to_render;
	float default_rotation0;
	
	unsigned short int card1_to_render;
	float default_rotation1;

	bool animation;
	bool display_card0;
	bool display_card1;

	unsigned short card_type;
	sf::Vector2f defaultPosition0;
	sf::Vector2f defaultPosition1;
	sf::Vector2f centerPosition;
public:
	CardDeck();
	~CardDeck();

	//Init functions
	void initVariables();
	void initTextures();
	void initCards();

	void drawCard(unsigned short type);
	void animate(const float& dt);
	void setAnimation(bool c);
	void setDisplay(bool c, bool state);
	int cardAction(Bank* bank, Player* player, short& player_to_go);

	bool isDisplayed(bool c);
	Card* getHuge(bool c);

	void update(const float& dt, sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};