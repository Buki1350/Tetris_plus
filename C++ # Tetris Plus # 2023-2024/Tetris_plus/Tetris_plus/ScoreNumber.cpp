#include "ScoreNumber.h"

void ScoreNumber::Write(float size, std::string text)
{
	sf::Texture currentTexture;
	sf::Sprite currentSprite;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == '1')
			currentTexture = Texture1;
		if (text[i] == '2')
			currentTexture = Texture2;
		if (text[i] == '3')
			currentTexture = Texture3;
		if (text[i] == '4')
			currentTexture = Texture4;
		if (text[i] == '5')
			currentTexture = Texture5;
		if (text[i] == '6')
			currentTexture = Texture6;
		if (text[i] == '7')
			currentTexture = Texture7;
		if (text[i] == '8')
			currentTexture = Texture8;
		if (text[i] == '9')
			currentTexture = Texture9;
		if (text[i] == '0')
			currentTexture = Texture0;

		currentSprite.setTexture(currentTexture);
		
		float scale = size / currentSprite.getLocalBounds().width;

		currentSprite.setScale(scale, scale);
		currentSprite.setPosition(sf::Vector2f( position.x + (size * i) - (size * text.length()/2), position.y));
		Basics::window.draw(currentSprite);
	}
}

void ScoreNumber::SetPosition(Vec2D position)
{
	ScoreNumber::position = position;
}

ScoreNumber::ScoreNumber()
{
	Texture1.loadFromFile("Assets/1.png");
	Texture2.loadFromFile("Assets/2.png");
	Texture3.loadFromFile("Assets/3.png");
	Texture4.loadFromFile("Assets/4.png");
	Texture5.loadFromFile("Assets/5.png");
	Texture6.loadFromFile("Assets/6.png");
	Texture7.loadFromFile("Assets/7.png");
	Texture8.loadFromFile("Assets/8.png");
	Texture9.loadFromFile("Assets/9.png");
	Texture0.loadFromFile("Assets/0.png");
}

ScoreNumber::~ScoreNumber()
{

}
