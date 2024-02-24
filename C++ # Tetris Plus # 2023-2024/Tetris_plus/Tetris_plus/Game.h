#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <chrono>
#include "Basics.h"
#include "Menu.h"
#include "Time.h"
#include "ClassicTetris.h"
#include "Scoreboard.h"

class Game
{
private:
	int timeInMicros;

	Menu menu;
	ClassicTetris classicTetris;
	Scoreboard scoreboard;

	std::string initialScene = "Menu";

	float timeSinceLastFrame = 0.0f;
	std::chrono::high_resolution_clock::time_point timer;
public:	
	void initVariables();
	bool isRunning();
	void pollEvent();
	void update();
	void render();

	Game();
	~Game();
};

