#pragma once
#include "HealthBar.h"
#include "TimeHandler.h"

class HUD
{
	static const int CAP = 2;
private:
	HealthBar* healthbars[CAP];
	TimeHandler* timeHandler;
public:
	HUD();
	void updateClock(sf::Clock clock);
	void update(Character characterOne, Character characterTwo);
	void drawAllComponents(sf::RenderTarget & target, sf::RenderStates states) const;
	virtual ~HUD();
};