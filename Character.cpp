#include "Character.h"
#include <iostream>
#include <string>
Character::Character(int player)
	:GameEntity(4.0f, "ken", player), player(player), lives(300), hitBoxHead(this->getSpriteGlobal().left, this->getSpriteGlobal().top, 50.f, 50.f)
{
	
	if (player != 0)
	{
		this->spawn(700, 520);
		//this->setSpriteRotation(45);
		this->flipSprite();
	}
	else
	{
		this->spawn(100, 520);
	}
	jumpVelocity = 0;
	xDir = 0;
	yDir = 0;
	isGrounded = true;
}

int Character::getLives()
{
	return this->lives;
}

void Character::decreaseLives(int amountToDecrease)
{
	if (this->lives > 0)
	{
		this->lives -= amountToDecrease;
	}
	
}

void Character::increaseLives(int amountToIncrease)
{
	std::cout << this->lives << std::endl;
	if (this->lives < 300)
	{
		this->lives += amountToIncrease;
	}
	
}

void Character::collisionBetweenCharacters(Character & other)
{
	if (this->getHurtbox().intersects(other.getHitbox()))
	{
		std::cout << "hej" << std::endl;
		this->decreaseLives(10);
	}
}

void Character::lightPunch()
{

	changeAnimation(2,3,10,1);

	animationSpriteUpdate();
}

void Character::hardKick()
{
	changeAnimation(6, 5, 13,1);

	animationSpriteUpdate();
}

void Character::walkRight()
{
	walkingTrue();
	changeAnimation(3, 5, 10,0);
	animationSpriteUpdate();
}

void Character::specialAttack()
{
	changeAnimation(0, 4, 12,1);
	animationSpriteUpdate();
}

void Character::crouch()
{
	changeAnimation(9, 1, 4,1);
	animationSpriteUpdate();
	
}

void Character::jump()
{
	setVelocity(-3);
	jumpVelocity = -3;
	changeAnimation(8, 2, 7, 1);
	animationSpriteUpdate();
	std::cout << xDir << std::endl;
	moveSpritePosition(xDir, jumpVelocity);
	isJumping(!isGrounded);
}

void Character::isInAir()
{

	moveSpritePosition(xDir, jumpVelocity);
	jumpVelocity += 0.090f;
	setVelocity(jumpVelocity);
		isJumping(!isGrounded);
	//std::cout << "asd" << std::endl;
}



void Character::spawn(float xPos, float yPos)
{
	setSpritePosition(xPos, yPos);
}

void Character::update()
{
	updateHurtbox();
	updateHitbox();
	if (getSpritePos().y < 520)
	{
		//if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		isInAir();
		isGrounded = false;

		
	}
	else
	{
		isGrounded = true;
		if (getSpritePos().y > 520)
		{
			setSpritePosition(getSpritePos().x, 520);
		}
		jumpVelocity = 0;
		setVelocity(0);
		isJumping(!isGrounded);
	}
	if (isUnableToMove() == false)
	{
		if (isGrounded == true)
		{


			if (player != 0)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					xDir = 1;

					walkRight();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					xDir = -1;

					walkRight();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					xDir = 0;
					crouch();
					
				}
				else
				{
					walkingFalse(5);
					xDir = 0;

				}

			}
			else
			{

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					xDir = 1;

					walkRight();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					xDir = -1;

					walkRight();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					xDir = 0;
					crouch();
				}
				else
				{
					walkingFalse(5);
					xDir = 0;
				}
			}
			moveSpritePosition(xDir, yDir);
		}
		
	}
}
