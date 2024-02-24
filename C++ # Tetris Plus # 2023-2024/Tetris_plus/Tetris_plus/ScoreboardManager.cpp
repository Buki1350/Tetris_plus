#include "ScoreboardManager.h"

void ScoreboardManager::Save()
{
	std::ofstream fileToClear;

	fileToClear.open("BS.dat", std::ofstream::out | std::ofstream::trunc);
	fileToClear.close();

	std::ofstream fileToWrite("BS.dat");

	for (int i = 0; i < 10; i++)
		fileToWrite << dates[i] << "        " << scores[i] << "\n";

	fileToWrite.close();

	for (int i = 0; i < 0; i++)
	{
		std::cout << scores[i] << " ";
	}
	std::cout << "\n";
}

void ScoreboardManager::Load()
{
	std::ifstream fileToRead("BS.dat");

	if (fileToRead && fileToRead.peek() != std::ifstream::traits_type::eof())
	{
		std::string n;
		int s;
		for (int i = 0; i < 10; i++)
		{
			fileToRead >> n >> s;
			dates[i] = n;
			scores[i] = s;
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			dates[i] = "";
			scores[i] = 0;
		}
	}

	fileToRead.close();
}

int ScoreboardManager::GetWorstScore()
{
	return scores[9];
}

void ScoreboardManager::AddNewBestScore(int score)
{
	bool placeFound = false;

	for (int i = 0; i < 10 && !placeFound; i++)
	{
		if (score > scores[i])
		{
			for (int j = 9; j > i; j--)
			{
				scores[j] = scores[j - 1];
				dates[j] = dates[j - 1];
			}

			scores[i] = score;
			dates[i] = Basics::GetTodaysDate();

			placeFound = true;
		}

	}
	
}