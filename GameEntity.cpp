#include "GameEntity.h"

GameEntity::GameEntity(float speed, std::string filename)
	:speed(speed)
{
	texture.loadFromFile("../Images/" + filename + "/.png");
	sprite.setTexture(this->texture);
}

float GameEntity::getSpeed() const
{
	return speed;
}

sf::FloatRect GameEntity::getGlobal()
{
	return sprite.getGlobalBounds();
}

void GameEntity::setSpritePosition(float xPos, float yPos)
{
	this->sprite.setPosition(xPos, yPos);
}

void GameEntity::moveSpritePosition(int offSetX, int offSetY)
{
	this->sprite.move(offSetX * speed, offSetY * speed);
}

void GameEntity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite);
}
