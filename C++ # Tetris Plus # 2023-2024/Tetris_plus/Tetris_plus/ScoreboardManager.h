#pragma once
#include <iostream>
#include <fstream>
#include "Basics.h"

class ScoreboardManager
{
public:
	int scores[10]{0};
	std::string dates[10];
	void Save();
	void Load();
	int GetWorstScore();
	void AddNewBestScore(int score);
};

