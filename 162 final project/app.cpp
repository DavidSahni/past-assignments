//Program Filename: app.cpp
//Author: David Sahni
//Date: 3/22/2017
//Description: Driver file for Final Project
//Input: int argc: number of arguments, char* argv[]: command line argument for file name
//Output: Escape from cs162 is run

#include "mazelevel.hpp"
#include "ta.hpp"
#include "maze.hpp"
#include "student.hpp"
#include <time.h>
#include <stdlib.h>
#include <fstream>

int main(int argc, char* argv[]) {
	srand(time(NULL));
	std::ifstream infile;
	infile.open(argv[1]);
	if (infile.fail()) {
		std::cout << "Please enter a valid filename!" << std::endl;
		return 0;
	}
	int numlevels, height, width;
	infile >> numlevels >> height >> width;
	Maze m1(infile, numlevels, height, width);
	m1.gameflow();

	infile.close();

}