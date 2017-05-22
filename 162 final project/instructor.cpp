//Program Filename: instructor.cpp
//Author: David Sahni
//Date: 3/22/2017
//Description: implementation file for instructor
//Input: n/a
//Output: 
#include "instructor.hpp"


char Instructor::get_move() {
	return '0';
}

void Instructor::setloc(int i, int j) {
	row = i;
	column = j;
}
int Instructor::getrow() {
	return row;
}
int Instructor::getcol() {
	return column;
}