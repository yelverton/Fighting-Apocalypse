#include "TimeHandler.h"

TimeHandler::TimeHandler()
	:elapsedTime(sf::Time::Zero)
{
	this->gameTime = sf::seconds(91.f);
	this->font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	this->text.setFont(font);
	this->rectShapes[0] = sf::RectangleShape(sf::Vector2f(150.f, 50.f));
	this->rectShapes[0].setPosition(400.f, 4.f);
	this->rectShapes[0].setFillColor(sf::Color::Transparent);
	this->rectShapes[0].setOutlineThickness(4.f);
	this->rectShapes[0].setOutlineColor(sf::Color::White);
	this->text.setPosition(410.f, 10.f);
	//this->rectShapes[1] = sf::RectangleShape(sf)
}

bool TimeHandler::gameIsOngoing() const
{
	return this->gameTime.asSeconds() > 0.f;
}

TimeHandler::~TimeHandler()
{
}

void TimeHandler::update(const sf::Clock clock)
{
	if (gameTime.asSeconds() > 0)
	{
		this->gameTime -= clock.getElapsedTime();
		this->text.setString("Time: " + std::to_string(int(gameTime.asSeconds())));
		if (this->gameTime.asSeconds() <= 10)
		{
			this->text.setFillColor(sf::Color::Red);
		}
	}
}

void TimeHandler::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->text);

	for (int i = 0; i < 4; i++)
	{
		target.draw(this->rectShapes[i]);
	}
}
