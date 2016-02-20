#include <iostream>
#include "profiler.h"
#include "people.h"
#include <unistd.h>
#include "utils.h"
#include<vector>

int main(int argc, char *argv[])
{
	system("sh whofile.sh");
	
	int num = 0;
	int num2 =0;
	
	std::vector<std::string> alert = utils::nameInFile('conf/users_sms.conf');

	People *ppl = new People();

	std::vector<Profiler> users;

	std::vector<std::string> init = ppl->getPeopleList();

	for (unsigned i = 0; i < init.size(); i++)
	{
		users.push_back(Profiler(init[i]));
	}


	while (true)
	{
		num = ppl->getNumPeople();
		unsigned int sleep(.01);
		ppl->updateWho();
		if (ppl->getJoined().size() > 0 ||  ppl->getLeft().size() > 0)
		{
			if (ppl->getJoined().size() > 0)
			{
				std::vector<std::string> joined = ppl->getJoined();
				std::cout << utils::vectorToStr(ppl->getJoined()) << " has joined." << std::endl;
			
				for (unsigned i = 0; i < joined.size(); i++)
				{
					if (std::find(users.begin(), users.end(), joined[i]) != users.end())
					{
						std::string command = "python python/sms.py " + joined[i] + " online";
						system(command.c_str());
					}
					users.push_back(Profiler(joined[i]));
				}
				
			}
			else
			{
				std::vector<std::string> left = ppl->getLeft();
				std::cout <<utils::getTimeAsStr()<<": " <<utils::vectorToStr(ppl->getLeft()) << "has left.";

				for (unsigned i = 0; i < left.size(); i++)
				{
					for (unsigned j = 0; j < users.size(); j++)
					{
						if (users[j].getName() == left[i])
						{
							std::cout <<" Time spent on server: "<< users[j].getMinSpent() <<" minutes."<<std::endl;
							if (std::find(users.begin(), users.end(), left[i]) != users.end())
							{
								std::string command = "python python/sms.py " + left[i] + " offline";
								system(command.c_str());
							}
							users.erase(users.begin() + j);
						}
					}
				}

			}
			std::cout << "People online: " << ppl->getNumPeople() << std::endl;
			ppl->resetLists();
		}
	}

	return 0;
}
