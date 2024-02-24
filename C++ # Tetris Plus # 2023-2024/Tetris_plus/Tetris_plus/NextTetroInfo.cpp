#include "NextTetroInfo.h"

void NextTetroInfo::LinkWithBoard(GameBoard* board)
{
	NextTetroInfo::gBoard = board;
}

void NextTetroInfo::Draw()
{
	sf::Sprite background(backgroundTexture);
	background.setScale(Basics::getSmallerScale(), Basics::getSmallerScale());
	background.setPosition(position.x, position.y);
	Basics::window.draw(background);

	for (int nextTetroIndex = 0; nextTetroIndex < 4; nextTetroIndex++)
	{
		tetromino = gBoard->GetNextTetromino(nextTetroIndex);
		
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				sf::Texture cellTexture;
				switch (tetromino[i][j])
				{
				case 0:
					cellTexture = nullCellTexture;
					break;
				case 1:
					cellTexture = blueCellTexture;
					break;
				case 2:
					cellTexture = greenCellTexture;
					break;
				case 3:
					cellTexture = orangeCellTexture;
					break;
				case 4:
					cellTexture = orangeCellTexture;
					break;
				case 5:
					cellTexture = redCellTexture;
					break;
				case 6:
					cellTexture = purpleCellTexture;
					break;
				case 7:
					cellTexture = yellowCellTexture;
					break;
				default:
					cellTexture = undefinedCellTexture;
					break;
				}

				sf::Sprite cellSprite(cellTexture);

				cellSprite.setScale(
					(gBoard->GetCellSize() / cellTexture.getSize().x) * Basics::getSmallerScale(),
					(gBoard->GetCellSize() / cellTexture.getSize().y) * Basics::getSmallerScale());

				int biasX = 1;
				int biasY = 1;
				float scaledSpace = space * Basics::getSmallerScale();
				cellSprite.setPosition(
					sf::Vector2f(position.x + ((i + biasX) * gBoard->GetCellSize() * Basics::getSmallerScale()),
					position.y + ((j + biasY) * gBoard->GetCellSize() * Basics::getSmallerScale()) + nextTetroIndex * scaledSpace));
				cellSprite.setScale(Basics::getSmallerScale(), Basics::getSmallerScale());
				Basics::window.draw(cellSprite);
			}
		}
	}
}

void NextTetroInfo::SetPosition(Vec2D position)
{
	NextTetroInfo::position = position;
}

NextTetroInfo::NextTetroInfo()
{
	gBoard = nullptr;

	backgroundTexture.loadFromFile("Assets/nextTetroBox.png");

	tetromino = new int* [4];
	for (int i = 0; i < 4; i++)
		tetromino[i] = new int[4];
}

NextTetroInfo::~NextTetroInfo()
{
}
