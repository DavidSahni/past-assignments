//Program Filename: wall.hpp
//Author: David Sahni
//Date: 3/22/2017
//Description: wall headerfile
//Input: n/a
//Output: wall class defined
#ifndef _wall
#define _wall

#include "mazelocation.hpp"

class wall : public mazelocation {
public:
	bool is_occupiable();
	char get_display_character();

};

#endif