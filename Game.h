#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <vector>
#include "TimeHandler.h"
#include "HealthBar.h"
#include "Background.h"
#include <iostream>

#include "HUD.h"

class Game
{
public:
	static const int HEIGHT = 600;
	static const int WIDTH = 900;
private:
	sf::Clock clock;
	sf::Time elapsedTimeSinceLastUpdate;
	sf::Time timePerFrame;

	Character* playerOnePtr;
	float dt;
	std::vector<Character*> characterVector;
	TimeHandler* timeHandler;
	HealthBar* healthBar;
	Background* background;

	//HUD* hud;

	sf::RenderWindow window;
	void handleEvents();
	void update();
	void render();
public:
	Game();
	void run();
	virtual ~Game();
};