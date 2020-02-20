#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class GameEntity:public sf::Drawable
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speed;

public:
	GameEntity(float speed, std::string filename);
	float getSpeed()const;
	virtual void spawn(float xPos, float yPos) = 0;
	virtual void update() = 0;
	sf::FloatRect getGlobal();
	void setSpritePosition(float xPos, float yPos);
	void moveSpritePosition(int offSetX, int offSetY);

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};