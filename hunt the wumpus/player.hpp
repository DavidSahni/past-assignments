//Program Filename: player.hpp
//Author: David Sahni
//Date: 3/6/17
//Description: player struct header file
//Input: n/a
//Output: defines player struct
#ifndef _player
#define _player

struct player {
	int i;
	int j;
	int arrows;
	bool hasgold;
	bool win;
	bool moved;
	bool killwump;
};

#endif