#include "utils.h"


namespace utils
{

	bool fileExists(const std::string& name) {
		std::ifstream f(name.c_str());
		if (f.good()) {
			f.close();
			return true;
		}
		else {
			f.close();
			return false;
		}
	}

	bool inString(std::string substr, std::string str)
	{
		if (str.find(substr) != std::string::npos)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::string indexWordinStr(std::string str, unsigned index)
	{
		std::istringstream iss(str);
		std::string word;
		for (unsigned i = 0; i <= index; i++)
		{
			iss >> word;
		}
		iss.clear();
		iss.ignore(100000, '\n');
		return word;
	}

	int getCurrentUnixTime()
	{
		return time(NULL);
	}


	std::string getTimeAsStr()
	{
		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, 80, "%H:%M", timeinfo);
		std::string str(buffer);
		return str;
	}

	unsigned getStrTimeInMin(std::string str)
	{
		int h, m, min = 0;
		auto k = str;

		if (sscanf(str.c_str(), "%d:%d", &h, &m) >= 2)
		{
			min = h * 60 + m;
		}
		return min;
	}

	std::string vectorToStr(std::vector<std::string> vec)
	{
		std::string ans;
		for (unsigned i = 0; i < vec.size(); i++)
		{
			ans += vec[i] + " ";
		}
		return ans;
	}
}
