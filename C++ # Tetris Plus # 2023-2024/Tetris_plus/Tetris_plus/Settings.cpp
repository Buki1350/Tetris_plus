#include "Settings.h"

//0 - A		4 - 
//1 - B		
//2 - X		
//3 - Y		

bool Settings::isButtonPressed(std::string action)
{
	if (sf::Joystick::isConnected(0)) //recall to non-existing var (Jostick)
	{
		if (action == "Fullscreen")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Fullscreen))
				return true;

		if (action == "Up")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Up) || sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) == 100)
				return true;

		if (action == "Down")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Down) || sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) == -100)
				return true;

		if (action == "Left")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) == -100)
				return true;

		if (action == "Right")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) == 100)
				return true;

		if (action == "Confirm")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Confirm) || sf::Joystick::isButtonPressed(0, 0))
				return true;

		if (action == "Exit")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Exit) || sf::Joystick::isButtonPressed(0, 7))
				return true;

		if (action == "Restart")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Restart) || sf::Joystick::isButtonPressed(0, 6))
				return true;

		if (action == "Rotate_left")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_RotateLeft) || sf::Joystick::isButtonPressed(0, 2))
				return true;

		if (action == "Rotate_right")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_RotateRight) || sf::Joystick::isButtonPressed(0, 1))
				return true;

		if (action == "Fast_down")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_FastDown) || sf::Joystick::isButtonPressed(0, 0))
				return true;

		if (action == "Keep")
		{
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_FastDown) || sf::Joystick::isButtonPressed(0, 3))
				return true;
		}
	}
	else
	{
		if (action == "Fullscreen")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Fullscreen))
				return true;

		if (action == "Up")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Up))
				return true;

		if (action == "Down")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Down))
				return true;

		if (action == "Left")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Left))
				return true;

		if (action == "Right")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Right))
				return true;

		if (action == "Confirm")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Confirm))
				return true;

		if (action == "Exit")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Exit))
				return true;

		if (action == "Restart")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_Restart))
				return true;

		if (action == "Rotate_left")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_RotateLeft))
				return true;

		if (action == "Rotate_right")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_RotateRight))
				return true;

		if (action == "Fast_down")
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_FastDown))
				return true;

		if (action == "Keep")
		{
			if (sf::Keyboard::isKeyPressed(controls.Keyboard_FastDown))
				return true;
		}
	}
	
	return false;

}

Settings::Settings()
{
}

Settings::~Settings()
{

}
