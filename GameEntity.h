#pragma once
#include <SFML/Graphics.hpp>
#include "Hurtbox.h"
#include "Hitbox.h"
#include <string>

class GameEntity:public sf::Drawable
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect intRect;
	//Hitbox* hitboxPtr;
	Hurtbox* hurtboxPtr;
	Hitbox* hitboxPtr;

	float speed;
	int updateTime;
	int player;
	int timeCounter;
	int attackFrameLength;
	bool animationActive;
	int nrOfTotalColumns;
	int thisAnimationColumnsNr;
	int frameCounter;
	bool walking;
	bool doNotMoveDuringAnimation;
	float jumpVelocity;
	bool jumping;
	int priority;
	int counterBecauseFrameCounterDidNotWork;
	
public:
	GameEntity(float speed, std::string filename, int player = 1);
	void createHurtbox(sf::Sprite &sprite);
	void createHitbox(sf::Sprite &sprite);
	void setSpriteRotation(float angle);
	float getSpeed() const;
	virtual void spawn(float xPos, float yPos) = 0;
	virtual void update(/*float delta*/) = 0;
	sf::FloatRect getSpriteGlobal() const;
	sf::Vector2f getSpritePos() const;
	sf::FloatRect getHitbox() const;
	sf::FloatRect getHurtbox() const;

	void setSpritePosition(float xPos, float yPos);
	void moveSpritePosition(float offSetX, float offSetY);
	void changeAnimation(int row,int nrOfColumns ,int frames, int priority);
	void animationSpriteUpdate();
	sf::Vector2f getScale();
	void walkingTrue();
	void walkingFalse(int stopMoving);
	bool isAnimationActive();
	sf::IntRect getTextRect();
	bool isUnableToMove();
	void setVelocity(float velocity);
	void isJumping(bool jumping);
	//void changeAnimationStartPos(int startColumn);
	
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void flipSprite();

protected:
	void updateHurtbox();
	void updateHitbox();
};