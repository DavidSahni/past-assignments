//Program Filename: event.cpp
//Author: David Sahni
//Date: 3/6/17
//Description: event class implementation file
//Input: n/a
//Output: event class functions run
#include "event.hpp"

void Events::runevent(int roomnum, player& p1, bool& gamerunning) {
	std::cout << "The event clas runevent ran something is broken..." << std::endl;
}

void Events::perception() {
	std::cout << "You see a bug in the code because this function should not be run" << std::endl;
}

Events::Events(){}

bool Events::iswumpus() {
	return false;
}