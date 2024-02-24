#pragma once
#include <chrono>
#include <iostream>
#include <sstream>

class Time
{
private:
	std::chrono::high_resolution_clock::time_point startPoint;
	std::chrono::high_resolution_clock::time_point endPoint;

	std::chrono::high_resolution_clock::time_point currentTime;
	std::chrono::high_resolution_clock::time_point previousTime;

	float currentDeltaTime = 0;
public:
	void startTimer();
	void endTimer(std::string cmd_message);
	float getDeltaTime_inMiliseconds();
	void UpdateTime(); //ONLY used in Game.Update() method
	std::string GetDate();

	Time();
	~Time();
};

