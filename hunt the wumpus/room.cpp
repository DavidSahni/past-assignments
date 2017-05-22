//Program Filename: room.cpp
//Author: David Sahni
//Date: 3/6/17
//Description: room implementation file
//Input: n/a
//Output: room functions run
#include "room.hpp"

void Room::setevent(Events* eptr) {
	eventpointer = eptr;
	hasevent = true;
}

Room::Room() {
	hasevent = false;
	marker = '*';
}

void Room::doevent(int roomnum, player& p1, bool& gamerunning) {
	if (hasevent == true) {
		eventpointer->runevent(roomnum, p1, gamerunning);
	}
	else  {
		std::cout << "no event here" << std::endl;
	}
}

char Room::printit() {
	return marker;
}

bool Room::haveevent() {
	return hasevent;
}

void Room::setmarker(char x) {
	this->marker = x;
}

void Room::percieve() {
	if (hasevent)
		eventpointer->perception();
}

bool Room::wumpushere() {
	if (hasevent) {
		return eventpointer->iswumpus();
	}
	else
		return false;
}

void Room::killevent() {
	hasevent = false;
	marker = '*';
}