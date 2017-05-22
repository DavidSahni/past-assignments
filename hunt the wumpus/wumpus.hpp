//Program Filename: Wumpus.hpp
//Author: David Sahni
//Date: 3/6/17
//Description: Wumpus class header file
//Input: n/a
//Output: wumpus class defined
#ifndef wump
#define wump

#include "event.hpp"

class Wumpus : public Events {
public:
	void runevent(int, player&, bool&);
	Wumpus();
	void perception();
	bool iswumpus();
};

#endif