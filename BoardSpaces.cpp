#include "BoardSpaces.h"


void BoardSpaces::initSpaceLocations()
{
	//1-10
	this->boardSpace.push_back(Coorinates(sf::Vector2f(950, 920), sf::Vector2f(1020, 1000)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(848, 950), sf::Vector2f(888, 1000)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(768, 950), sf::Vector2f(808, 1000)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(688, 950), sf::Vector2f(728, 1000)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(608, 950), sf::Vector2f(648, 1000)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(528, 950), sf::Vector2f(568, 1000)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(448, 950), sf::Vector2f(488, 1000)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(368, 950), sf::Vector2f(408, 1000)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(288, 950), sf::Vector2f(328, 1000)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(208, 950), sf::Vector2f(248, 1000)));
	//11-20
	this->boardSpace.push_back(Coorinates(sf::Vector2f(10, 930), sf::Vector2f(80, 930)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(40, 810), sf::Vector2f(95, 855)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(52, 724), sf::Vector2f(95, 780)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(48, 643), sf::Vector2f(95, 685)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(40, 557), sf::Vector2f(95, 605)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(40, 472), sf::Vector2f(95, 527)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(40, 383), sf::Vector2f(95, 446)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(40, 300), sf::Vector2f(95, 370)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(40, 230), sf::Vector2f(95, 286)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(40, 150), sf::Vector2f(95, 205)));

	//21-30
	this->boardSpace.push_back(Coorinates(sf::Vector2f(40, 20), sf::Vector2f(110, 80)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(180, 12), sf::Vector2f(180, 70)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(260, 12), sf::Vector2f(260, 70)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(350, 12), sf::Vector2f(350, 70)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(430, 12), sf::Vector2f(430, 70)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(511, 12), sf::Vector2f(511, 70)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(595, 12), sf::Vector2f(595, 70)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(680, 12), sf::Vector2f(680, 70)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(760, 12), sf::Vector2f(760, 70)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(840, 12), sf::Vector2f(840, 70)));
	//31-40
	this->boardSpace.push_back(Coorinates(sf::Vector2f(935, 12), sf::Vector2f(1000, 90)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(940, 155), sf::Vector2f(1005, 200)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(940, 240), sf::Vector2f(1005, 279)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(940, 320), sf::Vector2f(1005, 360)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(940, 400), sf::Vector2f(1005, 450)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(940, 480), sf::Vector2f(1005, 524)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(940, 564), sf::Vector2f(1005, 615)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(940, 650), sf::Vector2f(1005, 695)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(940, 730), sf::Vector2f(1005, 775)));
	this->boardSpace.push_back(Coorinates(sf::Vector2f(940, 810), sf::Vector2f(1005, 860)));

}

