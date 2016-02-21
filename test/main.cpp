//Test the destructor in Profiler

#include "profiler.h"
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<Profiler> prof;
	Profiler *person = new Profiler("ethan.lew");
	prof.push_back(*person);
	prof.erase(prof.begin());
	return 0;
}