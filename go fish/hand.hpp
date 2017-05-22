//Program Filename: hand.hpp
//Author: David Sahni
//Date: 2/6/2017
//Description: hand header file
//Input: n/a
//Output: n/a

#ifndef hand_hpp
#define hand_hpp

#include "deck.hpp"

class hand {
private:
	card* cards;
	int n_cards;

public:
	hand(const hand&);
	hand();
	card* gethand();
	void setcard(card);
	card* addcard();
	~hand();
	int howmany();
	void operator= (const hand&);
	void removecard(int);
};

#endif