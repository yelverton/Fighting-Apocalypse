#pragma once
#include "GameEntity.h"

class Character :public GameEntity
{
private:
	int lives;
	int player;

public:
	Character(float speed, int player=1);

	int getLives();
	void decreaseLives();
	void increaseLives();

	// Inherited via GameEntity
	virtual void spawn(float xPos, float yPos) override;
	virtual void update() override;
};