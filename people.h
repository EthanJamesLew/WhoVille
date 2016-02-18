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
	std::vector<std::string> getDeltaPeople();
	unsigned getNumPeople();
private:
	std::vector<std::string> peopleList;
	std::vector <std::string> newPeopleList;
	unsigned numPeople;
};

#endif