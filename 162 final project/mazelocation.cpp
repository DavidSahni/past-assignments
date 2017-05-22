//Program Filename: mazelocation.cpp
//Author: David Sahni
//Date: 3/22/2017
//Description: mazelocation implementation file
//Input: n/a
//Output:
#include "mazelocation.hpp"

bool mazelocation::is_occupiable() {
	return true;
}

char mazelocation::get_display_character() {
	return 0;
}

void mazelocation::set_student(bool x) {}
bool mazelocation::has_student() {
}
void mazelocation::set_start(bool) {}
bool mazelocation::is_start() {
}
void mazelocation::set_ladder(bool) {}
bool mazelocation::is_ladder() {}

void mazelocation::set_ta(bool) {}
bool mazelocation::has_ta() {}
void mazelocation::set_instructor(bool) {}
bool mazelocation::has_instructor() {}
void mazelocation::set_skills(bool) {}
bool mazelocation::has_skills() {}