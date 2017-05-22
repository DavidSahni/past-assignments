//Program Filename:  openspace.hpp
//Author: David Sahni
//Date: 3/22/2017
//Description: openspace header file
//Input: n/a
//Output: openspace class defined
#ifndef ospace
#define ospace

#include "mazelocation.hpp"

class openspace : public mazelocation {
private:
	bool student;
	bool isstart;
	bool isladder;
	bool ista;
	bool isins;
	bool isskills;
	char marker;
public:
	bool is_occupiable();
	char get_display_character();
	void set_student(bool);
	bool has_student();
	void set_start(bool);
	bool is_start();
	void set_ladder (bool);
	bool is_ladder();
	void set_ta(bool);
	bool has_ta();
	void set_instructor(bool);
	bool has_instructor();
	void set_skills(bool);
	bool has_skills();

	openspace();
};

#endif