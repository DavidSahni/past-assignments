//Program Filename: wumpus.cpp
//Author: David Sahni
//Date: 3/6/17
//Description: wumpus class implementation file
//Input: n/a
//Output: wumpus clas functions are run
#include "wumpus.hpp"

void Wumpus::runevent(int roomnum, player& p1, bool& gamerunning) {
	std::cout << std::endl << "As you enter the room, the punget smell grows even stronger" << std::endl;
	std::cout << "You see a massive shape in the corner lurch to its feet" << std::endl <<
		"As the door behind you swings shut, the Wumpus lunges towards you with terrifying speed!" << std::endl << std::endl;
	gamerunning = false;
}

void Wumpus::perception() {
	std::cout << "You smell a terrible stench" << std::endl;
}

Wumpus::Wumpus(){}

bool Wumpus::iswumpus() {
	std::cout << std::endl << "You hear a scream as your arrow pierces the Wumpus' heart" << std::endl;
	return true;

}