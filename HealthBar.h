#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class HealthBar : public sf::Drawable
{
private:
	sf::RectangleShape rectangleShapes[2];
public:
	HealthBar(float xPos, float yPos);
	void update(Character &character);
	virtual ~HealthBar();

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};