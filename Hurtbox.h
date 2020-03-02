#pragma once
#include <SFML/Graphics.hpp>


class Hurtbox : public sf::Drawable
{
private:
	sf::RectangleShape hurtbox;
	sf::Sprite &sprite;
	float spriteX;
	float spriteY;
public:
	
	Hurtbox(float spriteX, float spriteY, sf::Sprite& sprite, float spriteWidth, float spriteHeight);
	bool collision(const sf::FloatRect &other) const;
	void setHurtboxSize(float x, float y);
	void update();
	sf::FloatRect getBounds() const;
	virtual ~Hurtbox();


	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

};