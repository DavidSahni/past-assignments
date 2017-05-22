//Program Filename: mazeperson.hpp
//Author: David Sahni
//Date: 3/22/2017
//Description: mazeperson header file
//Input: n/a
//Output: mazeperson class defined
#ifndef mazeperson
#define mazeperson

#include <iostream>

class Mazeperson {
public:
	virtual char get_move();
	virtual void setloc(int, int);
	virtual int getrow();
	virtual int getcol();
	virtual void addproskill();
	virtual void useproskill();
	virtual int getproskill();
	virtual char getusrchoice();
};


#endif