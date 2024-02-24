#include "GameBoard.h"

void GameBoard::NewBoard()
{
	score = 0;
	for (int i = 0; i < width + height; i++)
	{
		board[i] = new int[height + margin];
		for (int j = 0; j < height + margin; j++)
		{
			if (i < margin || i >= width - margin || j >= GameBoard::height - GameBoard::margin)
				board[i][j] = -10;
			else
				board[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i++)		//FILL THE LIST
		NewTetromino();
}

void GameBoard::NewTetromino()
{
	crntTetroPos.x = initTetroPos.x;
	crntTetroPos.y = initTetroPos.y;

	crntTetroRotation = tetroRotationsList[0];
	crntTetroIndex = tetroIndexList[0];

	for (int i = 0; i < 3; i++)
	{
		tetroIndexList[i] = tetroIndexList[i + 1];
		tetroRotationsList[i] = tetroRotationsList[i + 1];
	}


	tetroIndexList[3] = rand() % 7 + 1;
	tetroRotationsList[3] = rand() % 3 + 1;
	int* newTetro = tetrosBase.getShape(tetroIndexList[3], tetroRotationsList[3]);

	//TAKE CURRENT FROM TOP OF THE LIST AND 
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			currentTetro[i][j] = nextTetroList[i][j][0];				//TAKE PART FROM TOP OF THE LIST

			for (int z = 0; z < 3; z++)
				nextTetroList[i][j][z] = nextTetroList[i][j][z + 1];	//PUSH CHUNK OF THE QUEUE
			
			nextTetroList[i][j][3] = newTetro[i + (j * 4)];				//FILL LAST CHU FROM THE QUEUE
		}
	}
}

void GameBoard::DrawBoard()
{
	float currentCellSize = cellSize * Basics::getSmallerScale();
	for (int j = margin; j < height - margin; j++)
	{
		for (int i = margin; i < width - margin; i++)
		{
			sf::Texture cellTexture;
			switch (abs(board[i][j]))
			{
			case 0:
				cellTexture = emptyCellTexture;
				break;
			case 1:
				cellTexture = blueCellTexture;
				break;
			case 11:
				cellTexture = shadowBkueCellTexture;
				break;
			case 2:
				cellTexture = greenCellTexture;
				break;
			case 22:
				cellTexture = shadowGreenCellTexture;
				break;
			case 3:
				cellTexture = orangeCellTexture;
				break;
			case 33:
				cellTexture = shadowOrangeCellTexture;
				break;
			case 4:
				cellTexture = orangeCellTexture;
				break;
			case 44:
				cellTexture = shadowOrangeCellTexture;
				break;
			case 5:
				cellTexture = redCellTexture;
				break;
			case 55:
				cellTexture = shadowRedCellTexture;
				break;
			case 6:
				cellTexture = purpleCellTexture;
				break;
			case 66:
				cellTexture = shadowPurpleCellTexture;
				break;
			case 7:
				cellTexture = yellowCellTexture;
				break;
			case 77:
				cellTexture = shadowYellowCellTexture;
				break;
			default:
				cellTexture = undefinedCellTexture;
				break;
			}

			sf::Sprite cellSprite(cellTexture);
			cellSprite.setScale((cellSize / cellTexture.getSize().x) * Basics::getSmallerScale(), (cellSize / cellTexture.getSize().y) * Basics::getSmallerScale());
			cellSprite.setPosition(sf::Vector2f(position.x + (i - margin) * currentCellSize, position.y + (j - margin) * currentCellSize));
			Basics::window.draw(cellSprite);
		}
	}
}

void GameBoard::RotateTetromino(std::string dir)
{
	if (dir == "Right")
	{
		int newRotation = crntTetroRotation + 1;
		if (newRotation < 0)
			newRotation = 3;
		if (newRotation > 3)
			newRotation = 0;

		int* newRotatedTetro = tetrosBase.getShape(crntTetroIndex, newRotation);

		bool isColliding = false;

		for (int j = 0; j < 4 && !isColliding; j++)
			for (int i = 0; i < 4 && !isColliding; i++)
				if (board[crntTetroPos.x + i][crntTetroPos.y + j] * newRotatedTetro[i + (j * 4)] < 0)
					isColliding = true;

		if (!isColliding)
		{
			for (int j = 0; j < 4; j++)
				for (int i = 0; i < 4; i++)
					currentTetro[i][j] = newRotatedTetro[i + (j * 4)];
			crntTetroRotation = newRotation;
		}
		else
		{
			
		}
	}
	if (dir == "Left")
	{
		int newRotation = crntTetroRotation - 1;
		if (newRotation < 0)
			newRotation = 3;
		if (newRotation > 3)
			newRotation = 0;
		int* newRotatedTetro = tetrosBase.getShape(crntTetroIndex, newRotation);

		bool isColliding = false;

		for (int j = 0; j < 4 && !isColliding; j++)
			for (int i = 0; i < 4 && !isColliding; i++)
				if (board[crntTetroPos.x + i][crntTetroPos.y + j] * newRotatedTetro[i + (j * 4)] < 0)
					isColliding = true;

		if (!isColliding)
		{
			for (int j = 0; j < 4; j++)
				for (int i = 0; i < 4; i++)
					currentTetro[i][j] = newRotatedTetro[i + (j * 4)];
			crntTetroRotation = newRotation;
		}
	}
}

