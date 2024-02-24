#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Button.h"
#include "ScoreboardManager.h"

class Scoreboard : public Scene
{
private:
	Button exitButton;
	sf::Texture background_texture, exitButton_texture, exitButton_pressed_texture;
	sf::Font font;
	float spacing = 30.0f;
	int characterSize = 12;

	ScoreboardManager SBM;

	void Input();
	bool wasConfirmButtonPressedBefore = true; //FOR MULTIPLE CLICKS BUG
	bool notActive = true;	//FOR REFRESHING DATA
public:
	void Draw();
	void Update();
	Scoreboard();
};

