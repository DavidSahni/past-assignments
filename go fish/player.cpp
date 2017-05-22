//Program Filename: player.cpp
//Author: David Sahni
//Date: 2/6/2017
//Description: player class implementation file
//Input: n/a
//Output: runs player functions

#include "player.hpp"

player::player() {
	books = new int[1];
	n_books = 0;
}
void player::playermakehand(deck* deck1) {
	for (int i = 0; i < 7; i++) {
		myhand.setcard(deck1->dealcard());
	}

}

void player::psethand(hand temp) {
	myhand = temp;	
}

hand player::pgethand() {
	return myhand;
}

player::~player() {
	delete[] books;
}

int player::addcard(card newcard, int n) {
	myhand.setcard(newcard);
	if (n == 0) {
		cout << endl << "You drew a " << newcard.getrank() << endl;
	}
	return newcard.getrank();
}

void player::printhand() {
	for (int i = 0; i < myhand.howmany() ; i++) {
		cout << "Card " << i + 1 << " is rank: ";
		cout << myhand.gethand()[i].getrank() << " and suit: " << myhand.gethand()[i].getsuit() << endl;
	}
}

void player::bookset(int book) {
	int* temp = new int[n_books + 1];
	for (int i = 0; i < n_books; i++) {
		temp[i] = books[i];
	}
	temp[n_books] = book;
	n_books++;
	delete[] books;
	books = temp;
	removebook(book);
}

void player::removebook(int book) {
	for (int i = 0; i < myhand.howmany(); i++) {
		if (myhand.gethand()[i].getrank() == book) {
			myhand.removecard(i);
			i--;
		}
	}
}

int* player::getbooks() {
	return books;
}

int player::getn_books() {
	return n_books;
}

void player::newhand(hand* temphand) {
	*temphand = myhand;
}

void player::copyhand(hand* temp) {
	myhand.~hand();
	myhand = *temp;
}

void player::addhand(card* stolen, int numcards) {
	for (int i = 0; i < numcards; i++) {
		myhand.setcard(stolen[i]);
	}
}

int player::randomcard() {
	srand(time(NULL));
	int randcard = rand() % myhand.howmany();
	return myhand.gethand()[randcard].getrank();
}