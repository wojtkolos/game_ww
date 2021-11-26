#pragma once
#define SPACE_H

//#include "action.h"

#include <string>
class Space {

private:
	std::string name[2];
	std::string actionText[2];
	std::string spaceType; //property, card, tax, railroads, jail, etc	    
	int propertyCost;
	int freeParking;
	bool occupied;
	int owned;
	bool mortgaged;
	int houses;
	int rent;
	int tax;

public:
	Space(std::string name1, std::string name2, std::string spaceType, int propertyCost, int freeParking,
		bool occupied, int owned, bool mortgaged, int houses, int rent,	int tax, 
		std::string actionText1, std::string actionText2);
	virtual~Space();

	//functions to set values
	void setName(std::string inputName, std::string inputName2);
	void setType(std::string inputType);
	void setPropertyCost(int inputCost);
	void setFreeParking(int inputMoney);
	void setOccupied(int inputOccupied);
	void setOwnership(int inputOwnership);
	void setMortgaged(bool inputMortgage);
	void setRent(int inputRent);
	void setTax(int inputTax);
	void setActionText(std::string textInput, std::string textInput2);
	void setHouses(int inputHouses);
	bool upgrade();

	//functions to get values
	std::string getName(int nameIndex);
	int getPropertyCost();
	int getFreeParking();
	bool getMortgaged();
	int getRent();
	int getTax();
	int getOwnership();
	std::string getActionText(int textIndex);
	std::string getType();
	int getHouses();

};