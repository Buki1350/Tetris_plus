#include "Scene.h"

void Scene::controllerStatus()
{
	initControllerMessageX = Basics::window.getSize().x - (controller_connected_texture.getSize().x * 2) * Basics::getScale();
	initControllerMessageY = 0 - (signed)controller_connected_texture.getSize().y * Basics::getScale();


	controller_connected_message.setScale(Basics::getScale(), Basics::getScale());
	controller_disconnected_message.setScale(Basics::getScale(), Basics::getScale());

	if (!JStickConnected && sf::Joystick::isConnected(0) || JStickConnected && !sf::Joystick::isConnected(0))
		currentControllerMessAnimTime = 0;

	if (currentControllerMessAnimTime < controllerMessAnimTime)
	{
		currentControllerMessAnimTime += Basics::GetDeltaTime();
		if (sf::Joystick::isConnected(0))
		{
			controller_connected_message.move((cos(currentControllerMessAnimTime / controllerMessAnimTime * 2 * 3.1415) / 2 + 0.5) * Basics::GetDeltaTime() / controllerMessAnimTime * controller_connected_texture.getSize().x * 4 * Basics::getScale(),
			(cos(currentControllerMessAnimTime / controllerMessAnimTime * 2 * 3.1415) / 2 + 0.5) * Basics::GetDeltaTime() / controllerMessAnimTime * controller_connected_texture.getSize().x * 4 * Basics::getScale()); //cos(x PI 2)/2 + 0.5   <- half texture size
			
			controller_disconnected_message.setPosition(initControllerMessageX, initControllerMessageY);
		}
		else
		{
			controller_disconnected_message.move((cos(currentControllerMessAnimTime / controllerMessAnimTime * 2 * 3.1415) / 2 + 0.5) * Basics::GetDeltaTime() / controllerMessAnimTime * controller_disconnected_texture.getSize().x * 4 * Basics::getScale(),
			(cos(currentControllerMessAnimTime / controllerMessAnimTime * 2 * 3.1415) / 2 + 0.5) * Basics::GetDeltaTime() / controllerMessAnimTime * controller_disconnected_texture.getSize().x * 4 * Basics::getScale()); //cos(x PI 2)/2 + 0.5   <- half texture size

			controller_connected_message.setPosition(initControllerMessageX, initControllerMessageY);
		}
	}
	else
	{
		controller_connected_message.setPosition(initControllerMessageX, initControllerMessageY);
		controller_disconnected_message.setPosition(initControllerMessageX, initControllerMessageY);
	}

	
	Basics::window.draw(controller_connected_message);
	Basics::window.draw(controller_disconnected_message);

	JStickConnected = sf::Joystick::isConnected(0);
}

Scene::Scene()
{
	controller_connected_texture.loadFromFile("Assets/controller_connected_message.png");
	controller_connected_message.setTexture(controller_connected_texture);
	controller_disconnected_texture.loadFromFile("Assets/controller_disconnected_message.png");
	controller_disconnected_message.setTexture(controller_disconnected_texture);

	initControllerMessageX = Basics::window.getSize().x - controller_connected_texture.getSize().x * 2;
	initControllerMessageY = - (signed)controller_connected_texture.getSize().y;
	controller_connected_message.setPosition(initControllerMessageX, initControllerMessageY);
	controller_disconnected_message.setPosition(initControllerMessageX, initControllerMessageY);

	currentControllerMessAnimTime = controllerMessAnimTime;
	JStickConnected = sf::Joystick::isConnected(0);
}

Scene::~Scene()
{
}
