//Program Filename: Ta.hpp
//Author: David Sahni
//Date: 3/22/2017
//Description: ta header file
//Input: n/a
//Output: ta class defined
#ifndef ta
#define ta

#include <stdlib.h>
#include <iostream>

class Ta {
private:
	int ei;
	int ej;
	int turnc;
	bool appeased;
public:
	char get_move();
	void setloc(int, int);
	int getrow();
	int getcol();
	void appease(bool);
	bool isappeased();
};


#endif