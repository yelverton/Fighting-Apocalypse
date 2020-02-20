#include "Character.h"

Character::Character(float speed, int player)
	:GameEntity(speed, "0"), player(player)
{
}

int Character::getLives()
{
	return lives;
}

void Character::decreaseLives()
{
	--lives;
}

void Character::increaseLives()
{
	++lives;
}

void Character::spawn(float xPos, float yPos)
{
	setSpritePosition(xPos, yPos);
}

void Character::update()
{
	if (player != 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			moveSpritePosition(0, -1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			moveSpritePosition(0, 1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			moveSpritePosition(1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			moveSpritePosition(-1, 0);
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			moveSpritePosition(0, -1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			moveSpritePosition(0, 1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			moveSpritePosition(1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			moveSpritePosition(-1, 0);
		}
	}
}
