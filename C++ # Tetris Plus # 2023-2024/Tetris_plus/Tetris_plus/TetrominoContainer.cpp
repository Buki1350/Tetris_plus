#include "TetrominoContainer.h"

TetrominoContainer::TetrominoContainer()
{
	emptyCellTexture.loadFromFile("Assets/emptyCell.png");
	blueCellTexture.loadFromFile("Assets/blueCell.png");
	shadowBkueCellTexture.loadFromFile("Assets/shadowBlueCell.png");
	greenCellTexture.loadFromFile("Assets/greenCell.png");
	shadowGreenCellTexture.loadFromFile("Assets/shadowGreenCell.png");
	orangeCellTexture.loadFromFile("Assets/orangeCell.png");
	shadowOrangeCellTexture.loadFromFile("Assets/shadowOrangeCell.png");
	redCellTexture.loadFromFile("Assets/redCell.png");
	shadowRedCellTexture.loadFromFile("Assets/shadowRedCell.png");
	purpleCellTexture.loadFromFile("Assets/purpleCell.png");
	shadowPurpleCellTexture.loadFromFile("Assets/shadowPurpleCell.png");
	yellowCellTexture.loadFromFile("Assets/yellowCell.png");
	shadowYellowCellTexture.loadFromFile("Assets/shadowYellowCell.png");
	undefinedCellTexture.loadFromFile("Assets/cell.png");
	nullCellTexture.loadFromFile("Assets/nullCell.png");
}
