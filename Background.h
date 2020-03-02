#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Background : public sf::Drawable
{
	static const int CAP = 2;
private:
	sf::Texture texture[CAP];
	sf::Sprite sprite[CAP];
	sf::Music music;

public:
	Background();
	virtual ~Background();
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

};