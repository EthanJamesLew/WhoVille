#include <iostream>
#include "profiler.h"
#include "people.h"
#include <unistd.h>
#include "utils.h"

int main(int argc, char *argv[])
{
	system("sh whofile.sh");
	
	int num = 0;
	int num2 =0;
	
	People *ppl = new People();

	while (true)
	{
		num = ppl->getNumPeople()
		unsigned int sleep(.01);
		ppl->updateWho();
		if (num != num2)
		{
			std::cout << utils::vectorToStr(ppl->getDeltaPeople()) <<" has changed."<< std::endl;
			std::cout << "Room size: " << ppl->getNumPeople() << std::endl;
			num2 = num;
		}
	}

	return 0;
}
