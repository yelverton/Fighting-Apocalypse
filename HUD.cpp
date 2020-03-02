#include "HUD.h"

HUD::HUD()
{
	this->timeHandler = new TimeHandler();

	this->healthbars[0] = new HealthBar(50.f, 10.f);
	this->healthbars[1] = new HealthBar(500, 10.f);
}

void HUD::updateClock(sf::Clock clock)
{
	this->timeHandler->update(clock);
}

void HUD::update(Character characterOne, Character characterTwo)
{
	this->healthbars[0]->update(characterOne);
	this->healthbars[0]->update(characterTwo);
}

void HUD::drawAllComponents(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < CAP; i++)
	{
		healthbars[i]->draw(target, states);
	}
	
	timeHandler->draw(target, states);
}

HUD::~HUD()
{
	for (int i = 0; i < CAP; i++)
	{
		delete this->healthbars[i];
	}

	delete this->timeHandler;

}
