//Program Filename: huntthewumpus.cpp
//Author: David Sahni
//Date: 3/6/17
//Description: hunt the wumpus driver file
//Input: int argc, char** argv
//Output: n/a
#include <iostream>

#include <vector>
#include <time.h>

#include "wumpus.hpp"
#include "room.hpp"
#include "event.hpp"
#include "player.hpp"
#include "game.hpp"


int getroomnum(int argc, char** argv);
void checkroomnum(int&);
bool playhtw(int);
int getusrchoice();

//Function: main
//Description: main function for hunt the wumpus program
//Parameters: int argc: command line argument count, char* argv[]: command line argument data
//Pre conds: none
//Post conds:  hunt the wumpus program run
int main(int argc, char* argv[]) {
	srand(time(NULL));
	int roomnum;
	roomnum = getroomnum(argc, argv);
	bool newmap = true;
	while (newmap) {
		newmap = playhtw(roomnum);
	}
}

//Function: getusrchoice
//Description: sanitizes a user input
//Parameters: none
//Pre conds: none
//Post conds: returns an integer value
int getusrchoice() {
	bool isbad = true;
	std::string temp;
	while (isbad) {
		std::cout << "Please enter your choice: ";
		std::cin >> temp;
		if (atoi(temp.c_str()) <= 0)
			std::cout << "Invalid choice" << std::endl;
		else if (atoi(temp.c_str()) > 3)
			std::cout << "Please choose an option between 1 and 3" << std::endl;
		else
			isbad = false;
	}
	return atoi(temp.c_str());
}

//Function: playhtw
//Description: function that creates a game of hunt the wumpus and plays it
//Parameters: int roomnum: number of rooms as entered by the user
//Pre conds: none
//Post conds: game of hunt the wumpus will be played, could run multiple games
bool playhtw(int roomnum) {
	bool samemap = true;
	Game g1(roomnum);
	int c;
	while (samemap) {
		std::cout << "	Welcome to Hunt The Wumpus			Created by: David Sahni" << std::endl;
		g1.gameflow();
		std::cout << "Would you like to play again ?" << std::endl << "1: Yes (Same map)" << std::endl << "2: New map" << std::endl << "3: Exit" << std::endl;
		c = getusrchoice();
		if (c == 1) {
			g1.startplayer();
		}
		else if (c == 2)
			return true;
		else if (c == 3)
			return false;
	}
}

//Function: getroomnum
//Description: verifies there is an entered room number
//Parameters: int argc: number of cmd line args, char** argv: cmd line args data
//Pre conds: none
//Post conds: 
int getroomnum(int argc, char** argv) {
	if (argc < 2) {
		int temp;
		std::cout << "Please enter the size of Wumpus' cave: ";
		std::cin >> temp;
		return temp;
	}
	else {
		return atoi(argv[1]);
	}
}
//Function: checkroomnum
//Description: checks that the roomnumbers are > 4
//Parameters: int& roomnum: number to be checked changed if bad
//Pre conds: none
//Post conds: roomnum > 4
void checkroomnum(int& roomnum) {
	while (roomnum < 4) {
		std::cout << "The cave must be larger than 4x4" << std::endl << "Please enter the number of rooms: ";
		std::cin >> roomnum;
	}
}
