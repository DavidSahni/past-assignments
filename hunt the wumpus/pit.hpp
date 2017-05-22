//Program Filename: pit.hpp
//Author: David Sahni
//Date: 3/6/17
//Description: pit header file
//Input: n/a
//Output: defines pit classs
#ifndef pits
#define pits

#include "event.hpp"

class Pit : public Events {
public:
	Pit();
	void runevent(int, player&, bool&);
	void perception();
	bool iswumpus();
};

#endif 