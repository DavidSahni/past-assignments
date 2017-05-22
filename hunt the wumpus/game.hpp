//Program Filename: game.hpp
//Author: David Sahni
//Date: 3/6/17
//Description: game header file
//Input: n/a
//Output: defines game class
#ifndef _game
#define _game

#include "room.hpp"
#include "event.hpp"
#include "wumpus.hpp"
#include "bats.hpp"
#include "pit.hpp"
#include "gold.hpp"
#include "rope.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>

class Game {
private: 
	std::vector<std::vector<Room> > cave;
	int roomnum;
	player p1;
	bool gamerunning;
	Wumpus w;
	Bats b;
	Pit p;
	Gold g;
	Rope r;
	int wumpi;
	int wumpj;
public:
	Game(int);
	int getusrchoice();
	void giveevents();
	void setwumpus(char);
	void printgrid();
	void setbandp(char x);
	void startplayer();
	void gameflow();
	void playermove();
	bool move();
	bool firearrow();
	void checkplayerpos();
	void percepts();
	void hitormiss(bool);
};

#endif