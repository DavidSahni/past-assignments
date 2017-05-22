//Program Filename: deck.cpp
//Author: David Sahni
//Date: 2/6/2017
//Description: deck implementation file
//Input: n/a
//Output: creates a deck with 52 cards

#include "deck.hpp"

deck::deck() {
	n_cards = 52;
	cardplace = 0;
	int i = 0;
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 13; k++) {
			cards[i].setcard(k, j);
			i++;

		}
	}
}


deck::~deck() {

}

card deck::dealcard() {
	cardplace++;
	return cards[cardplace-1];
}

void deck::shuffledeck() {
	int index, cardleft = n_cards - cardplace;
	srand(time(NULL));
	for (int i = cardplace; i < n_cards; i++) {
		index = rand() % cardleft + cardplace;
		card temp = cards[index];
		cards[index] = cards[i];
		cards[i] = temp;
	}
}

card deck::getcard(int i) {
	return cards[i];

}