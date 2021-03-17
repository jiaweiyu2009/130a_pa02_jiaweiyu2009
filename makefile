all: runEverything 

runEverything: main.cpp heap.cpp
	g++ -std=c++11 -o prog2.out main.cpp heap.cpp

