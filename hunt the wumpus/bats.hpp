//Program Filename: bats.hpp
//Author: David Sahni
//Date: 3/6/17
//Description: bats header file
//Input: n/a
//Output: bats class defined
#ifndef _battys
#define _battys
#include "event.hpp"
#include <cstdlib>

class Bats : public Events {
public:
	void runevent(int, player&, bool&);
	Bats();
	void perception();
	bool iswumpus();
};


#endif
