#include "profiler.h"
#include "utils.h"

Profiler::Profiler(std::string name)
{
	this->UserName = name;

	std::string person = "";
	std::ifstream currentPeople;
	std::ofstream outFile;

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

	if (utils::fileExists("who/" + this->UserName + ".who") == false)
	{
		outFile.open("who/" + this->UserName + ".who");
		outFile << "THIS IS A.WHO FILE.OPEN IT IN EXCEL FOR READIBILITY AND ANALYSIS, , , ," << std::endl;
		outFile << "User, people.mcperson	, , ," << std::endl;
		outFile << ", , , ," << std::endl;
		outFile << "Logins, Time Start, Time End, Total Time (min), IP Address" << std::endl;
		outFile.close();
	}

}


Profiler::~Profiler()
{
	Profiler::writePersonToFile();
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
	std::ofstream outFile;
	std::ofstream outFile2;
	if (utils::fileExists("who/"+this->UserName + ".who") == false)
	{
		outFile.open("who/" + this->UserName + ".who");
		outFile << "THIS IS A.WHO FILE.OPEN IT IN EXCEL FOR READIBILITY AND ANALYSIS, , , ," << std::endl;
		outFile << "User, people.mcperson	, , ," << std::endl;
		outFile << ", , , ," << std::endl;
		outFile << "Logins, Time Start, Time End, Total Time (min), IP Address" << std::endl;
		outFile.close();
	}
	outFile2.open("who/" + this->UserName + ".who");
	outFile2 << utils::getDateAsStr()<<", "<<this->timeStarted << ", " << utils::getTimeAsStr() << ", " << this->getMinSpent() << ", " << this->ipAddr << std::endl;
	outFile2.close();
	return;
}