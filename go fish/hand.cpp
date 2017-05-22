//Program Filename: hand.cpp
//Author: David Sahni
//Date: 2/6/2017
//Description: hand class implementation file
//Input: n/a
//Output: runs all hand functions

#include "hand.hpp"

//Function: howmany
//Description: returns how many cards are the array
//Parameters: none
//Pre conds: none
//Post conds: returns n_cards int
int hand::howmany() {
	return n_cards;
}

//Function: hand copy constructor
//Description: hand copy constructor
//Parameters: const hand&: hand to be copied
//Pre conds: hand class should have values
//Post conds: hand item is copied
hand::hand(const hand& other) {
	this->n_cards = other.n_cards;
	this->cards = new card[this->n_cards];
	for (int i = 0; i < this->n_cards; i++) {
		this->cards[i] = other.cards[i];
	}
}

//Function: equal operator overload
//Description: copies item into hand class without messing up dynamic stuff
//Parameters: hand to be copied
//Pre conds: n/a
//Post conds: new hand object is copied
void hand::operator=(const hand& other) {
	this->n_cards = other.n_cards;
	this->cards = new card[this->n_cards];
	for (int i = 0; i < this->n_cards; i++) {
		this->cards[i] = other.cards[i];
	}
}

//Function: hand constructor
//Description: default hand constructor
//Parameters: none
//Pre conds: none
//Post conds: n_cards set to 0
hand::hand() {
	n_cards = 0;
}

//Function: gethand
//Description: returns card array
//Parameters: n/a
//Pre conds: n/a
//Post conds: returns card array
card* hand::gethand() {
	return cards;
}

//Function: setcard
//Description: adds a card to the hand
//Parameters: card: card to be dealt
//Pre conds: card has to exist/have info
//Post conds: hand will have an extra card
void hand::setcard(card deal) {
	cards = addcard();
	cards[n_cards] = deal;
	n_cards++;
}


//Function: addcard
//Description: increases card array size by one
//Parameters: none
//Pre conds: none
//Post conds: card* size is increased
card* hand::addcard() {
	card* temp;
	temp = new card[n_cards + 1];
	for (int i = 0; i < n_cards; i++) {
		temp[i] = cards[i];
	}
	if (n_cards > 0) {
		delete[] cards;
	}
	return temp;
}

//Function: remove card
//Description: removes a card from card* array
//Parameters: int card to be removed
//Pre conds: none
//Post conds: card* has less cards
void hand::removecard(int bcard) {
	n_cards--;
	card* temp = new card[n_cards];
	int j = 0;
	for (int i = 0; i < n_cards+1; i++) {
		if (i != bcard) {
			temp[j] = this->cards[i];
			j++;
		}
	}
	delete[] cards;
	cards = temp;
}
//Function: hand destructor
//Description: destroys hand class object, deleting dyn memory
//Parameters: none
//Pre conds: hand object cannot have been deleted
//Post conds: card* memory freed
hand::~hand() {
	if (n_cards > 0) {
		delete[] cards;
	}
}

