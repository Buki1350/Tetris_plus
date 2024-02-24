#pragma once
#include <SFML/Graphics.hpp>
#include "TetrominoContainer.h"
#include "GameBoard.h"


class NextTetroInfo : TetrominoContainer
{
private:
	Vec2D position;
	float space = 100.0f;

	sf::Texture backgroundTexture;
	
	GameBoard* gBoard;
	int** tetromino;
public:
	void LinkWithBoard(GameBoard* board);
	void Draw();
	void SetPosition(Vec2D position);

	NextTetroInfo();
	~NextTetroInfo();
};

