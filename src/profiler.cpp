#include "profiler.h"
#include "utils.h"

Profiler::Profiler(std::string name)
{
	this->UserName = name;

	std::string person = "";
	std::ifstream currentPeople;

	if (utils::fileExists(name + ".who"))
	{
		//Parse that baby for max time
	}

	currentPeople.open("current_people.who");

	while (currentPeople.peek() != EOF || person == name)
	{
		getline(currentPeople, person);
		
		if (utils::inString(name, person))
		{
			this->timeStarted = utils::indexWordinStr(person, 3);
			this->ipAddr = utils::indexWordinStr(person, 4);
		}
	}
	currentPeople.close();
	this->minStarted = utils::getStrTimeInMin(timeStarted);

}

std::string Profiler::getTimeStarted()
{
	return timeStarted;
}

std::string Profiler::getIpAddr()
{
	return ipAddr;
}

std::string Profiler::getName()
{
	return UserName;
}

int Profiler::getMinSpent()
{
	std::string curTime = utils::getTimeAsStr();
	unsigned curMin = utils::getStrTimeInMin(curTime);
	unsigned thenMin = minStarted;
	return curMin - minStarted;
}

void Profiler::writePersonToFile()
{
}