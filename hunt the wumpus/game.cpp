//Program Filename: game.cpp
//Author: David Sahni
//Date: 3/6/17
//Description: game class implementation file
//Input: n/a
//Output: game class functions run
#include "game.hpp"

//Function: Game
//Description: game class constructor
//Parameters: int x: number of rooms recieved from command line args
//Pre conds: none
//Post conds: game class object created 
Game::Game(int x) : roomnum(x) {
		for (int i = 0; i < roomnum; i++) {
			std::vector<Room> row;
			for (int j = 0; j < roomnum; j++) {
				Room temp;
				row.push_back(temp);
			}
			cave.push_back(row);
		}
		giveevents();
		startplayer();
	}

//Function: getusrchoice
//Description: function that input sanitizes an integer from the user
//Parameters: none
//Pre conds: none
//Post conds: returns an int
int Game::getusrchoice() {
	bool isbad = true;
	std::string temp;
	while (isbad) {
		std::cout << "Please enter your choice: ";
		std::cin >> temp;
		if (atoi(temp.c_str()) <= 0)
			std::cout << "Invalid choice" << std::endl;
		else
			isbad = false;
	}
	return atoi(temp.c_str());
}

//Function: giveevents
//Description: calls the functions to set the events in the rooms
//Parameters: none
//Pre conds: none
//Post conds: event giving functions called
void Game::giveevents() {
	setwumpus('W');
	setbandp('B');
	setbandp('P');
	setwumpus('G');
}

//Function: setwumpus
//Description: sets the wumpus and the gold on the map
//Parameters: char x, identifier to what is being placed + symbol for debugger mode
//Pre conds: none
//Post conds: wumpus pointer and gold pointers added to room objects
void Game::setwumpus(char x) {
	Events* eptr;
	bool isgood = false;
	while (!isgood) {
		int i = rand() % roomnum;
		int j = rand() % roomnum;
		if (!cave[i][j].haveevent()) {
			if (x == 'W') {
				eptr = &w;
				wumpi = i;
				wumpj = j;
				std::cout << "i: " << wumpi << " j: " << wumpj << std::endl;
			}
			else
				eptr = &g;
			cave[i][j].setevent(eptr);
			//cave[i][j].setmarker(x);
			//std::cout << "i: " << i << " j: " << j << std::endl;
			isgood = true;
		}
	}
}

//Function: setbandp
//Description: sets the bats and pits on the map
//Parameters: char x: identifier to what is being placed + symbol for debugger mode
//Pre conds: none
//Post conds: 
void Game::setbandp(char x) {
	Events* eptr;
	bool isgood = false;
	int numevent = 0;
	while (!isgood) {
		int i = rand() % roomnum;
		int j = rand() % roomnum;
		if (!cave[i][j].haveevent()) {
			if (x == 'B') {
				eptr = &b;
				cave[i][j].setevent(eptr);
			}
			else {
				eptr = &p;
				cave[i][j].setevent(eptr);
			}
			//cave[i][j].setmarker(x);
			numevent++;
			if (numevent == 2)
				isgood = true;
		}
	}
}

