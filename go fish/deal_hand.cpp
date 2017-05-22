//Program Filename: deal_hand.cpp
//Author: David Sahni
//Date: 2/6/2017
//Description: Application file for gofish program
//Input: n/a
//Output: runs the game

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"


//Function: main
//Description: main function for gofish program
//Parameters: n/a
//Pre conds: j/a
//Post conds: gofish is run, user is asked whether they want to to end, program ends at selection
int main() {
	bool playing = true;
	while (playing) {
		game game1;
		game1.gamestart();
		cout << endl << endl << "If you would like to play again, enter 1, if not, enter 0!" << endl;
		cin >> playing;
	}
	return 0;
}