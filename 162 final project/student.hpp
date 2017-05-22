//Program Filename: student.hpp
//Author: David Sahni
//Date: 3/22/2017
//Description: intrepidstudent headerfile
//Input: n/a
//Output: intrepidstudent class defined
#ifndef intrepids
#define intrepids

#include "mazeperson.hpp"

class intrepidstudent : public Mazeperson {
private:
	int row;
	int col;
	int proskills;
public:
	intrepidstudent();
	char get_move();
	void setloc(int, int);
	int getrow();
	int getcol();
	void addproskill();
	void useproskill();
	int getproskill();
	char getusrchoice();
	void resetskills();
};

#endif