edit:
	g++ -std=c++11 -I ./include -I ./src -o WhoVille ./src/main.cpp ./src/utils.cpp ./src/people.cpp ./src/profiler.cpp
clean:
	rm -f WhoVille