void BoardSpaces::initSpaceParam()
{
	//1-10
	this->spaces.push_back(new Space("   GO!   ", "         ", "START", 0, 0, true, -1, false, 0, 0, 0, "Pass Go! ", "Get $200 "));
	this->spaces.push_back(new Space("  Port of   ", "  Lubeck   ", "Property", 60, 0, true, -1, false, 0, 2, 0, "         ", "   $60   "));
	this->spaces.push_back(new Space("Community", "  Chest  ", "Community Chest", 0, 0, true, -1, false, 0, 0, 0, " Draw a  ", "  Card   "));
	this->spaces.push_back(new Space(" Port of  ", " Rostock ", "Property", 70, 0, true, -1, false, 0, 4, 0, "         ", "   $60   "));
	this->spaces.push_back(new Space(" Income  ", "  Tax  ", "Tax", 0, 0, true, -1, false, 0, 2, 200, "         ", "Pay $200 "));
	this->spaces.push_back(new Space(" Gdansk Cargo  ", " Terminal ", "RailRoad", 200, 0, true, -1, false, 0, 25, 0, "         ", "  $200   "));
	this->spaces.push_back(new Space(" Port of  ", "  Szczecin   ", "Property", 100, 0, true, -1, false, 0, 6, 0, "         ", "  $100   "));
	this->spaces.push_back(new Space(" Chance  ", "         ", "Chance", 0, 0, true, -1, false, 0, 0, 0, " Draw a  ", "  card   "));
	this->spaces.push_back(new Space("  Port of  ", "  Gdynia  ", "Property", 100, 0, true, -1, false, 0, 6, 0, "         ", "  $100   "));
	this->spaces.push_back(new Space(" Port of  ", " Gdansk   ", "Property", 120, 0, true, -1, false, 0, 8, 0, "         ", "  $120   "));
	//11-20
	this->spaces.push_back(new Space(" Jail  ", "         ", "Jail", 0, 0, true, -1, false, 0, 0, 0, "  Just   ", "Visiting "));
	this->spaces.push_back(new Space(" Port of   ", " San Francisco  ", "Property", 140, 0, true, -1, false, 0, 10, 0, "         ", "  $140   "));
	this->spaces.push_back(new Space("Charging ", "Station ", "Utility", 150, 0, true, -1, false, 0, 10, 0, "         ", "  $150   "));
	this->spaces.push_back(new Space("Port of ", "  New Orleans   ", "Property", 140, 0, true, -1, false, 0, 10, 0, "         ", "  $140   "));
	this->spaces.push_back(new Space(" Port of ", " Saint-Petersburg   ", "Property", 160, 0, true, -1, false, 0, 12, 0, "         ", "  $160   "));
	this->spaces.push_back(new Space("Gdansk Cargo ", "    Terminal     ", "RailRoad", 200, 0, true, -1, false, 0, 25, 0, "         ", "  $200   "));
	this->spaces.push_back(new Space("  Port of ", "  Copenhagen ", "Property", 180, 0, true, -1, false, 0, 14, 0, "         ", "  $180   "));
	this->spaces.push_back(new Space("Community", "  Chest  ", "Community Chest", 0, 0, true, -1, false, 0, 0, 0, " Draw a  ", "  Card   "));
	this->spaces.push_back(new Space("  Karlaskrona", "  Port ", "Property", 180, 0, true, -1, false, 0, 14, 0, "         ", "  $180   "));
	this->spaces.push_back(new Space("  Port of ", " New York and New Jersey", "Property", 200, 0, true, -1, false, 0, 16, 0, "         ", "  $200   "));
	//21-30
	this->spaces.push_back(new Space("Free", "   Parking   ", "FreeParking", 0, 0, false, -1, false, 0, 0, 0, "         ", "         "));
	this->spaces.push_back(new Space(" Port of ", "Hong Kong", "Property", 220, 0, false, -1, false, 0, 18, 0, "         ", "  $220   "));
	this->spaces.push_back(new Space(" Chance  ", "         ", "Chance", 0, 0, false, -1, false, 0, 0, 0, " Draw a  ", "  Card   "));
	this->spaces.push_back(new Space(" Port of ", " Rotterdam ", "Property", 220, 0, false, -1, false, 0, 18, 0, "         ", "  $220   "));
	this->spaces.push_back(new Space("Port of ", " Stockholm   ", "Property", 240, 0, false, -1, false, 0, 20, 0, "         ", "  $240   "));
	this->spaces.push_back(new Space("Singapore Cargo ", "   Terminal      ", "RailRoad", 200, 0, false, -1, false, 0, 25, 0, "         ", "  $200   "));
	this->spaces.push_back(new Space("Port of ", "  Jebel Ali", "Property", 260, 0, false, -1, false, 0, 22, 0, "         ", "  $260   "));
	this->spaces.push_back(new Space(" Port   ", "Gruz", "Property", 260, 0, false, -1, false, 0, 22, 0, "         ", "  $260   "));
	this->spaces.push_back(new Space(" Water Refill ", " Station", "Utility", 150, 0, false, -1, false, 0, 10, 0, "         ", "  $150   "));
	this->spaces.push_back(new Space(" Port of ", " Barcelona ", "Property", 280, 0, false, -1, false, 0, 22, 0, "         ", "  $280   "));
	//31-40
	this->spaces.push_back(new Space("Go to ", " Jail  ", "GoJail", 0, 0, false, -1, false, 0, 0, 0, "         ", "         "));
	this->spaces.push_back(new Space("Nagasaki ", "  Port ", "Property", 300, 0, false, -1, false, 0, 26, 0, "         ", "  $300   "));
	this->spaces.push_back(new Space("  Port of ", " Nassau ", "Property", 300, 0, false, -1, false, 0, 26, 0, "         ", "  $300   "));
	this->spaces.push_back(new Space("Community", "  Chest  ", "Community Chest", 0, 0, false, -1, false, 0, 0, 0, " Draw a  ", "  Card   "));
	this->spaces.push_back(new Space(" Port of ", " Tianjin ", "Property", 320, 0, false, -1, false, 0, 28, 0, "         ", "  $320   "));
	this->spaces.push_back(new Space("   Shanghai Cargo", " Terminal ", "RailRoad", 200, 0, false, -1, false, 0, 25, 0, "         ", "  $200   "));
	this->spaces.push_back(new Space(" Chance ", "         ", "Chance", 0, 0, false, -1, false, 0, 0, 0, " Draw a  ", "  Card   "));
	this->spaces.push_back(new Space(" Port of ", " Istanbul ", "Property", 350, 0, false, -1, false, 0, 35, 0, "         ", "  $350   "));
	this->spaces.push_back(new Space(" Luxury  ", "  Tax   ", "Tax", 0, 0, false, -1, false, 0, 0, 75, "         ", " Pay $75 "));
	this->spaces.push_back(new Space("Port of  ", "Singapore ", "Property", 400, 0, false, -1, false, 0, 50, 0, "         ", "  $400   "));
}

