#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <time.h> 
#include <chrono>
#include <Windows.h>
#include <iostream>
#include "Scene.h"
#include "Tetrominos.h"
#include "ScoreNumber.h"
#include "Button.h"
#include "ScoreboardManager.h"
#include "GameBoard.h"
#include "NextTetroInfo.h"

class ClassicTetris : public Scene
{
private:
	GameBoard gBoard;
	NextTetroInfo NTInfo;

	ScoreboardManager SBManager;
	bool newScoreAdded = false;

	ScoreNumber scoreNum;

	Button exitButton;
	Button againButton;
	int selectedButton = 0;

	//END_SCREEN
	float endScreenLerpTime = 2.0f; //seconds
	float currentEndScreenLerpTime = 0.0f;
	bool endScreenCreated = false;
	int selectedEndOption = 0; //prevent for not clicking "start" in menu again 
	sf::Sprite endScreenBackground;
	sf::Sprite gameOverText;
	sf::Sprite newBestScoreText;


	//TEXTURES
	sf::Texture backgroundTexture;
	sf::Texture nextTetroBoxTexture;
	sf::Texture endScreenTexture;
	sf::Texture gameOverTextTexture;
	sf::Texture exitButtonTexture;
	sf::Texture selectedExitButtonTexture;
	sf::Texture againButtonTexture;
	sf::Texture selectedAgainButtonTexture;
	sf::Texture newBestScore_texture;

	void initVariables(); //
	void loadTextures();
	void drawBackground();//

	void endScreenInput();

	void gameOverScreen(std::string Hide_or_Show);
public:
	void update();
	void drawScene();

	ClassicTetris();
	~ClassicTetris();

};