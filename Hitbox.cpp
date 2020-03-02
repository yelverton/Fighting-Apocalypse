#include "Hitbox.h"

Hitbox::Hitbox(float spriteX, float spriteY, sf::Sprite & sprite, float spriteWidth, float spriteHeight)
	:sprite(sprite), spriteX(spriteX), spriteY(spriteY)
{
	this->hitbox.setPosition(sprite.getPosition().x + spriteX, sprite.getPosition().y + spriteY);
	//this->hitbox.setSize(sf::Vector2f(spriteWidth, spriteHeight));
	this->hitbox.setSize(sf::Vector2f(38.f, spriteHeight));
	this->hitbox.setFillColor(sf::Color::Transparent);
	
	this->hitbox.setOutlineColor(sf::Color::Blue);
	this->hitbox.setOutlineThickness(1.f);
}

Hitbox::~Hitbox()
{
}

void Hitbox::setHitboxSize(float x, float y)
{
	this->hitbox.setSize(sf::Vector2f(x, y));
}

void Hitbox::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
	{
		this->hitbox.setSize(sf::Vector2f(20.f, 5.f));
		this->hitbox.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y + 15.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
	{
		this->hitbox.setSize(sf::Vector2f(15.f, 10.f));
		this->hitbox.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y);
	}
	else
	{
		this->hitbox.setSize(sf::Vector2f(38.f, this->sprite.getGlobalBounds().height));
		this->hitbox.setPosition(/*this->sprite.getPosition().x + spriteX, this->sprite.getPosition().y + this->spriteY*/ -100.f, -100.f);
	}
}

sf::FloatRect Hitbox::getBounds() const
{
	return this->hitbox.getGlobalBounds();
}

void Hitbox::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->hitbox);
}


