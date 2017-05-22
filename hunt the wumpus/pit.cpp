//Program Filename: pit.cpp
//Author: David Sahni
//Date: 3/6/17
//Description: pit implementation file
//Input: n/a
//Output: pit functions are run
#include "pit.hpp"

void Pit::runevent(int roomnum, player& p1, bool& gamerunning) {
	std::cout << std::endl << "The darkness of the room makes it impossible  to see where you are going" << std::endl;
	std::cout << "As you take your next step, you feel your foot pass where the floor should be..." << std::endl;
	std::cout << "Suddenly you are hurtling downward, flailing as you fall!" << std::endl;
	gamerunning = false;
}
void Pit::perception() {
	std::cout << "You feel a breeze..." << std::endl;
}

Pit::Pit() {};

bool Pit::iswumpus() {
	return false;
}