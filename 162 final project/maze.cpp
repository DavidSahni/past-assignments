//Program Filename: maze.cpp
//Author: David Sahni
//Date: 3/22/2017
//Description: maze class implementation file
//Input: n/a
//Output: 
#include "maze.hpp"


Maze::Maze(std::ifstream& infile, int numlevs, int height, int width) : numlevels(numlevs), row(height), column(width) {
	levels = new Mazelevel*[numlevels];
	for (int i = 0; i < numlevels; i++) {
		levels[i] = new Mazelevel(infile, row, column);
	}
	lev = 0;
	win = false;
}

void Maze::setmaze(int c) {
	tas[0].appease(false);
	setstudent(c);
	settas(c);
	setskills(c);
}

void Maze::gameflow() {
	std::cout << "Welcome to the CS162 Maze, your final challenge in this course!" << std::endl << std::endl;
	while (!win) {
		setmaze(lev);
		levelflow();
		lev++;
	}
	std::cout << "YOU DID IT!" << std::endl << "You have succesfully passed CS162!! Congratulations and good luck in the future!" << std::endl << "Thanks for playing!" << std::endl;
}


void Maze::levelflow() {
	bool finlevel = false;
	std::cout << "Welcome to Level " << lev + 1 << std::endl;
	levels[lev]->displaymaze();
	while (!finlevel) {
		finlevel = playermove();
		tamove();
		system("clear");
		levels[lev]->displaymaze();
		checkpos();
		if (lev+1 == numlevels)
			finlevel = checkins();
	}
}

bool Maze::checkins() {
	bool isinstructor = insnear(s1.getrow(), s1.getcol());
	if (isinstructor) {
		if (s1.getproskill() >= 3) {
			win = true;
			return true;
		}
		else {
			std::cout << "You have made it to the instructor, but you lack the programming skills to pass the class!!" << std::endl << "YOU MUST NOW RETAKE THE CLASS!" << std::endl;
			lev = 0;
			for (int i = 0; i < numlevels; i++)
				resetlevel(i);
			levels[lev]->displaymaze();
			return false;
		}
	}
	return false;
}

bool Maze::insnear(int i, int j) {
	if (levels[lev]->get_location(i + 1, j)->has_instructor() && levels[lev]->get_location(i + 1, j)->is_occupiable()) {
		return true;
	}

	else if (levels[lev]->get_location(i - 1, j)->has_instructor() && levels[lev]->get_location(i - 1, j)->is_occupiable()) {
		return true;
	}

	else if (levels[lev]->get_location(i, j + 1)->has_instructor() && levels[lev]->get_location(i, j + 1)->is_occupiable()) {
		return true;
	}

	else if (levels[lev]->get_location(i, j - 1)->has_instructor() && levels[lev]->get_location(i, j - 1)->is_occupiable()) {
		return true;
	}
	else if (levels[lev]->get_location(i, j)->has_instructor()) {
		return true;
	}

	else
		return false;
}

void Maze::checkpos() {
	int i = s1.getrow();
	int j = s1.getcol();
	if (!tas[0].isappeased()) {
		bool tanear = tacheck(i, j);
		if (tanear) {
			std::cout << "A TA caught you! Back to the beginning of the level!!" << std::endl;
			resetlevel(lev);
			levels[lev]->displaymaze();
		}
	}
	if (levels[lev]->get_location(s1.getrow(), s1.getcol())->has_skills()) {
		s1.addproskill();
		levels[lev]->get_location(s1.getrow(), s1.getcol())->set_skills(false);
	}
}

void Maze::resetlevel(int c) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			levels[c]->get_location(i, j)->set_student(false);
			levels[c]->get_location(i, j)->set_skills(false);
			levels[c]->get_location(i, j)->set_ta(false);
		}
	s1.resetskills();
	setmaze(c);
}

