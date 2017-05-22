//Program Filename: maze.hpp
//Author: David Sahni
//Date: 3/22/2017
//Description: maze class header file
//Input: n/a
//Output: maze class defined
#ifndef mazer
#define mazer

#include <stdlib.h>
#include "mazelevel.hpp"
#include "student.hpp"
#include "ta.hpp"
#include "instructor.hpp"

class Maze {
private:
	bool win;
	int numlevels;
	int row;
	int column;
	int lev;
	Mazelevel** levels;
	intrepidstudent s1;
	Ta tas[2];

public:
	Maze( std::ifstream&, int, int, int);
	void setmaze(int);
	void setstudent(int);
	void settas(int);
	void setskills(int);
	void levelflow();
	bool playermove();
	void tamove();
	void checkpos();
	bool tacheck(int, int);
	void resetlevel(int);
	bool checkins();
	bool insnear(int i, int j);
	void gameflow();
	~Maze();
};


#endif