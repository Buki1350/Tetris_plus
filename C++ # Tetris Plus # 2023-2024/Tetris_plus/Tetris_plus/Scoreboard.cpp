#include "Scoreboard.h"

void Scoreboard::Update()
{
	if (notActive)
	{
		SBM.Load();
		notActive = false;
	}

	Input();
	wasConfirmButtonPressedBefore = Basics::settings.isButtonPressed("Confirm");
}

void Scoreboard::Input()
{
	if (((Basics::settings.isButtonPressed("Confirm")) && !wasConfirmButtonPressedBefore))
	{
		notActive = true;
		Basics::sceneManager.changeScene("Menu");
		wasConfirmButtonPressedBefore = true;
	}
}

void Scoreboard::Draw()
{
	sf::Sprite background(background_texture);
	background.setScale(Basics::getXScale(), Basics::getYScale());
	Basics::window.draw(background);

	exitButton.setTexture(exitButton_texture, exitButton_pressed_texture);
	exitButton.setPosition(Vec2D(Basics::window.getSize().x/2, Basics::window.getSize().y - 100.0f));
	exitButton.isSelected = true;
	exitButton.drawButton();

	for (int i = 1; i < 10; i++)
	{
		if (SBM.scores[i - 1] != 0)
		{
			sf::Text text;
			std::string str = std::to_string(i) + ". " + SBM.dates[i - 1] + "   " + std::to_string(SBM.scores[i - 1]);
			text.setFont(font);
			text.setString(str);
			text.setCharacterSize(characterSize * Basics::getScale());
			text.setPosition(Basics::window.getSize().x/2 - str.size()/2 * characterSize * Basics::getScale(), Basics::window.getSize().y / 8 + i * spacing);
			Basics::window.draw(text);
		}
	}
}

Scoreboard::Scoreboard()
{
	background_texture.loadFromFile("Assets/scoreboardBackground.png");
	exitButton_texture.loadFromFile("Assets/defaultExitButton.png");
	exitButton_pressed_texture.loadFromFile("Assets/chosenExitButton.png");

	font.loadFromFile("Fonts/prstartk.ttf");
}
