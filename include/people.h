#pragma once
#ifndef PEOPLE_H
#define PEOPLE_H

#include"utils.h"

class People
{
public:
	People();
	void updateWho();
	void printPeople();
	std::vector<std::string> getJoined();
	std::vector<std::string> getLeft();
	std::vector<std::string> getPeopleList();
	unsigned getNumPeople();
	void resetLists();
private:
	std::vector<std::string> peopleList;
	std::vector <std::string> newPeopleList;
	unsigned numPeople;
};

#endif
