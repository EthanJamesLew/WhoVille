#pragma once
#ifndef PROFILER_H
#define PROFILER_H
#include<string>
#include<ctime>
#include"utils.h"
class Profiler
{
public:
	Profiler(std::string name);
	std::string getName();
	std::string getTimeSpent();
	std::string getTimeStarted();
	std::string getIpAddr();
	int getMinSpent();
	void writePersonToFile();
private:
	std::string UserName;
	std::string timeSpent;
	std::string timeStarted;
	std::string ipAddr;
	unsigned minSpent;
	unsigned minStarted;
	unsigned maxTimeOnline;

};

#endif // !PROFILER_H
