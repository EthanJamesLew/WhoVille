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
	std::string person = "";
	std::ifstream currentPeople;
	std::string buffer;
	std::string name;

	system("sh whofile.sh");

	currentPeople.open("current_people.who");
	
	this->newPeopleList.clear();

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

std::vector<std::string> People::getLeft()
{
	std::vector<std::string> difference;
	std::sort(peopleList.begin(), peopleList.end());
	std::sort(newPeopleList.begin(), newPeopleList.end());

	std::set_difference(newPeopleList.begin(), newPeopleList.end(), peopleList.begin(), peopleList.end(), std::back_inserter(difference));

	return difference;
}

std::vector<std::string> People::getJoined()
{
	std::vector<std::string> difference;
	std::sort(peopleList.begin(), peopleList.end());
	std::sort(newPeopleList.begin(), newPeopleList.end());

	std::set_difference(peopleList.begin(), peopleList.end(), newPeopleList.begin(), newPeopleList.end(), std::back_inserter(difference));
	
	return difference;
}

void People::resetLists()
{
	this->peopleList = newPeopleList;
	return;
}

}