//Function: printgrid
//Description: function to print the grid to the screen
//Parameters: none
//Pre conds: none
//Post conds: grid is printed to the screen
void Game::printgrid() {
	for (int i = 0; i < roomnum; i++) {
		for (int j = 0; j < roomnum; j++) {
			if (p1.i == i && p1.j == j)
				std::cout << 'A';
			else
				std::cout << cave[i][j].printit();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//Function: startplayer
//Description: initializes the player at the beginning of the game
//Parameters: none
//Pre conds: none
//Post conds: player struct will be changed and escape rope event will be placed
void Game::startplayer() {
	if (p1.killwump)
		setwumpus('W');
	p1.arrows = 3;
	p1.hasgold = false;
	p1.win = false;
	p1.killwump = false;
	bool isgood = false;
	while (!isgood) {
		int i = rand() % roomnum;
		int j = rand() % roomnum;
		if (!cave[i][j].haveevent()) {
			p1.i = i;
			p1.j = j;
			Events* eptr = &r;
			cave[i][j].setevent(eptr);
			//cave[i][j].setmarker('E');
			isgood = true;
		}
	}
}

//Function: gameflow
//Description: runs the essential functions for a turn of the game
//Parameters: none
//Pre conds: none
//Post conds: the entire game will run
void Game::gameflow() {
	gamerunning = true;
	while (gamerunning) {
		printgrid();
		percepts();
		playermove();
		checkplayerpos();
	}
	if (p1.win) {
		std::cout << std::endl << "Congratulations, you have beaten the Wumpus' cave!" << std::endl;
	}
	else
		std::cout <<  std::endl << "You have perished in the Wumpus' lair...." << std::endl << "	GAME OVER" << std::endl;
}

//Function: percepts
//Description: calls perception functions for each room around the player
//Parameters: none
//Pre conds: none
//Post conds: perceptions printed to the screen
void Game::percepts() {
	int n = p1.i - 1, e = p1.j + 1, s = p1.i + 1, w = p1.j - 1;
	if (n > 0)
		cave[n][p1.j].percieve();
	if (e < roomnum)
		cave[p1.i][e].percieve();
	if (s < roomnum)
		cave[s][p1.j].percieve();
	if (w > 0)
		cave[p1.i][w].percieve();
}

//Function: checkplayerpos
//Description: checks for and runs events in the players current room
//Parameters: none
//Pre conds: none
//Post conds: events will be run
void Game::checkplayerpos() {

	if (cave[p1.i][p1.j].haveevent())
		cave[p1.i][p1.j].doevent(roomnum, p1, gamerunning);
	if (p1.moved) {
		if (cave[p1.i][p1.j].haveevent())
			cave[p1.i][p1.j].doevent(roomnum, p1, gamerunning);
		p1.moved = false;
	}
}

//Function: playermove
//Description: asks what the player wants to do on there turn
//Parameters: none
//Pre conds: none
//Post conds: player struct changed
void Game::playermove() {
	bool isgood = false;
	int choice;
	while (!isgood) {
		std::cout << "Would you like to move or fire an arrow?" << std::endl << "1. Move" << std::endl << "2. Arrow" << std::endl;
		choice = getusrchoice();
		if (choice > 2)
			std::cout << "Invalid choice, must be between 1 and 2" << std::endl;
		else if (choice == 1) {
			isgood = move();
		}
		else if (choice == 2) {
			if (p1.arrows <= 0) {
				std::cout << "You have no arrows left!!" << std::endl;
				isgood = false;
			}
			else
				isgood = firearrow();
		}
	}
}

//Function: move
//Description: moves the player based on user input
//Parameters: none
//Pre conds: none
//Post conds: player struct is changed
bool Game::move() {
	while (true) {
		std::cout << "Which direction would you like to move?" << std::endl << "1. North" << std::endl << "2. East"
			<< std::endl << "3. South" << std::endl << "4. West" << std::endl << "5. Go Back" << std::endl;
		int choice = getusrchoice();
		if (choice == 1) {
			if (p1.i == 0)
				std::cout << "You are at the northern edge of the cave, pick another direction!" << std::endl;
			else {
				p1.i--;
				std::cout << "Traveled North" << std::endl;
				return true;
			}
		}
		else if (choice == 2) {
			if (p1.j == roomnum - 1)
				std::cout << "You are at eastern edge of the cave, pick another direction!" << std::endl;
			else {
				p1.j++;
				std::cout << "Traveled East" << std::endl;
				return true;
			}
		}
		else if (choice == 3) {
			if (p1.i == roomnum - 1)
				std::cout << "You are at Southern edge of the cave, pick another direction!" << std::endl;
			else {
				p1.i++;
				std::cout << "Traveled South" << std::endl;
				return true;
			}
		}
		else if (choice == 4) {
			if (p1.j == 0)
				std::cout << "You are at Western edge of the cave, pick another direction!" << std::endl;
			else {
				p1.j--;
				std::cout << "Traveled West" << std::endl;
				return true;
			}
		}
		else if (choice == 5)
			return false;
		else {
			std::cout << "Invalid choice" << std::endl;
		}
	}
}

//Function: hitormiss
//Description: determines what do based on whether the wumpus was hit by the arrow or not
//Parameters: bool findwumpus: was the wumpus hit
//Pre conds: none
//Post conds: player struct possibly changed, wumpus position possibly changed
void Game::hitormiss(bool findwumpus) {
	if (findwumpus) {
		cave[wumpi][wumpj].killevent();
		p1.killwump = true;
	}
	else if (p1.killwump) {}
	else if (p1.arrows == 0) {
		std::cout << "You ran out of arrows and have no way to defeat the wumpus..." << std::endl;
		gamerunning = false;
	}
	else {
		if (rand() % 100 + 1 <= 75) {
			std::cout << "A loud roar informs you that Wumpus has woken and moved" << std::endl;
			cave[wumpi][wumpj].killevent();
			bool isgood = false;
			while (!isgood) {
				setwumpus('W');
				if (!(wumpi == p1.i && wumpj == p1.j))
					isgood = true;
			}

		}
	}
}

//Function: firearrow
//Description: fires the arrow in the direction specified by the user
//Parameters: none
//Pre conds: none
//Post conds: arrow will be fired and hits will be determined
bool Game::firearrow() {
	p1.arrows--;
	bool findwumpus = false;
	while (true) {
		std::cout << "Which direction would you like to fire?" << std::endl << "1. North" << std::endl << "2. East"
			<< std::endl << "3. South" << std::endl << "4. West" << std::endl << "5. Go Back" << std::endl;
		int choice = getusrchoice();
		if (choice == 1) {
			for (int i = 1; i < 4; i++) {
				if ((p1.i - i) < 0)
					break;
				else {
					findwumpus = cave[p1.i-i][p1.j].wumpushere();
					if (findwumpus)
						break;
				}
			}
			hitormiss(findwumpus);
			return true;
		}
		else if (choice == 2) {
			for (int i = 1; i < 4; i++) {
				if ((p1.j + i) == roomnum)
					break;
				else {
					findwumpus = cave[p1.i][p1.j+i].wumpushere();
					if (findwumpus)
						break;
				}
			}
			hitormiss(findwumpus);
			return true;
		}
		else if (choice == 3) {
			for (int i = 1; i < 4; i++) {
				if ((p1.i + i) == roomnum)
					break;
				else {
					findwumpus = cave[p1.i + i][p1.j].wumpushere();
					if (findwumpus)
						break;
				}
			}
			hitormiss(findwumpus);
			return true;
		}
		else if (choice == 4) {
			for (int i = 1; i < 4; i++) {
				if ((p1.j - i) < 0)
					break;
				else {
					findwumpus = cave[p1.i][p1.j - i].wumpushere();
					if (findwumpus)
						break;
				}
			}
			hitormiss(findwumpus);
			return true;
		}
		else if (choice == 5) {
			p1.arrows++;
			return false;
		}
		else
			std::cout << "Invalid Choice" << std::endl;
	}
}