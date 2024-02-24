#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Basics.h"
class ScoreNumber
{
private:
	Vec2D position = Vec2D(0.0f, 0.0f);
	sf::Texture Texture1;
	sf::Texture Texture2;
	sf::Texture Texture3;
	sf::Texture Texture4;
	sf::Texture Texture5;
	sf::Texture Texture6;
	sf::Texture Texture7;
	sf::Texture Texture8;
	sf::Texture Texture9;
	sf::Texture Texture0;

public:
	void Write(float size, std::string text);
	void SetPosition(Vec2D position);
	ScoreNumber();
	~ScoreNumber();
};

