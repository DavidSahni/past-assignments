//Program Filename: 
//Author: David Sahni
//Date: 2/6/2017
//Description: 
//Input: n/a
//Output: all card implementation files

#include "card.hpp"
//Function: card constructor
//Description: initializes a card at 0 0
//Parameters: none
//Pre conds: none
//Post conds: card has data
card::card() {
	rank = 0;
	suit = 0;
}

//Function: card destructor
//Description: destructor for card class
//Parameters: n/a
//Pre conds: n/a
//Post conds: destructed
card::~card() {

}

//Function: setcard
//Description: sets a card rank and suit
//Parameters: int r: rank, int s: suit
//Pre conds: n/a
//Post conds: card has values inputted for rank and suit
void card::setcard(int r, int s) {
	rank = r;
	suit = s;
}

//Function: getrank
//Description: getter for rank of card
//Parameters: n/a
//Pre conds: n/a
//Post conds: returns rank int
int card::getrank() {
	return rank;
}

//Function: getsuit
//Description: getter for suit of card
//Parameters: n/a
//Pre conds: n/a
//Post conds: returns suit int
int card::getsuit() {
	return suit;
}