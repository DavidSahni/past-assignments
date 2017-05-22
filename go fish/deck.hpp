//Program Filename: deck.hpp
//Author: David Sahni
//Date: 2/6/2017
//Description: deck header file
//Input: n/a
//Output:

#ifndef deck_
#define deck_
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "card.hpp"
using namespace std;


class deck {
private:
	card cards[52];
	int n_cards;
	int cardplace;
public:
	deck();
	~deck();
	card dealcard();
	void shuffledeck();
	card getcard(int);
};

#endif