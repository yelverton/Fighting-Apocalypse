#include "HealthBar.h"
#include <iostream>
HealthBar::HealthBar(float xPos, float yPos)
{
	this->rectangleShapes[0].setSize(sf::Vector2f(250.f, 50.f));
	this->rectangleShapes[0].setFillColor(sf::Color::Green);
	//this->rectangleShapes[0].setPosition(50.f, 10.f);
	
	this->rectangleShapes[0].setPosition(xPos, yPos);

	this->rectangleShapes[1].setSize(sf::Vector2f(300.f, 50.f));
	this->rectangleShapes[1].setFillColor(sf::Color::Transparent);
	//this->rectangleShapes[1].setPosition(50.f, 10.f);
	this->rectangleShapes[1].setPosition(xPos, yPos);
	this->rectangleShapes[1].setOutlineColor(sf::Color::White);
	this->rectangleShapes[1].setOutlineThickness(4.f);
}

void HealthBar::update(Character & character)
{
	this->rectangleShapes[0].setSize(sf::Vector2f(float(character.getLives()), 50.f));
	
	/*if (this->rectangleShapes[0].getSize().x >= 300)
	{

		this->rectangleShapes[0].setFillColor(sf::Color::Green);
		
	}*/

	if (this->rectangleShapes[0].getSize().x >= 150)
	{
		this->rectangleShapes[0].setFillColor(sf::Color::Green);
	}
	/*else */else if (this->rectangleShapes[0].getSize().x <= 150 && this->rectangleShapes[0].getSize().x > 75)
	{
		this->rectangleShapes[0].setFillColor(sf::Color::Yellow);
	}
	else if (this->rectangleShapes[0].getSize().x <= 75)
	{
		
		this->rectangleShapes[0].setFillColor(sf::Color::Red);
	}

	if (this->rectangleShapes[0].getSize().x > 300)
	{
		this->rectangleShapes[0].setSize(sf::Vector2f(300.f, 50.f));
	}

	if (this->rectangleShapes[0].getSize().x <= 0)
	{
		this->rectangleShapes[0].setSize(sf::Vector2f(0, 0));
	}

}

HealthBar::~HealthBar()
{
}

void HealthBar::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < 2; i++)
	{
		target.draw(this->rectangleShapes[i]);
	}
}
