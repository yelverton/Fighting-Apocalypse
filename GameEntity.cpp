#include "GameEntity.h"
#include "SpriteRow.h"
#include <iostream>
GameEntity::GameEntity(float speed, std::string filename, int player)
	:speed(speed), timeCounter(0), updateTime(15), player(player)
{
	this->walking = false;
	nrOfTotalColumns = 7;
	texture.loadFromFile("../Images/" + filename + ".png");
	sprite.setTexture(this->texture);
	this->intRect = sf::IntRect(0, 0, this->texture.getSize().x / nrOfTotalColumns , 80/*this->texture.getSize().y / 10*/);//write this when you have a real sprite sheet this->texture.getSize().x / 10,
	this->sprite.setTextureRect(this->intRect);
	animationActive = false;
	frameCounter = 0;
	std::cout << texture.getSize().y << std::endl;
	doNotMoveDuringAnimation = false;
	this->jumpVelocity = 0;
	counterBecauseFrameCounterDidNotWork = 0;
	createHurtbox(this->sprite);
	createHitbox(this->sprite);
}

void GameEntity::createHurtbox(sf::Sprite & sprite)
{
	this->hurtboxPtr = new Hurtbox(15, 0, this->sprite, this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height);
}

void GameEntity::createHitbox(sf::Sprite & sprite)
{
	this->hitboxPtr = new Hitbox(15, 0, this->sprite, this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height);
}

void GameEntity::setSpriteRotation(float angle)
{
	this->sprite.setRotation(angle);
}

float GameEntity::getSpeed() const
{
	return this->speed;
}

sf::FloatRect GameEntity::getSpriteGlobal() const
{
	return this->sprite.getGlobalBounds();
}

sf::Vector2f GameEntity::getSpritePos() const
{
	return this->sprite.getPosition();
}


sf::FloatRect GameEntity::getHurtbox() const
{
	if (this->hurtboxPtr != nullptr)
		return this->hurtboxPtr->getBounds();
}

sf::FloatRect GameEntity::getHitbox() const
{
	if (this->hitboxPtr != nullptr)
		return this->hitboxPtr->getBounds();
}

void GameEntity::setSpritePosition(float xPos, float yPos)
{
	this->sprite.setPosition(xPos, yPos);
}

void GameEntity::moveSpritePosition(float offSetX, float offSetY)
{
	this->sprite.move(offSetX * speed, offSetY * speed);

	if (this->sprite.getPosition().x < 0.f)
	{
		this->sprite.setPosition(0.f, this->getSpritePos().y);
	}
	else if (this->sprite.getPosition().x + this->getSpriteGlobal().width > 900)
	{
		this->sprite.setPosition(900 - this->sprite.getGlobalBounds().width, this->sprite.getPosition().y);
	}
}

void GameEntity::changeAnimation(int row, int nrOfColumns, int frames, int priority)
{
	
	this->intRect.top = this->intRect.height * (row);
	if (priority > 0)
	{
		doNotMoveDuringAnimation = true;
		walking = false;
	}
	counterBecauseFrameCounterDidNotWork = 0;
	this->attackFrameLength = frames;
	animationActive = true;
	this->thisAnimationColumnsNr = nrOfColumns;
	
	if (walking == false)
	{
		this->intRect.left = 0;
		this->timeCounter = 0;
		

	}
	
	
}