bool GameBoard::IsGameOver()
{
	for (int i = margin; i < width - margin; i++)
		if (board[i][margin] < 0)
			return true;

	return false;
}

void GameBoard::SetShadow()
{
	for (int j = margin; j < height - margin; j++)
		for (int i = margin; i < width - margin; i++)
			if (board[i][j] > 10)
				board[i][j] = 0;

	tetroShadowPos.x = crntTetroPos.x;
	tetroShadowPos.y = crntTetroPos.y;

	while (NothingBelow(tetroShadowPos.x, tetroShadowPos.y))
	{
		tetroShadowPos.y++;
	}

	for (int j = 0; j < 4; j++)
		for (int i = 0; i < 4; i++)
			if (currentTetro[i][j] != 0)
				board[tetroShadowPos.x + i][tetroShadowPos.y + j] = crntTetroIndex * 11;

}

bool GameBoard::NothingBelow(int posX, int posY)
{
	bool condition = true;
	for (int j = 0; j < 4 && condition; j++)
	{
		for (int i = 0; i < 4 && condition; i++)
		{
			if (currentTetro[i][j] * board[posX + i][posY + j + 1] < 0)
			{
				condition = false;
			}
		}
	}
	return condition;
}

void GameBoard::UpdateTetromino()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (currentTetro[i][j] != 0)
				board[i + crntTetroPos.x][j + crntTetroPos.y] = currentTetro[i][j];
		}
	}
	prevTetroPos.x = crntTetroPos.x;
	prevTetroPos.y = crntTetroPos.y;
}

void GameBoard::MoveTetromino(std::string dir)
{
	if (horizMoveDelay_timer >= horizMoveDelay)
	{
		if (dir == "Left")
		{
			bool isLeftFree = true;
			for (int j = 0; j < 4 && isLeftFree; j++)
			{
				for (int i = 0; i < 4 && isLeftFree; i++)
				{
					if (currentTetro[i][j] * board[crntTetroPos.x + i - 1][crntTetroPos.y + j] < 0)
					{
						isLeftFree = false;
					}

				}
			}
			if (isLeftFree)
				crntTetroPos.x--;
		}
		if (dir == "Right")
		{
			bool isRightFree = true;
			for (int j = 0; j < 4 && isRightFree; j++)
			{
				for (int i = 0; i < 4 && isRightFree; i++)
				{
					if (currentTetro[i][j] * board[crntTetroPos.x + i + 1][crntTetroPos.y + j] < 0)
					{
						isRightFree = false;
					}
				}
			}
			if (isRightFree)
				crntTetroPos.x++;
		}
		horizMoveDelay_timer = 0.0f;
	}
	else
		horizMoveDelay_timer += Basics::GetDeltaTime();
}

void GameBoard::GameInput()
{
	if (Basics::settings.isButtonPressed("Right"))
		MoveTetromino("Right");

	if (Basics::settings.isButtonPressed("Left"))
		MoveTetromino("Left");

	if (Basics::settings.isButtonPressed("Rotate_right"))
	{
		if (!isKeyPressed)
			RotateTetromino("Right");
		isKeyPressed = true;
	}
	else if (Basics::settings.isButtonPressed("Rotate_left"))
	{
		if (!isKeyPressed)
			RotateTetromino("Left");
		isKeyPressed = true;
	}
	else if (Basics::settings.isButtonPressed("Fast_down"))
	{
		if (!isKeyPressed)
		{
			crntTetroPos.x = tetroShadowPos.x;
			crntTetroPos.y = tetroShadowPos.y;
			softDropTimer = softDropTime;
		}
		isKeyPressed = true;
	}
	else
		isKeyPressed = false;


	if (Basics::settings.isButtonPressed("Down"))
	{
		crntDropTime = 0.02f;
	}
	else
	{
		if (score != 0)
			crntDropTime = dropTime - (float)score/2000;
		else
			crntDropTime = dropTime;

		if (crntDropTime < 0.02f)
			crntDropTime = 0.02f;

		//std::cout << crntDropTime << "\n";
		
	}
	if (Basics::settings.isButtonPressed("Exit"))
		Basics::sceneManager.changeScene("Menu");
}

