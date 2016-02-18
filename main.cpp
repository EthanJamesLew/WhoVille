#include <iostream>
#include "profiler.h"
#include "people.h"
#include <unistd.h>
#include "utils.h"

int main(int argc, char *argv[])
{
	system("sh whofile.sh");
	
	People *ppl = new People();
	
	std::cout << "Room size: " << ppl->getNumPeople() << std::endl;

	while (true)
	{
		unsigned int sleep(.01);
		ppl->updateWho();
		if (ppl->getDeltaPeople().size() != 0)
		{
			std::cout << utils::vectorToStr(ppl->getDeltaPeople()) <<" has changed."<< std::endl;
			std::cout << "Room size: " << ppl->getNumPeople() << std::endl;
		}
	}

	return 0;
}