void BoardSpaces::initTextures()
{
	if (!this->textures["HOUSE_GREEN"].loadFromFile("Recources/Images/Sprites/Houses/house-green.png"))
		throw "ERROR::BOARDSPACE::COULD_NOT_LOAD_PLAYER_SHIP_TEXTURE";
	if (!this->textures["HOUSE_RED"].loadFromFile("Recources/Images/Sprites/Houses/house-red.png"))
		throw "ERROR::BOARDSPACE::COULD_NOT_LOAD_PLAYER_SOCCER_TEXTURE";
}


void BoardSpaces::initHouses()
{
	//space01
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(826, 904), sf::Vector2f(850, 904), sf::Vector2f(874, 904), 0));
	//space03
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(662, 904), sf::Vector2f(686, 904), sf::Vector2f(710, 904), 0));
	//space06
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(416, 904), sf::Vector2f(440, 904), sf::Vector2f(464, 904), 0));
	//space08
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(252, 904), sf::Vector2f(276, 904), sf::Vector2f(300, 904), 0));
	//space09
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(170, 904), sf::Vector2f(194, 904), sf::Vector2f(218, 904), 0));


	//space11
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(176, 826), sf::Vector2f(176, 850), sf::Vector2f(176, 874), 90));
	//space13
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(176, 664), sf::Vector2f(176, 688), sf::Vector2f(176, 712), 90));
	//space14
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(176, 580), sf::Vector2f(176, 604), sf::Vector2f(176, 628), 90));
	//space16
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(176, 418), sf::Vector2f(176, 442), sf::Vector2f(176, 466), 90));
	//space18
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(176, 254), sf::Vector2f(176, 278), sf::Vector2f(176, 302), 90));
	//space19
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(176, 170), sf::Vector2f(176, 194), sf::Vector2f(176, 218), 90));


	//space21
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(207, 176), sf::Vector2f(231, 176), sf::Vector2f(255, 176), 180));
	//space23
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(371, 176), sf::Vector2f(395, 176), sf::Vector2f(419, 176), 180));
	//space24
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(454, 176), sf::Vector2f(478, 176), sf::Vector2f(502, 176), 180));
	//space26
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(617, 176), sf::Vector2f(642, 176), sf::Vector2f(665, 176), 180));
	//space27
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(699, 176), sf::Vector2f(723, 176), sf::Vector2f(747, 176), 180));
	//space29
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(862, 176), sf::Vector2f(886, 176), sf::Vector2f(910, 176), 180));


	//space31
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(905, 207), sf::Vector2f(905, 231), sf::Vector2f(905, 255), 270));
	//space32
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(905, 289), sf::Vector2f(905, 313), sf::Vector2f(905, 337), 270));
	//space34
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(905, 454), sf::Vector2f(905, 478), sf::Vector2f(905, 502), 270));
	//space37
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(905, 698), sf::Vector2f(905, 722), sf::Vector2f(905, 746), 270));
	//space39
	this->houses.push_back(new SpaceHouses(this->textures["HOUSE_GREEN"], this->textures["HOUSE_RED"],
		sf::Vector2f(905, 862), sf::Vector2f(905, 886), sf::Vector2f(905, 910), 270));
}

BoardSpaces::BoardSpaces()
{
	this->initSpaceLocations();
	this->initSpaceParam();

	this->initTextures();
	this->initHouses();
}

BoardSpaces::~BoardSpaces()
{
	for (auto& space : this->spaces)
		delete space;
	for (auto& house : this->houses)
		delete house;
}

sf::Vector2f BoardSpaces::getSpacePos1(int element)
{
	return boardSpace[element].x;
}

sf::Vector2f BoardSpaces::getSpacePos2(int element)
{
	return boardSpace[element].y;
}


Space* BoardSpaces::getSpace(int element)
{
	return this->spaces[element];
}

void BoardSpaces::update(const float& dt, sf::Vector2f mousePosView)
{
	for (auto& house : this->houses)
		house->update(dt, mousePosView);
}

void BoardSpaces::render(sf::RenderTarget* target)
{
	for (auto& house : this->houses)
		house->render(target);
}

