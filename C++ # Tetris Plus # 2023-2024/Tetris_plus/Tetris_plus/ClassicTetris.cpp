#include "ClassicTetris.h"

void ClassicTetris::initVariables()
{
	srand(time(NULL));

	SBManager.Load();

	NTInfo.LinkWithBoard(&gBoard);

	exitButton.isResponsive(true);
	againButton.isResponsive(true);
	gBoard.NewBoard();
}

void ClassicTetris::loadTextures()
{
	backgroundTexture.loadFromFile("Assets/classicTetrisBackground.png");
	nextTetroBoxTexture.loadFromFile("Assets/nextTetroBox.png");
	endScreenTexture.loadFromFile("Assets/classicTetrisEndScreen.png");
	gameOverTextTexture.loadFromFile("Assets/gameOverText.png");
	exitButtonTexture.loadFromFile("Assets/defaultExitButton.png");
	selectedExitButtonTexture.loadFromFile("Assets/chosenExitButton.png");
	againButtonTexture.loadFromFile("Assets/defaultAgainButton.png");
	selectedAgainButtonTexture.loadFromFile("Assets/chosenAgainButton.png");
	newBestScore_texture.loadFromFile("Assets/newBestScore.png");

	endScreenBackground.setTexture(endScreenTexture);
	gameOverText.setTexture(gameOverTextTexture);

	againButton.setTexture(againButtonTexture, selectedAgainButtonTexture);
	exitButton.setTexture(exitButtonTexture, selectedExitButtonTexture);

	newBestScoreText.setTexture(newBestScore_texture);
}

void ClassicTetris::drawBackground()
{
	sf::Texture _backgroundTexture;
	_backgroundTexture = backgroundTexture;
	sf::Sprite backgroundSprite(_backgroundTexture);
	backgroundSprite.setScale(Basics::getXScale(), Basics::getYScale());
	Basics::window.draw(backgroundSprite);
}

void ClassicTetris::gameOverScreen(std::string Hide_or_Show)
{
	if (!endScreenCreated)
	{
		endScreenBackground.setPosition(0, Basics::window.getSize().y);
		endScreenCreated = true;
	}

	if (Hide_or_Show == "Show")
	{
		if (currentEndScreenLerpTime < endScreenLerpTime)
		{
			endScreenBackground.move(0, -(cos(currentEndScreenLerpTime / endScreenLerpTime * 2 * M_PI + M_PI) / 2 + 0.5f) * Basics::GetDeltaTime() / endScreenLerpTime * endScreenTexture.getSize().y * 2 * Basics::getYScale()); //cos(x * pi + pi)/2 + 0.5
			currentEndScreenLerpTime += Basics::GetDeltaTime();
		}
		else
		{
			endScreenBackground.setPosition(0, 0);
			if (selectedButton == 0) selectedButton = 1;
			endScreenInput();
		}
	}
	if (Hide_or_Show == "Hide")
	{
		if (currentEndScreenLerpTime > 0.0f)
		{
			endScreenBackground.move(0, (cos(currentEndScreenLerpTime / endScreenLerpTime * 2 * M_PI + M_PI) / 2 + 0.5f) * Basics::GetDeltaTime() / endScreenLerpTime * endScreenTexture.getSize().y * 2 * Basics::getYScale()); //cos(x * pi + pi)/2 + 0.5
			currentEndScreenLerpTime -= Basics::GetDeltaTime();
		}
		else
		{
			endScreenBackground.setPosition(0, Basics::window.getSize().y);
			if (selectedButton == 0) selectedButton = 1;
		}
	}

	againButton.isSelected = selectedButton == 1;
	exitButton.isSelected = selectedButton == 2;

	endScreenBackground.setScale(Basics::getXScale(), Basics::getYScale());

	gameOverText.setScale(2 * Basics::getScale(), 2 * Basics::getScale());
	gameOverText.setPosition(Basics::window.getSize().x / 2 - (gameOverTextTexture.getSize().x * Basics::getScale()), endScreenBackground.getPosition().y + 100 * Basics::getScale());

	newBestScoreText.setPosition(Basics::window.getSize().x / 2 - newBestScoreText.getLocalBounds().width/2.0f * Basics::getScale(), (gameOverText.getPosition().y + 150 * Basics::getScale()));
	newBestScoreText.setScale(Basics::getScale(), Basics::getScale());

	againButton.setSize(100, 30);
	exitButton.setSize(100, 30);

	againButton.setPosition(Vec2D(Basics::window.getSize().x * (0.25f)/*/ 2 - 100.0f * Basics::getXScale()*/, (gameOverText.getPosition().y+100 * Basics::getScale()) * 2));
	exitButton.setPosition(Vec2D(Basics::window.getSize().x * (0.75f)/*/2 + 100 * Basics::getXScale()*/, (gameOverText.getPosition().y+100 * Basics::getScale()) * 2));
}

