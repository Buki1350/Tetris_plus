#ifndef BASICS_H
#define BASICS_H

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Time.h"
#include "SceneManager.h"
#include "Vec2D.h"

# define M_PI           3.14159265358979323846

class Basics
{
public:
	static sf::RenderWindow window;
	static Settings settings;
	static SceneManager sceneManager;
	static Time myTime;

	static float getScale();
	static float getInvertedScale();
	static float getXScale();
	static float getYScale();
	static float getSmallerScale();
	static float GetDeltaTime();
	static bool isVertical();
	static std::string GetTodaysDate();
};

#endif

