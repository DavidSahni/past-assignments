//Program Filename: rope.cpp
//Author: David Sahni
//Date: 3/6/17
//Description: implementation file for rope class
//Input: n/a
//Output: n/a
#include "rope.hpp"

void Rope::perception() {}

void Rope::runevent(int roomnum, player& p1, bool& gamerunning) {
	if (p1.hasgold && p1.killwump) {
		std::cout << std::endl << "You made your way back to the escape rope after killing the wumpus and finding the gold!!" << std::endl;
		p1.win = true;
		gamerunning = false;
	}
}

Rope::Rope() {}

bool Rope::iswumpus() {
	return false;
}