void ClassicTetris::endScreenInput()
{
	if (Basics::settings.isButtonPressed("Right")) selectedButton = 2;
	if (Basics::settings.isButtonPressed("Left")) selectedButton = 1;

	if (Basics::settings.isButtonPressed("Confirm"))
	{
		if (exitButton.isSelected) selectedEndOption = 1;
		if (againButton.isSelected) selectedEndOption = 2;
	}
	else
	{
		if (selectedEndOption == 1)
		{
			selectedButton = 0;
			gBoard.NewBoard();
			endScreenBackground.setPosition(0.0f, Basics::window.getSize().y);
			Basics::sceneManager.changeScene("Menu");
		}
		if (selectedEndOption == 2)
		{
			selectedButton = 0;
			gBoard.NewBoard();
		}

		selectedEndOption = 0;
	}
}

void ClassicTetris::update()
{
	if (!gBoard.IsGameOver())
		gBoard.Update();
	
	if (gBoard.IsGameOver())
	{
		gameOverScreen("Show");
		if (!newScoreAdded)
		{
			SBManager.AddNewBestScore(gBoard.GetScore());
			SBManager.Save();
			newScoreAdded = true;
		}
	}
	else 
		gameOverScreen("Hide");
}

void ClassicTetris::drawScene()
{ 	 
	drawBackground();
	
	Vec2D boardPosition;
	Vec2D scorePosition;
	if (Basics::isVertical())
	{
		boardPosition = Vec2D(gBoard.GetCellSize() * Basics::getSmallerScale(), gBoard.GetCellSize() * Basics::getSmallerScale());
		scorePosition.x = boardPosition.x + gBoard.GetCellSize() * (gBoard.GetColNum()/2)* Basics::getSmallerScale();
		scorePosition.y = gBoard.GetCellSize() * (gBoard.GetRowsNum() + 2) * Basics::getSmallerScale();

		NTInfo.SetPosition(
			Vec2D(
				(gBoard.GetColNum() + 2) * gBoard.GetCellSize() * Basics::getSmallerScale(),
				gBoard.GetCellSize() * 5 * Basics::getSmallerScale())
		);

	}
	else
	{
		boardPosition = Vec2D(
			Basics::window.getSize().x * (0.5f) - (gBoard.GetColNum() / 2 * gBoard.GetCellSize() * Basics::getYScale()),
			gBoard.GetCellSize() * Basics::getYScale());

		scorePosition.x = boardPosition.x + gBoard.GetCellSize() * (gBoard.GetColNum() / 2) * Basics::getYScale();
		scorePosition.y = gBoard.GetCellSize() * (gBoard.GetRowsNum() + 2) * Basics::getYScale();

		NTInfo.SetPosition(
			Vec2D(
				boardPosition.x + ((gBoard.GetColNum() + 1) * gBoard.GetCellSize()) * Basics::getYScale(),
				gBoard.GetCellSize()/2 * Basics::getYScale())
		);
	}

	scoreNum.SetPosition(scorePosition);


	scoreNum.Write(25.0f * Basics::getSmallerScale(), std::to_string(gBoard.GetScore()));
	gBoard.SetPosition(boardPosition);

	gBoard.DrawBoard();


	NTInfo.Draw();


	controllerStatus();

	Basics::window.draw(endScreenBackground);
	Basics::window.draw(gameOverText);
	/*if (gBoard.GetScore() > SBManager.scores[0])
		Basics::window.draw(newBestScoreText);*/
	againButton.drawButton();
	exitButton.drawButton();

}

ClassicTetris::ClassicTetris()
{
	initVariables();
	loadTextures();
}

ClassicTetris::~ClassicTetris()
{
}


