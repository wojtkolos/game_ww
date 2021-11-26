#include "DialogBoxes.h"

void DialogBoxes::initDialogBoxes()
{
	this->dialogboxes["EXIT"] = new DialogBox(&this->font, "Are you sure to quit?", "YES", "NO");
	this->dialogboxes["INCOME_TAX"] = new DialogBox(&this->font, "You want to pay?", "$200", "10%");
}

DialogBoxes::DialogBoxes(sf::Font& font)
{
	this->font = font;
	this->initDialogBoxes();
}

DialogBoxes::~DialogBoxes()
{
	for (auto& but : this->dialogboxes)
		delete but.second;
	this->dialogboxes.clear();
}

DialogBox* DialogBoxes::getDialogBox(std::string key)
{
	return this->dialogboxes[key];
}

bool DialogBoxes::isBoxConfirm(std::string key)
{
	return this->dialogboxes[key]->isConfirm();
}

bool DialogBoxes::isBoxCancel(std::string key)
{
	return this->dialogboxes[key]->isCancel();
}

bool DialogBoxes::isBoxActive(std::string key)
{
	return this->dialogboxes[key]->isActive();
}

void DialogBoxes::setBoxActive(std::string key, bool state)
{
	this->dialogboxes[key]->setActive(state);
}

void DialogBoxes::resetBoxState(std::string key)
{
	this->dialogboxes[key]->resetState();
}

void DialogBoxes::update(sf::Vector2f mousePosView)
{
	for (auto& i : dialogboxes)
		if (i.second->isActive())
			i.second->update(mousePosView);
}

void  DialogBoxes::render(sf::RenderTarget* target)
{
	for (auto& it : this->dialogboxes)
	{
		if (it.second->isActive())
			it.second->render(target);
	}
}