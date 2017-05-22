//Program Filename: mazelevel.hpp
//Author: David Sahni
//Date: 3/22/2017
//Description: mazelevel header file
//Input: n/a
//Output: mazelevel class defined
#ifndef _maze
#define _maze

#include "mazelocation.hpp"
#include "openspace.hpp"
#include "wall.hpp"

#include <stdlib.h>
#include <iostream>
#include <fstream>

class Mazelevel {
private:
	mazelocation*** locations;
	int row;
	int column;
public:
	Mazelevel(std::ifstream&, int, int);
	Mazelevel();
	~Mazelevel();
	mazelocation* get_location(int, int);
	void displaymaze();
	void operator=(const Mazelevel&);
};

#endif