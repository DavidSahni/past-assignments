//Program Filename: player.hpp
//Author: David Sahni
//Date: 2/6/2017
//Description: player class header file
//Input: n/a
//Output: n/a

#ifndef player_
#define player_
#include "hand.hpp"
#include <iostream>

class player {
private:
	hand myhand;
	int* books;
	int n_books;

public:
	player();
	void playermakehand(deck*);
	~player();
	hand pgethand();
	void psethand(hand);
	void printhand();
	void bookset(int book);
	int* getbooks();
	int getn_books();
	void newhand(hand*);
	void copyhand(hand*);
	void addhand(card*, int);
	int addcard(card, int);
	void removebook(int book);
	int randomcard();
};
#endif