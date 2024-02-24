#include "Time.h"

void Time::startTimer()
{
	startPoint = std::chrono::high_resolution_clock::now();
}

void Time::endTimer(std::string cmd_message)
{
	endPoint = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::microseconds>(endPoint - startPoint);
	float deltaInFloat = delta.count();
}

float Time::getDeltaTime_inMiliseconds()
{
	return currentDeltaTime;
}

void Time::UpdateTime()
{
	currentTime = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - previousTime);
	float deltaInFloat = delta.count();

	previousTime = currentTime;
	currentDeltaTime = deltaInFloat;
}

std::string Time::GetDate()
{
    std::string date = "";
    std::time_t now = std::time(0);
    std::tm localTime = {};

    // U¿yj localtime_s, aby unikn¹æ problemów zwi¹zanych z bezpieczeñstwem
    if (localtime_s(&localTime, &now) == 0)
    {
        // Zdefiniuj bufor dla sformatowanej daty
        char buffer[80];

        // U¿yj strftime do sformatowania struktury czasu do postaci tekstu
        if (std::strftime(buffer, sizeof(buffer), "%Y-%m-%d__%H:%M:%S", &localTime) > 0)
        {
            date = buffer;
        }
    }

    return date;
}

Time::Time()
{
	currentTime = previousTime = std::chrono::high_resolution_clock::now();
}

Time::~Time()
{
}
