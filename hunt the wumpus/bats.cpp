//Program Filename: bats.cpp
//Author: David Sahni
//Date: 3/6/17
//Description: bats implementation file
//Input: n/a
//Output: runs bats functions
#include "bats.hpp"

Bats::Bats(){}

void Bats::runevent(int roomnum, player& p1, bool& gamerunning) {
	std::cout << std::endl << "As you enter the room, giant bats swoop down from the rafters!!" << std::endl <<
		"You feel its massive talons digging into your shoulders as it lifts you into the air!" << std::endl << std::endl;
	int i = rand() % roomnum;
	int j = rand() % roomnum;
	p1.i = i;
	p1.j = j;
	p1.moved = true;
	
}

void Bats::perception() {
	std::cout << "You hear wings flapping..." << std::endl;
}
bool Bats::iswumpus() {
	return false;
}