//Program Filename: openspace.cpp
//Author: David Sahni
//Date: 3/22/2017
//Description: openspace class implementation file
//Input: n/a
//Output: 
#include "openspace.hpp"

bool openspace::is_occupiable() {
	return true;
}


char openspace::get_display_character() {
	return marker;
}

void openspace::set_student(bool x) {
	student = x;
	if (student)
		marker = '*';
	else if (!student && isstart)
		marker = '@';
	else if (!student && isladder)
		marker = '^';
	else if (!student && ista)
		marker = 'T';
	else if (!student && isins)
		marker = '%';
	else
		marker = ' ';
}
bool openspace::has_student() {
	return student;
}
void openspace::set_start(bool x) {
	isstart = x;
	if (isstart)
		marker = '@';
}
bool openspace::is_start() {
	return isstart;
}
void openspace::set_ladder(bool x) {
	isladder = x;
	if (isladder)
		marker = '^';
}
bool openspace::is_ladder() {
	return isladder;
}

openspace::openspace() {
	student = false;
	isstart = false;
	isladder = false;
	ista = false;
	isins = false;
	isskills = false;
	marker = ' ';
}

void openspace::set_ta(bool x) {
	ista = x;
	if (ista && !student)
		marker = 'T';
	else if (ista && student)
		marker = '*';
	else if (!ista && isstart)
		marker = '@';
	else if (!ista && isladder)
		marker = '^';
	else if (!ista && isins)
		marker = '%';
	else if (!ista && isskills)
		marker = '$';
	else if (!ista && student)
		marker = '*';
	else
		marker = ' ';
}
bool openspace::has_ta() {
	return ista;
}
void openspace::set_instructor(bool x) {
	isins = x;
	if (isins)
		marker = '%';
}
bool openspace::has_instructor() {
	return isins;
}
void openspace::set_skills(bool x) {
	isskills = x;
	if (isskills)
		marker = '$';
}
bool openspace::has_skills() {
	return isskills;
}