//Program Filename: rope.hpp
//Author: David Sahni
//Date: 3/6/17
//Description: rope class header file
//Input: n/a
//Output: rope class defined
#ifndef ropeee
#define ropeee

#include "event.hpp"

class Rope : public Events {
public:
	Rope();
	void runevent(int, player&, bool&);
	void perception();
	bool iswumpus();
};

#endif