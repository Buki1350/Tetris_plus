#pragma once
#include <SFML/Window.hpp>
class Controls
{
public:
	sf::Keyboard::Key Keyboard_Fullscreen = sf::Keyboard::F11;
	sf::Keyboard::Key Keyboard_Up = sf::Keyboard::Up;
	sf::Keyboard::Key Keyboard_Down = sf::Keyboard::Down;
	sf::Keyboard::Key Keyboard_Left = sf::Keyboard::Left;
	sf::Keyboard::Key Keyboard_Right = sf::Keyboard::Right;
	sf::Keyboard::Key Keyboard_Confirm = sf::Keyboard::Enter;
	sf::Keyboard::Key Keyboard_Exit = sf::Keyboard::Escape;
	sf::Keyboard::Key Keyboard_Restart = sf::Keyboard::R;
	sf::Keyboard::Key Keyboard_RotateLeft = sf::Keyboard::Z;
	sf::Keyboard::Key Keyboard_RotateRight = sf::Keyboard::X;
	sf::Keyboard::Key Keyboard_FastDown = sf::Keyboard::Space;
	sf::Keyboard::Key Keyboard_Keep = sf::Keyboard::C;
};

