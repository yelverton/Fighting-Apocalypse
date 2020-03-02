#include "Hurtbox.h"
#include <iostream>
Hurtbox::Hurtbox(float spriteX, float spriteY, sf::Sprite & sprite, float spriteWidth, float spriteHeight)
	:sprite(sprite), spriteX(spriteX), spriteY(spriteY)
{
	this->hurtbox.setPosition(sprite.getPosition().x + spriteX, sprite.getPosition().y + spriteY);
	//this->hitbox.setSize(sf::Vector2f(spriteWidth, spriteHeight));
	this->hurtbox.setSize(sf::Vector2f(38.f, spriteHeight));
	this->hurtbox.setFillColor(sf::Color::Transparent);
	this->hurtbox.setOutlineColor(sf::Color::Red);
	this->hurtbox.setOutlineThickness(1.f);
	
}

bool Hurtbox::collision(const sf::FloatRect & other) const
{
	return this->hurtbox.getGlobalBounds().intersects(other);
}

void Hurtbox::setHurtboxSize(float x, float y)
{
	this->hurtbox.setSize(sf::Vector2f(x, y));
}

void Hurtbox::update()
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->hurtbox.setSize(sf::Vector2f(40.f, 54.f));
		this->hurtbox.setPosition(this->sprite.getPosition().x + spriteX, this->sprite.getPosition().y + 25.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->hurtbox.setSize(sf::Vector2f(65.f, 80.f));
		this->hurtbox.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y + this->spriteY);
	}
	else
	{
		this->hurtbox.setSize(sf::Vector2f(38.f, this->sprite.getGlobalBounds().height));
		this->hurtbox.setPosition(this->sprite.getPosition().x + spriteX, this->sprite.getPosition().y + this->spriteY);
	}


	//this->hitbox.setPosition(this->sprite.getPosition().x + spriteX, this->sprite.getPosition().y + this->spriteY);
	
}

sf::FloatRect Hurtbox::getBounds() const
{
	return this->hurtbox.getGlobalBounds();
}

Hurtbox::~Hurtbox()
{
}

void Hurtbox::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->hurtbox);
}
