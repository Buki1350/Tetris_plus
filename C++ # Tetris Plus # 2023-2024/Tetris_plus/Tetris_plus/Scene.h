#pragma once
#include "SFML/Graphics.hpp"
#include "Basics.h"
#include "Time.h"
#include <iostream>
class Scene
{
protected:
	bool justOpened = true;

	//WIDGETS
	bool JStickConnected;
	float controllerMessSize = 100.0f;
	float controllerMessBias = 0.0f;
	float controllerMessAnimTime = 2.0f; //seconds
	float currentControllerMessAnimTime;
	float initControllerMessageX;
	float initControllerMessageY;

	sf::Sprite controller_connected_message, controller_disconnected_message;
	sf::Texture controller_connected_texture, controller_disconnected_texture;

public:
	void controllerStatus();

	Scene();
	~Scene();
};

