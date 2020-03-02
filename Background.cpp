#include "Background.h"
#include <iostream>
Background::Background()
{
	this->texture[0].loadFromFile("../images/dark-grey-background.png");
	this->sprite->setTexture(texture[0]);
	this->sprite->setScale(2, 2);

	this->texture[1].loadFromFile("../images/vulcano.png");
	this->sprite[1].setTexture(texture[1]);
	this->sprite[1].setPosition(0, 100);

	if (!music.openFromFile("../sounds/Mega Man 2 - Dr. Wily's Castle.wav"))
	{
		std::cout << "Error when loading music" << std::endl; //Felhantering vid inladdning av fil
	}
	else
	{
		music.play();
	}


}

Background::~Background()
{
}

void Background::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < CAP; i++)
	{
		target.draw(this->sprite[i]);
	}
	

}
 