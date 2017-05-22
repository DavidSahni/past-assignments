//Program Filename: game.hpp
//Author: David Sahni
//Date: 2/6/2017
//Description: game header file
//Input: n/a
//Output: n/a

#ifndef _game
#define _game

#include "player.hpp"
#include "hand.hpp"


#include <cstdlib>

class game {
private:
	deck* deck1;
	player players[2];
	bool finished;
	//int realplayers;

public:
	game();
	void gprinthand(int);
	void gamestart();
	~game();
	void playerstatus(int n);
	bool playerturn(int);
	int isgood(int);
	int searchhand(int, int);
	void stealcards(int, int, int);
	int gofish(int);
	void playerbooks(int);
	bool cputurn(int);
	void pause(int i);
	bool playerbase();
	bool cpubase();
};




#endif