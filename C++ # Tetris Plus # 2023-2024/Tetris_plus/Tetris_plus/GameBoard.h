#pragma once
#include "SFML/Graphics.hpp"
#include "Tetrominos.h"
#include "Basics.h"
#include "TetrominoContainer.h"

class GameBoard : TetrominoContainer
{
private:
	int timeInMicros;
	//BOARD PARAMETERS
	int width = 10;
	int height = 20;
	int margin = 3;
	Vec2D position;

	float cellSize = 20.0f;

	int** board;
	int score = 0;

	//TETROMINOS
	Tetrominos tetrosBase;
	int** currentTetro;
	int crntTetroIndex;
	int crntTetroRotation;
	Vec2Di initTetroPos;
	Vec2Di crntTetroPos;
	Vec2Di prevTetroPos;
	Vec2Di tetroShadowPos;
	bool tetroPlaced = true;
	bool tetroCreated = false;
	
	int*** nextTetroList;
	int* tetroIndexList;
	int* tetroRotationsList;

	float dropTime = 0.5f; // base speed in sec
	float crntDropTime; // affected by speeding ; restarts to base dropTime
	float dropTimer = 0.0f;

	float softDropTimer = 0.0f;
	float softDropTime = 0.2f;

	float horizMoveDelay = 0.02f;
	float horizMoveDelay_timer = 0.0f;


	//OTHER
	bool isKeyPressed = false; // double click protection

	void NewTetromino();
	void RotateTetromino(std::string dir);
	void SetShadow();
	bool NothingBelow(int posX, int posY);
	void UpdateTetromino();
	void MoveTetromino(std::string dir);
	void GameInput();
	void ClearTetroAtPrevPos();
	bool SoftDropEnded();
	void PlaceTetromino();
	void ClearLines();
	bool ShouldDrop();
	void TetroFall();

public:
	int GetScore();
	float GetCellSize();
	int  GetColNum();
	int GetRowsNum();
	bool IsGameOver();
	void SetPosition(Vec2D position);
	void NewBoard();

	void DrawBoard();
	void Update();

	int** GetNextTetromino(int index);

	GameBoard();
	~GameBoard();
};

