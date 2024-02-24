#include "Menu.h"

void Menu::drawBackground()
{
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Assets/menuBackground.png");
	sf::Sprite backgroundSprite(backgroundTexture);
	backgroundSprite.setScale(Basics::getXScale(), Basics::getYScale());
	Basics::window.draw(backgroundSprite);
}

void Menu::drawButtons()
{
	startButton.setPosition(Vec2D(Basics::window.getSize().x / 2, Basics::window.getSize().y / 2 - (2 * startButton.getHeight())));
	startButton.isSelected = chosenButton == 1;
	startButton.drawButton();

	scoreBoardButton.setPosition(Vec2D(Basics::window.getSize().x / 2, Basics::window.getSize().y / 2));
	scoreBoardButton.isSelected = chosenButton == 2;
	scoreBoardButton.drawButton();

	exitButton.setPosition(Vec2D(Basics::window.getSize().x / 2, Basics::window.getSize().y / 2 + (2 * startButton.getHeight())));
	exitButton.isSelected = chosenButton == 3;
	exitButton.drawButton();
}

void Menu::buttonsActions()
{

	if (Basics::settings.isButtonPressed("Down"))
	{
		if (prevChosenButton == chosenButton)
		{
			if (chosenButton < numberOfButtons)
				chosenButton++;
		}
	}
	else if (Basics::settings.isButtonPressed("Up"))
	{
		if (prevChosenButton == chosenButton)
		{
			if (chosenButton > 1)
				chosenButton--;
		}
	}
	else
		prevChosenButton = chosenButton;

	
	if (Basics::settings.isButtonPressed("Confirm") && !wasConfirmButtonPressedBefore)
	{
		switch (chosenButton)
		{
		case 1:
			Basics::sceneManager.changeScene("ClassicTetris");
			break;
		case 2:
			Basics::sceneManager.changeScene("Scoreboard");
			break;
		case 3:
			Basics::window.close();
		}
	}

	wasConfirmButtonPressedBefore = Basics::settings.isButtonPressed("Confirm");
}

void Menu::inicializeVariables()
{
	startButton.setSize(100, 30);
	scoreBoardButton.setSize(100, 30);
	startButton.isResponsive(true);
	scoreBoardButton.isResponsive(true);
	exitButton.isResponsive(true);
	//chosenButton = 1;
	
	wasConfirmButtonPressedBefore = Basics::settings.isButtonPressed("Confirm");
	//prevChosenButton = 1;
}

void Menu::loadTextures()
{
	sf::Texture startButtonDefaultTexture;
	startButtonDefaultTexture.loadFromFile("Assets/defaultStartButton.png");
	sf::Texture startButtonSelectedTexture;
	startButtonSelectedTexture.loadFromFile("Assets/chosenStartButton.png");
	startButton.setTexture(startButtonDefaultTexture, startButtonSelectedTexture);

	sf::Texture scoreButtonDefaultTexture;
	scoreButtonDefaultTexture.loadFromFile("Assets/defaultScoreButton.png");
	sf::Texture scoreButtonSelectedTexture;
	scoreButtonSelectedTexture.loadFromFile("Assets/chosenScoreButton.png");
	scoreBoardButton.setTexture(scoreButtonDefaultTexture, scoreButtonSelectedTexture);

	sf::Texture exitButton_texture;
	exitButton_texture.loadFromFile("Assets/defaultExitButton.png");
	sf::Texture exitButton_pressed_texture;
	exitButton_pressed_texture.loadFromFile("Assets/chosenExitButton.png");
	exitButton.setTexture(exitButton_texture, exitButton_pressed_texture);
}

void Menu::drawScene()
{
	drawBackground();
	drawButtons();
	controllerStatus();
}

void Menu::update()
{
	buttonsActions();
}

Menu::Menu()
{
	inicializeVariables();
	loadTextures();
}

Menu::~Menu()
{
}
