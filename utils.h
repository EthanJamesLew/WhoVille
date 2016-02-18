#pragma once
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>    // std::set_difference, std::sort
#include <stdio.h>
#include<stdlib.h>
#include <iterator>

namespace utils
{
	bool fileExists(const std::string& name);

	bool inString(std::string substr, std::string str);

	std::string indexWordinStr(std::string str, unsigned index);

	int getCurrentUnixTime();

	std::string getTimeAsStr();

	unsigned getStrTimeInMin(std::string);

	std::string vectorToStr(std::vector<std::string> vec);

}
