//Program Filename: instructor.hpp
//Author: David Sahni
//Date: 3/22/2017
//Description: header file for instructor class
//Input: n/a
//Output: instructor class define
#ifndef hessisbest
#define hessisbest

#include "mazeperson.hpp"

class Instructor : public Mazeperson {
private:
	int row;
	int column;
public:
	char get_move();
	void setloc(int, int);
	int getrow();
	int getcol();
};

#endif