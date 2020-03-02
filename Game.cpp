#include "Game.h"

void Game::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (this->characterVector[0]->isUnableToMove() == false)
			switch (event.key.code)
			{

			case sf::Keyboard::R:
				this->characterVector[0]->lightPunch();
					break;
			case sf::Keyboard::T:
				this->characterVector[0]->hardKick();
				break;
			case sf::Keyboard::Y:
				this->characterVector[0]->specialAttack();
				break;
			case sf::Keyboard::Escape:
				//exit(0);
				window.close();
			case sf::Keyboard::U:
				this->characterVector[0]->decreaseLives(10);
				break;
			case sf::Keyboard::I:
				this->characterVector[0]->increaseLives(10);
				break;
			case sf::Keyboard::W:
				this->characterVector[0]->jump();
			default:
				break;
			}
			if (this->characterVector[1]->isUnableToMove() == false)
			switch (event.key.code)
			{

			

			case sf::Keyboard::Numpad1:
				this->characterVector[1]->lightPunch();
				break;
			case sf::Keyboard::Numpad2:
				this->characterVector[1]->hardKick();
				break;
			case sf::Keyboard::Numpad3:
				this->characterVector[1]->specialAttack();
				break;
			case sf::Keyboard::Up:
				this->characterVector[1]->jump();
				
				break;
			
			default:
				break;
			}


		}
		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			
			

			default:
				break;
			}
		}
	}
}

void Game::update()
{

	this->timeHandler->update(clock);
	elapsedTimeSinceLastUpdate += clock.restart();
	while (elapsedTimeSinceLastUpdate > timePerFrame)
	{
		this->dt = clock.restart().asSeconds();
		elapsedTimeSinceLastUpdate -= timePerFrame;
		
		this->characterVector[0]->animationSpriteUpdate();
		this->characterVector[1]->animationSpriteUpdate();
		//this->characterVector[0]->setSpritePosition(100, 300);
		for (int i = 0; i < characterVector.size(); i++)
		{
			this->characterVector[i]->update(/*dt*/);
		}
		
		//timeHandler->update();

		this->healthBar->update(*this->characterVector[0]);

		if (this->characterVector[0]->getSpritePos().x < this->characterVector[1]->getSpritePos().x && this->characterVector[0]->getScale().x <0)
		{
			this->characterVector[0]->flipSprite();
			this->characterVector[1]->flipSprite();
			std::cout<< "asd" << std::endl;
			
		}

		characterVector[0]->collisionBetweenCharacters(*this->characterVector[1]);

		if (this->characterVector[0]->getSpritePos().x > this->characterVector[1]->getSpritePos().x && this->characterVector[0]->getScale().x > 0)
		{
			this->characterVector[0]->flipSprite();
			this->characterVector[1]->flipSprite();
		}
		/*if (this->characterVector[1]->getSpritePos().y < 520)
		{
			this->characterVector[1]->isInAir();
		}
		if (this->characterVector[1]->getSpritePos().y > 520)
		{
			this->characterVector[1]->setSpritePosition(this->characterVector[1]->getSpritePos().x, 520);
		}*/

		

	}
}

void Game::render()
{
	window.clear();
	/*window.draw(*this->playerOnePtr);*/
	window.draw(*this->background);
	for (int i = 0; i < characterVector.size(); i++)
	{
		window.draw(*this->characterVector[i]);
	}
	//window.draw(this->hud.)
	window.draw(*this->timeHandler);
	window.draw(*this->healthBar);

	window.display();
}

Game::Game()
	:window(sf::VideoMode(WIDTH,HEIGHT),"Fighting Apocalypse"),
	timePerFrame(sf::seconds(1.0f/60.0f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)/*, playerOnePtr(new Character(0))*/
{
	this->dt = 0;
	this->timeHandler = new TimeHandler();
	characterVector.push_back(new Character(0));
	characterVector.push_back(new Character());
	this->healthBar = new HealthBar(50.f, 10.f);
	this->background = new Background();
	window.setKeyRepeatEnabled(false);
}


void Game::run()
{
	while (window.isOpen())
	{
		handleEvents();
		update();
		render();
	}
}

Game::~Game()
{
	/*delete this->playerOnePtr;*/

	for (int i = 0; i < this->characterVector.size(); i++)
	{
		delete this->characterVector[i];
	}

	delete this->timeHandler;
	delete this->healthBar;
	delete this->background;
	/*delete this->characterVector;*/
}
