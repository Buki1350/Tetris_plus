#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Button.h"
#include "Settings.h"


class Menu : public Scene
{
private:
	Button startButton, scoreBoardButton, exitButton;
	int numberOfButtons = 3;
	int chosenButton = 1;
	int prevChosenButton = 1;
	bool wasConfirmButtonPressedBefore;
	
	void inicializeVariables();
	void loadTextures();
	void drawBackground();
	void drawButtons();
	void buttonsActions();

public:
	void drawScene();
	void update();

	Menu();
	~Menu();
};

