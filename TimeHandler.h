#pragma once
#include <SFML/Graphics.hpp>

class TimeHandler : public sf::Drawable
{
private:
	sf::Text text;
	sf::Font font;
	sf::Time elapsedTime;
	sf::Time gameTime;
	sf::RectangleShape rectShapes[4];
public:
	TimeHandler();
	bool gameIsOngoing() const;
	virtual ~TimeHandler();
	void update(const sf::Clock clock);
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};