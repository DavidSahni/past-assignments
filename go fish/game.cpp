//Program Filename: game.cpp
//Author: David Sahni
//Date: 2/6/2017
//Description: game implementation file
//Input: n/a
//Output: runs the game

#include "game.hpp"

//Function: game
//Description: Game class constructor, 
//Parameters: n/a
//Pre conds: n/a
//Post conds: new deck made, both players are given a hand
game::game() {
	finished = false;
	deck1 = new deck;
	deck1->shuffledeck();
	players[0].playermakehand(deck1);
	players[1].playermakehand(deck1);
}

//Function: gprinthand
//Description: Prints the hand of a given player
//Parameters: int n: number of which player to print
//Pre conds: players[n] must not be null
//Post conds: text printed to the screen
void game::gprinthand(int n) {
	players[n].printhand();
}

//Function: ~game
//Description: game class destructor, frees memory
//Parameters: n/a
//Pre conds: n/a
//Post conds: deck1 memory freed
game::~game() {
	delete deck1;
}

//Function: pause
//Description: pauses the game until the user presses enter (uses system command)
//Parameters: int i: which prompt to display (whose turn is it about to be)
//Pre conds: n/a
//Post conds: program halted until user presses enter
void game::pause(int i) {
	char pause;
	string prompt[2] = { "the computer's", "your" };
	cout << "Press enter to continue to " << prompt[i] << " turn" << endl;
	cin.ignore(!i);
	pause = cin.get();
	system("clear");
}

//Function: playerbase
//Description: base function for the player's turn
//Parameters: n/a
//Pre conds: n/a
//Post conds: a player's full turn is run from this function
bool game::playerbase() {
	bool turn = true;
	while (turn) {
		turn = this->playerturn(0);
		this->playerbooks(0);
		this->playerstatus(0);
		if (players[0].getn_books() + players[1].getn_books() == 13) {
			return true;
		}
	}
}

//Function: cpubase
//Description: base function for the cpu's turn
//Parameters: n/a
//Pre conds: n/a
//Post conds: a cpu's turn will be run
bool game::cpubase() {
	bool turn = true;
	while (turn) {
		turn = this->cputurn(1);
		this->playerbooks(1);
		cout << "The computer has " << players[1].getn_books() << " book(s)" << endl;
		if (players[0].getn_books() + players[1].getn_books() == 13)
			return true;
	}
}

//Function: gamestart
//Description: starts and runs the flow of the game
//Parameters: n/a
//Pre conds: n/a
//Post conds: runs the entire game class
void game::gamestart() {
	cout << "Welcome to Go Fish!" << endl;
	while (!finished) {
		if (this->playerbase())
			break;
		this->pause(0);
		if (this->cpubase())
			break;
		this->pause(1);
		
	}
	if (players[0].getn_books() > players[1].getn_books()) {
		cout << "Congratulations, you won with " << players[0].getn_books() << " books!!" << endl;
	}
	else
		cout << "The computer won with " << players[1].getn_books() << " books, better luck next time!" << endl;

}

//Function: cputurn
//Description: runs one cpu turn
//Parameters: int n: integer input to denote which player is being called
//Pre conds: n/a
//Post conds: single cpu turn run
bool game::cputurn(int n) {
	cout << "It is the cpu's turn!" << endl;
	int search = players[n].randomcard();
	cout << "The computer searched for " << search << endl;
	cout << "You had " << searchhand(!n, search) << endl;
	if (searchhand(!n, search) == 0) {
		int fished = gofish(n);
		if (fished == search) {
			cout << "The computer drew a " << search << endl;
			return true;
		}
	}
	else {
		cout << "You gave the computer " << searchhand(!n, search) << " " << search << "(s)" << endl;
		stealcards(n, search, searchhand(!n, search));
		return true;
	}
	return false;
}

//Function: playerbooks
//Description: creates books (sets of 4) based on players cards
//Parameters: int n: which player is being searched
//Pre conds: player being searched must not be null
//Post conds: player books found and bookset called
void game::playerbooks(int n) {
	for (int i = 0; i < 13; i++) {
		if (searchhand(n, i) == 4) {
			players[n].bookset(i);
			if (n == 0) {
				cout << "You created a book of " << i << "'s" << endl << endl;
			}
			else
				cout << "The computer created a book of " << i << "'s" << endl << endl;
		}
	}
}