void GameEntity::animationSpriteUpdate()
{

	/*if (sf::Keyboard::isKeyPressed(weakAttack))
	{
		
		this->intRect.top = this->intRect.height * ((int)SpriteRow::ATTACK);
		this->attackFrameLength = 4;
	}*/
	if (animationActive == false)
	{
		this->intRect.top = this->intRect.height * (1);
		
		this->attackFrameLength = 10;
		thisAnimationColumnsNr = 4;
		
	}


		this->timeCounter = (this->timeCounter + 1) % this->attackFrameLength;

		if (this->timeCounter == 0 && !jumping)
		{
	
			
				this->intRect.left = (this->intRect.left + this->intRect.width) % ((int)this->texture.getSize().x/nrOfTotalColumns * thisAnimationColumnsNr);
			

			

			if (animationActive == true  && walking == false)
			{
				frameCounter++;
				
			}
		

		
		}
		if (jumping == true  )
		{
			if (this->timeCounter == 0 && counterBecauseFrameCounterDidNotWork <2)
			{
				this->intRect.left = (this->intRect.left + this->intRect.width) % ((int)this->texture.getSize().x / nrOfTotalColumns * thisAnimationColumnsNr);
				counterBecauseFrameCounterDidNotWork++;
			}
		
			
			if (counterBecauseFrameCounterDidNotWork >= 2)
			{
				if (jumpVelocity < -0.5)
				{
					this->intRect.left = ( this->intRect.width*3);
				}
				else if (jumpVelocity >= -0.5 && jumpVelocity <= 0.5)
				{
					this->intRect.left = (this->intRect.width * 4);
				}
				else if ( jumpVelocity > 0.5 && sprite.getPosition().y < 480)
				{
					this->intRect.left = (this->intRect.width * 5);
				}
				else if (jumpVelocity > 0 && sprite.getPosition().y >= 480  &&sprite.getPosition().y < 500)
				{
					this->intRect.left = (this->intRect.width * 2);
			
				}
				
				if (sprite.getPosition().y >= 500 && sprite.getPosition().y < 520)
				{

					this->intRect.left = (this->intRect.width * 1);
				
				}
				else if (sprite.getPosition().y >= 520)
				{

					
					frameCounter = thisAnimationColumnsNr;
					jumping = false;
				}
			}
		




		}
		
		
	if(frameCounter >= thisAnimationColumnsNr && animationActive == true )
	{
		std::cout << jumping << std::endl;
		this->intRect.left = (this->intRect.width );
		animationActive = false;
		doNotMoveDuringAnimation = false;
		frameCounter = 0;
		
	}
	
	this->sprite.setTextureRect(this->intRect);

	

}

sf::Vector2f GameEntity::getScale()
{
	return this->sprite.getScale();
}

void GameEntity::walkingTrue()
{
	this->walking = true;
}

void GameEntity::walkingFalse(int stopMoving)
{
	if (walking == true)
	{

	
		frameCounter = stopMoving;
		intRect = sf::IntRect(0, intRect.top, intRect.width, intRect.height);
	
	}
	this->walking = false;
	
}

bool GameEntity::isAnimationActive()
{
	return animationActive;
}

sf::IntRect GameEntity::getTextRect()
{
	return this->sprite.getTextureRect();
}

bool GameEntity::isUnableToMove()
{
	return doNotMoveDuringAnimation;
}

void GameEntity::setVelocity(float velocity)
{
	this->jumpVelocity = velocity;
	
}

void GameEntity::isJumping(bool jumping)
{
	this->jumping = jumping;

}


void GameEntity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite);
	if (this->hurtboxPtr)
		this->hurtboxPtr->draw(target, states);
	if (this->hitboxPtr)
		this->hitboxPtr->draw(target, states);
	
}

void GameEntity::flipSprite()
{
	
	
	if (this->sprite.getScale().x > 0)
	{
		this->sprite.setScale(-1, 1.f);
		this->sprite.setOrigin(this->sprite.getTextureRect().width,0);
	}
	else
	{
		this->sprite.setScale(1, 1.f);
		this->sprite.setOrigin(0, 0);
	}
	std::cout << this->sprite.getOrigin().x << std::endl;
	std::cout << this->sprite.getScale().x << std::endl;
}

void GameEntity::updateHurtbox()
{
	this->hurtboxPtr->update();
}

void GameEntity::updateHitbox()
{
	this->hitboxPtr->update();
}