void GameBoard::ClearTetroAtPrevPos()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (board[i + prevTetroPos.x][j + prevTetroPos.y] != 0 && currentTetro[i][j] != 0)
				board[i + prevTetroPos.x][j + prevTetroPos.y] = 0;
		}
	}
}

bool GameBoard::SoftDropEnded()
{
	if (NothingBelow(crntTetroPos.x, crntTetroPos.y))
		softDropTimer = 0;
	else
		softDropTimer += Basics::GetDeltaTime();


	return (softDropTimer > softDropTime);
}

void GameBoard::PlaceTetromino()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (board[i + prevTetroPos.x][j + prevTetroPos.y] != 0 && currentTetro[i][j] != 0)
				board[i + prevTetroPos.x][j + prevTetroPos.y] = -crntTetroIndex;
		}
	}
}

void GameBoard::ClearLines()
{
	for (int j = 0; j < height - margin; j++)
	{
		bool lineFull = true;

		for (int i = margin; i < width - margin; i++)
			if (board[i][j] == 0)
				lineFull = false;

		if (lineFull)
		{
			for (int i = margin; i < width - margin; i++)
				board[i][j] = 0;


			for (int j2 = j; j2 > 0; j2--)
			{
				for (int i2 = margin; i2 < width - margin; i2++)
					board[i2][j2] = board[i2][j2 - 1];
			}
			score += 10;
		}
	}
}

bool GameBoard::ShouldDrop()
{
	dropTimer += Basics::GetDeltaTime();

	if (dropTimer > crntDropTime)
	{
		dropTimer = 0;
		return true;
	}
	else
		return false;
}

void GameBoard::TetroFall()
{
	if (ShouldDrop() && NothingBelow(crntTetroPos.x, crntTetroPos.y))
		crntTetroPos.y++;
}

void GameBoard::SetPosition(Vec2D position)
{
	GameBoard::position = position;
}

void GameBoard::Update()
{
	if (SoftDropEnded())
	{
		PlaceTetromino();
		ClearLines();
		NewTetromino();
	}
	else
		ClearTetroAtPrevPos();

	GameInput();
	TetroFall();

	/*if (gBoard.ShouldDrop() && gBoard.NothingBelow(crntTetroPosX, crntTetroPosY))
		gBoard.crntTetroPosY++;*/

	if (Basics::settings.gameSettings.marked_location)
		SetShadow();
	UpdateTetromino();

	/*prevTetroPosX = crntTetroPosX;
	prevTetroPosY = crntTetroPosY;*/
}

int** GameBoard::GetNextTetromino(int index)
{
	int** test;
	test = new int* [4];
	for (int i = 0; i < 4; i++)
		test[i] = new int[4];

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
			test[i][j] = nextTetroList[i][j][index];
	}

	//////////////////////
	int tetroToReturn[16];
	try
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
				tetroToReturn[i + (4 * j)] = nextTetroList[i][j][index];
		}
	}
	catch(const std::exception e)
	{
		std::cerr << "Out of range index - index more than 3 in GetNextTetromino()";
	}

	return test;
}

float GameBoard::GetCellSize()
{
	return cellSize;
}

int GameBoard::GetColNum()
{
	return width - (2*margin);
}

int GameBoard::GetRowsNum()
{
	return height - (2 * margin);
}

int GameBoard::GetScore()
{
	return score;
}

GameBoard::GameBoard()
{
	srand(time_t(NULL));
	
	position = Vec2D(0.0f, 0.0f);

	width += 2 * margin;
	height += 2 * margin;

	board = new int* [width + (height * 2)];


	currentTetro = new int* [4];
	for (int i = 0; i < 4; i++)
		currentTetro[i] = new int[4] {0};

	nextTetroList = new int** [4];
	for (int i = 0; i < 4; i++)
	{
		nextTetroList[i] = new int* [4];
		for (int j = 0; j < 4; j++)
			nextTetroList[i][j] = new int[4] {0};
	}

	tetroIndexList = new int[4];
	tetroRotationsList = new int[4];

	crntTetroPos.x = prevTetroPos.x = margin;
	crntTetroPos.y = prevTetroPos.y = height;
	initTetroPos.x = width / 2 - 2;
	initTetroPos.y = 0;

	NewBoard();
}

GameBoard::~GameBoard()
{
	delete[] board;
	
	for (int i = 0; i < 4; i++)
	{
		delete[] currentTetro[i];

		for (int j = 0; j < 4; j++)
			delete[] nextTetroList[i][j];
		delete[] nextTetroList[i];
	}

	delete[] currentTetro;
	delete[] nextTetroList;
	delete[] tetroIndexList;
	delete[] tetroRotationsList;
}