#pragma once
#include <SFML/Graphics.hpp>
class TetrominoContainer
{
protected:
	sf::Texture emptyCellTexture;
	sf::Texture blueCellTexture;
	sf::Texture shadowBkueCellTexture;
	sf::Texture greenCellTexture;
	sf::Texture shadowGreenCellTexture;
	sf::Texture orangeCellTexture;
	sf::Texture shadowOrangeCellTexture;
	sf::Texture redCellTexture;
	sf::Texture shadowRedCellTexture;
	sf::Texture purpleCellTexture;
	sf::Texture shadowPurpleCellTexture;
	sf::Texture yellowCellTexture;
	sf::Texture shadowYellowCellTexture;
	sf::Texture undefinedCellTexture;
	sf::Texture nullCellTexture;

public:
	TetrominoContainer();
};

