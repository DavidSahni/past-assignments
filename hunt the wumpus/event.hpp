//Program Filename: event.hpp
//Author: David Sahni
//Date: 3/6/17
//Description: event class header file
//Input: n/a
//Output: event class defined
#ifndef _event
#define _event

#include "player.hpp"
#include <iostream>

class Events {
private:
public:
	virtual void runevent(int, player&, bool&);	
	virtual void perception();
	Events();
	virtual bool iswumpus();
};


#endif