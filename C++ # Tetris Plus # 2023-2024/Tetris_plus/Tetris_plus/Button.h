	 #pragma once
#include <string>
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Basics.h"
class Button
{
private:
	std::string buttonText = "";
	sf::Texture defaultTexture;
	sf::Texture selectedTexture;

	int buttonWidth = 100;
	int buttonHeight = 30;
	Vec2D position = Vec2D(0.0f, 0.0f);

	bool responsive = false;
	bool scaleToX = false;
	bool scaleToY = false;
public:
	bool isSelected = false;
	void setText(std::string text);
	void setSize(int x, int y);
	void setPosition(Vec2D position);
	void setTexture(sf::Texture defaultButtonTexture, sf::Texture selectedButtonTexture);
	bool clicked() const;
	void drawButton();
	void isResponsive(bool res);
	void setScalingAxis(std::string X_or_Y_or_Default);

	float getWidth() const;
	float getHeight() const;
	float getRawWidth() const;
	float getRawHeight() const;
	float getXPosition() const;
	float getYPosition() const;

	Button();
	~Button();
};

