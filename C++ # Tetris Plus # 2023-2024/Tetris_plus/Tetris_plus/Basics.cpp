#include "Basics.h"

sf::RenderWindow Basics::window;
Settings Basics::settings;
SceneManager Basics::sceneManager;
Time Basics::myTime;

float Basics::getScale()
{
	if (Basics::window.getSize().x < Basics::window.getSize().y)
		return static_cast<float>(Basics::window.getSize().x) / float(Basics::settings.windowSettings.window_width); //actual / initial
	else
		return static_cast<float>(Basics::window.getSize().y) / float(Basics::settings.windowSettings.window_height);
}

float Basics::getInvertedScale()
{
	if (Basics::window.getSize().x < Basics::window.getSize().y)
		return static_cast<float>(Basics::window.getSize().y) / float(Basics::settings.windowSettings.window_height);
	else
		return static_cast<float>(Basics::window.getSize().x) / float(Basics::settings.windowSettings.window_width); //actual / initial
}

float Basics::getXScale()
{
	return static_cast<float>(Basics::window.getSize().x) / float(Basics::settings.windowSettings.window_width);
}

float Basics::getYScale()
{
	return static_cast<float>(Basics::window.getSize().y) / float(Basics::settings.windowSettings.window_height);;
}

float Basics::getSmallerScale()
{
	if (getXScale() < getYScale())
		return getXScale();
	else
		return getYScale();
}

float Basics::GetDeltaTime()
{
	return (float)myTime.getDeltaTime_inMiliseconds()/1000;
}

bool Basics::isVertical()
{
	return Basics::window.getSize().y > Basics::window.getSize().x;
}

std::string Basics::GetTodaysDate()
{
	return myTime.GetDate();
}

