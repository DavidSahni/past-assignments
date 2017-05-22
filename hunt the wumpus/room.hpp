#ifndef _room
#define _room
#include "player.hpp"
//Program Filename: Room.hpp
//Program Filename: 
//Author: David Sahni
//Date: 3/6/17
//Description: room header file
//Input: n/a
//Output: room class defined
#include "event.hpp"
#include "wumpus.hpp"
#include <iostream>

class Room {
private:
	bool hasevent;
	Events* eventpointer;
	char marker;
public:
	Room();
	void setevent(Events* eptr);
	void doevent(int, player&, bool&);
	char printit();
	bool haveevent();
	void setmarker(char);
	void percieve();
	bool wumpushere();
	void killevent();
};



#endif