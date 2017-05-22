//Program Filename: ta.cpp
//Author: David Sahni
//Date: 3/22/2017
//Description: ta class implementation file
//Input: n/a
//Output: 
#include "ta.hpp"


char Ta::get_move() {
	int c = rand() % 4;
	if (c == 0)
		return 'W';
	else if (c == 1)
		return 'D';
	else if (c == 2)
		return 'S';
	else if (c == 3)
		return 'A';
}
void Ta::setloc(int i, int j) {
	ei = i;
	ej = j;
}
int Ta::getrow() {
	return ei;
}
int Ta::getcol() {
	return ej;
}

void Ta::appease(bool x) {
	appeased = x;
	if (appeased)
		turnc = 10;
	else
		turnc = 0;
}

bool Ta::isappeased() {
	turnc--;
	if (turnc == 0) {
		std::cout << "Programming skill's effect has worn off" << std::endl;
	}
	if (turnc < 0)
		return false;
	return appeased;
}