bool Maze::tacheck(int i, int j) {
	if (levels[lev]->get_location(i + 1, j)->has_ta() && levels[lev]->get_location(i + 1, j)->is_occupiable()) {
		return true;
	}

	else if (levels[lev]->get_location(i - 1, j)->has_ta() && levels[lev]->get_location(i - 1, j)->is_occupiable()) {
		return true;
	}

	else if (levels[lev]->get_location(i, j + 1)->has_ta() && levels[lev]->get_location(i, j + 1)->is_occupiable()) {
		return true;
	}

	else if (levels[lev]->get_location(i, j - 1)->has_ta() && levels[lev]->get_location(i, j - 1)->is_occupiable()) {
		return true;
	}
	else if (levels[lev]->get_location(i, j)->has_ta()) {
		return true;
	}

	else
		return false;
}

bool Maze::playermove() {
	bool isgood = false;
	while (!isgood) {
		int i = s1.getrow();
		int j = s1.getcol();
		char temp = s1.get_move();
		if (temp == 'W')
			i--;
		else if (temp == 'D')
			j++;
		else if (temp == 'S')
			i++;
		else if (temp == 'A')
			j--;
		if (temp == 'U') {
			if (levels[lev]->get_location(i, j)->is_ladder()) {
				return true;
			}
		}
		else if (temp == 'P') {
			if (s1.getproskill() > 0) {
				std::cout << "Used a Programming skill to appease the TA's!" << std::endl;
				s1.useproskill();
				tas[0].appease(true);
				isgood = true;
			}
		}
		else if (levels[lev]->get_location(i, j)->is_occupiable()) {
			levels[lev]->get_location(s1.getrow(), s1.getcol())->set_student(false);
			s1.setloc(i, j);
			levels[lev]->get_location(i, j)->set_student(true);
			isgood = true;
		}
	}
}

void Maze::tamove() {
	bool isgood = false;
	int c = 0;
	while (!isgood) {
		int i = tas[c].getrow();
		int j = tas[c].getcol();
		char temp = tas[c].get_move();
		if (temp == 'W')
			i--;
		else if (temp == 'D')
			j++;
		else if (temp == 'S')
			i++;
		else if (temp == 'A')
			j--;
		if (levels[lev]->get_location(i, j)->is_occupiable()) {
			levels[lev]->get_location(tas[c].getrow(), tas[c].getcol())->set_ta(false);
			tas[c].setloc(i, j);
			levels[lev]->get_location(i, j)->set_ta(true);
			c++; //lol
			if (c > 1)
				isgood = true;
		}
	}
}


void Maze::setstudent(int c) {
	bool isgood = false;
	while (!isgood) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++)
			if (levels[c]->get_location(i, j)->is_occupiable())
				if (levels[c]->get_location(i, j)->is_start()) {
					levels[c]->get_location(i, j)->set_student(true);
					s1.setloc(i, j);
					isgood = true;
				}
		}
	}
}

void Maze::settas(int c) {
	bool isgood = false;
	int counter=0;
	while (!isgood) {
		int i = rand() % row, j = rand() % column;
		if (levels[c]->get_location(i, j)->is_occupiable() && !(levels[c]->get_location(i,j)->is_ladder()) && !(levels[c]->get_location(i,j)->has_student())) {
			levels[c]->get_location(i, j)->set_ta(true);
			tas[counter].setloc(i, j);
			counter++;
			if (counter == 2)
				isgood = true;
		}
	}
}

void Maze::setskills(int c) {
	bool isgood = false;
	int counter = 0;
	while (!isgood) {
		int i = rand() % row, j = rand() % column;
		if (levels[c]->get_location(i, j)->is_occupiable() && !(levels[c]->get_location(i, j)->is_ladder()) && !(levels[c]->get_location(i, j)->has_student())) {
			if (!levels[c]->get_location(i, j)->has_ta() && !levels[c]->get_location(i,j)->has_instructor()) {
				levels[c]->get_location(i, j)->set_skills(true);
				counter++;
				if (counter == 3)
					isgood = true;
			}
		}
	}
}

Maze::~Maze() {
	for (int i = 0; i < numlevels; i++) {
		delete levels[i];
	}
	delete[] levels;
}