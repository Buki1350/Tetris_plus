#include "Game.h"

bool Game::isRunning()
{
	return Basics::window.isOpen();
}

void Game::initVariables()
{
	Basics::window.create(sf::VideoMode(Basics::settings.windowSettings.window_width, Basics::settings.windowSettings.window_height), Basics::settings.windowSettings.window_title);
	Basics::sceneManager.changeScene(initialScene);

	timer = std::chrono::high_resolution_clock::now();
}

void Game::pollEvent()
{
	sf::Event event;

	Basics::window.pollEvent(event);

	switch (event.type)
	{
	case sf::Event::Closed:
		Basics::window.close();
		break;
	case sf::Event::KeyPressed:

		if (Basics::settings.isButtonPressed("Exit") && (Basics::sceneManager.getCurrentScene() == "Menu"))
			Basics::window.close();
		break;
	case sf::Event::Resized:
		sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
		Basics::window.setView(sf::View(visibleArea));
		break;
	}
}

void Game::update()
{
	Basics::myTime.UpdateTime();

	if (Basics::sceneManager.getCurrentScene() == "Menu")
		menu.update();
	if (Basics::sceneManager.getCurrentScene() == "ClassicTetris")
		classicTetris.update();
	if (Basics::sceneManager.getCurrentScene() == "Scoreboard")
		scoreboard.Update();

}

void Game::render()
{
	Basics::window.clear();

	if (Basics::sceneManager.getCurrentScene() == "Menu")
		menu.drawScene();
	if (Basics::sceneManager.getCurrentScene() == "ClassicTetris")
		classicTetris.drawScene();
	if (Basics::sceneManager.getCurrentScene() == "Scoreboard")
		scoreboard.Draw();

	Basics::window.display();
}

Game::Game()
{
	initVariables();
}

Game::~Game()
{
}

