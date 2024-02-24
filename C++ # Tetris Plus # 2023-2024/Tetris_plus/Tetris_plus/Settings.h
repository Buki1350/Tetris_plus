#pragma once
#include <SFML/Window.hpp>
#include <cctype>
#include "Controls.h"
#include "WindowSettings.h"
#include "GameSettings.h"

class Settings
{
public:
	Controls controls;
	WindowSettings windowSettings;
	GameSettings gameSettings;

	//bool pressedKeysArray

	bool isButtonPressed(std::string action);
	//bool isButtonReleased(std::string action);
	Settings();
	~Settings();
};