//Function: playerturn
//Description: runs a single player turn
//Parameters: int n: which player is having a turn
//Pre conds: player[n] must not be null
//Post conds: full player turn will be run
bool game::playerturn(int n) {
	cout << "It is your turn! "<< endl;
	if (players[n].pgethand().howmany() == 0) {
		cout << "Your hand is empty! Draw a card!" << endl;
		gofish(n);
	}
	this->playerstatus(n);
	cout << "What would you like to search for?" << endl;
	int search = isgood(n);
	cout << endl << "You searched for " << search << endl;
	cout << "your opponent had " << searchhand(!n, search) << endl << endl;
	if (searchhand(!n, search) == 0) {
		cout << "Go Fish!!" << endl << endl;
		int fished = gofish(n);
		if (fished == search) {
			return true;
		}
	}
	else {
		stealcards(n, search, searchhand(!n, search));
		return true;
	}
	return false;
}

//Function: gofish
//Description: performs the go fish act of drawing from the deck
//Parameters: int n: player number recieving the new card
//Pre conds: player[n] must not be null
//Post conds: players[n] will have another card, returns the numerical value of that card
int game::gofish(int n) {
	int fished = players[n].addcard(deck1->dealcard(), n);
	return fished;
}

//Function: stealcards
//Description: removes cards from opposing player, adds the cards to current player
//Parameters: int n: number of current player, int search: card value to be removed, int numcards: number of cards being stolen
//Pre conds: players must not be null
//Post conds: cards removed from opposing player, new cards added to current player
void game::stealcards(int n, int search, int numcards) {
	hand* temphand = new hand;
	players[!n].newhand(temphand);
	card* stolen = new card[numcards];
	int j = 0;
	for (int i = 0; i < temphand->howmany(); i++) {
		if (search == temphand->gethand()[i].getrank()){
			stolen[j] = temphand->gethand()[i];
			j++;
			temphand->removecard(i);
			i--;
		}
	}
	players[!n].copyhand(temphand);
	players[n].addhand(stolen, numcards);
	delete[] stolen;
	delete temphand;
}

//Function: isgood
//Description: sanitizes a card input from the user
//Parameters: int n: player who is inputting a card to search for
//Pre conds: n/a
//Post conds: recieves input from the user, returns an integer
int game::isgood(int n) {
	bool bad = true;
	string temp;
	while (bad) {
		cin >> temp;
		if (searchhand(n, atoi(temp.c_str())) == 0) {
			cout << "Please enter a rank that you have!" << endl;
		}
		else
			bad = false;
	}
	return atoi(temp.c_str());
}

//Function: searchhand
//Description: searchs through a given players hand for a given card value, returns the number of cards found
//Parameters: int n: player whose hand to search, int search: card value to search
//Pre conds: players[n] must not be null
//Post conds: returns number of cards found
int game::searchhand(int n, int search) {
	int searchnum = 0;
	hand* temphand = new hand;
	this->players[n].newhand(temphand);
	for (int i = 0; i < temphand->howmany(); i++) {
		if (search == temphand->gethand()[i].getrank()) {
			searchnum++;
		}
	}
	delete temphand;
	return searchnum;
}

//Function: playerstatus
//Description: prints the status of the player to the screen (hand information, book information)
//Parameters: int n: player to be printed
//Pre conds: player[n] must not be null
//Post conds: information printed to the screen
void game::playerstatus(int n) {
	cout << "Your hand is: " << endl;
	this->gprinthand(n);
	cout << "You have " << players[n].getn_books() << " book(s)" << endl;
	if (players[n].getn_books() > 0) {
		cout << "Your books are: ";
		for (int i = 0; i < players[n].getn_books(); i++) {
			cout << players[n].getbooks()[i];
			if (i != players[n].getn_books() - 1) {
				cout << ", ";
			}
		}
		cout << endl;
	}
}