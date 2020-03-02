#pragma once
#include <SFML/Graphics.hpp>

class Hitbox : public sf::Drawable
{
private:
	sf::RectangleShape hitbox;
	sf::Sprite &sprite;
	float spriteX;
	float spriteY;
public:
	Hitbox(float spriteX, float spriteY, sf::Sprite& sprite, float spriteWidth, float spriteHeight);
	virtual ~Hitbox();
	// Inherited via Drawable
	void setHitboxSize(float x, float y);
	void update();
	sf::FloatRect getBounds() const;



	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

};