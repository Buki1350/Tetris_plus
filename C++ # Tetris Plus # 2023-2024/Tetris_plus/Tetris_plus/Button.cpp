#include "Button.h"

void Button::setText(std::string text)
{
    buttonText = text;
}

void Button::setSize(int x, int y)
{
    buttonWidth = x;
    buttonHeight = y;
}

void Button::setPosition(Vec2D position)
{
    Button::position = position;
}

void Button::setTexture(sf::Texture defaultButtonTexture, sf::Texture selectedButtonTexture)
{
    defaultTexture = defaultButtonTexture;
    selectedTexture = selectedButtonTexture;
}

bool Button::clicked() const
{
    return false;
}

void Button::drawButton()
{
    sf::Texture buttonTexture;
    sf::Sprite buttonSprite;
    (isSelected) ? buttonSprite.setTexture(selectedTexture) : buttonSprite.setTexture(defaultTexture);

    float scaleX = buttonWidth / buttonSprite.getLocalBounds().width;
    float scaleY = buttonHeight / buttonSprite.getLocalBounds().height;
    if (responsive)
    {
        if (scaleToX && !scaleToY) buttonSprite.setScale(scaleX * Basics::getXScale(), scaleY * Basics::getXScale());
        else if (!scaleToX && scaleToY) buttonSprite.setScale(scaleX * Basics::getYScale(), scaleY * Basics::getYScale());
        else buttonSprite.setScale(scaleX * Basics::getScale(), scaleY * Basics::getScale());
    }
    else
        buttonSprite.setScale(scaleX, scaleY);

    float cornerPositionX = position.x - (buttonWidth / 2);
    float cornerPositionY = position.y - (buttonHeight / 2);
    buttonSprite.setPosition(sf::Vector2f(cornerPositionX, cornerPositionY));
    Basics::window.draw(buttonSprite);
}

void Button::isResponsive(bool res)
{
    responsive = res;
}

float Button::getWidth() const
{
    if (responsive)
        return buttonWidth * Basics::getScale();
    else
        return buttonWidth;
}

float Button::getHeight() const
{
    if (responsive)
        return buttonHeight * Basics::getScale();
    else
        return buttonHeight;
}

void Button::setScalingAxis(std::string X_or_Y_or_Default)
{
    scaleToX = X_or_Y_or_Default == "X";
    scaleToY = X_or_Y_or_Default == "Y";
}

Button::Button()
{
}

float Button::getRawWidth() const
{
    return buttonWidth;
}

Button::~Button()
{
}

float Button::getRawHeight() const
{
    return buttonHeight;
}

float Button::getXPosition() const
{
    return position.x;
}

float Button::getYPosition() const
{
    return position.y;
}
