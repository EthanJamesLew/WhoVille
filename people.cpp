#include "people.h"

People::People()
{
	std::string person = "";
	std::ifstream currentPeople;
	std::string buffer;
	std::string name;

	currentPeople.open("current_people.who");

	while (currentPeople.peek() != EOF)
	{
		getline(currentPeople, buffer);
		name = utils::indexWordinStr(buffer, 0);
		this->peopleList.push_back(name);
	}
	this->newPeopleList = peopleList;
	this->numPeople = peopleList.size();
}

void People::printPeople()
{
	for (unsigned i = 0; i < peopleList.size(); i++)
	{
		std::cout << peopleList[i] << std::endl;
	}
	return;
}

void People::updateWho()
{
	this->peopleList = newPeopleList;
	std::string person = "";
	std::ifstream currentPeople;
	std::string buffer;
	std::string name;

	system("sh whofile.sh");

	currentPeople.open("current_people.who");

	while (currentPeople.peek() != EOF)
	{
		getline(currentPeople, buffer);
		name = utils::indexWordinStr(buffer, 0);
		this->newPeopleList.push_back(name);
	}
	this->numPeople = newPeopleList.size();
}

unsigned People::getNumPeople()
{
	return numPeople;
}

std::vector<std::string> People::getDeltaPeople()
{
	std::vector<std::string> difference;
	for (unsigned i = 0; i < peopleList.size(); i++)
	{
		if (std::find(newPeopleList.begin(), newPeopleList.end(), peopleList[i]) == newPeopleList.end())
		{
			difference.push_back(peopleList[i]);
		}
			
	}
	for (unsigned i = 0; i < newPeopleList.size(); i++)
	{
		if (std::find(peopleList.begin(), peopleList.end(), newPeopleList[i]) == peopleList.end())
		{
			difference.push_back(newPeopleList[i]);
		}

	}
	return difference;
}