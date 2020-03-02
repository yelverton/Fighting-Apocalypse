#pragma once
#include "GameEntity.h"

class Character :public GameEntity
{
private:
	int lives;
	int player;
	sf::FloatRect hitBoxHead;
	float jumpVelocity;
	float xDir;
	float yDir ;
	bool isGrounded;

public:
	Character(int player=1);

	int getLives();
	void decreaseLives(int amountToDecrease);
	void increaseLives(int amountToIncrease);
	
	void collisionBetweenCharacters(Character& other);

	void lightPunch();
	void hardKick();
	void walkRight();
	void specialAttack();
	void crouch();
	void jump();
	void isInAir();
	
	// Inherited via GameEntity
	virtual void spawn(float xPos, float yPos) override;
	virtual void update() override;
};