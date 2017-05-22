//Program Filename: Mazelevel.cpp
//Author: David Sahni
//Date: 3/22/2017
//Description: mazelevel implementation file
//Input: n/a
//Output: 
#include "mazelevel.hpp"


Mazelevel::Mazelevel(std::ifstream& infile, int x, int y) : row(x), column(y)  {
	this->locations = new mazelocation**[row];
	char temp;
	for (int i = 0; i < row; i++) {
		this->locations[i] = new mazelocation*[column];
		infile.get(temp);
		for (int j = 0; j < column; j++){
			infile.get(temp);
			if (temp == '#')
				this->locations[i][j] = new wall();
			else {
				this->locations[i][j] = new openspace();	
				if (temp == '@')
					this->locations[i][j]->set_start(true);
				else if (temp == '^')
					this->locations[i][j]->set_ladder(true);
				else if (temp == '%')
					this->locations[i][j]->set_instructor(true);
			}
		}
	}
}

Mazelevel::~Mazelevel() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			delete locations[i][j];
		}
		delete[] locations[i];
	}
	delete locations;
}


mazelocation* Mazelevel::get_location(int i, int j) {
	return this->locations[i][j];
}

void Mazelevel::displaymaze() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << this->locations[i][j]->get_display_character();
		}
		std::cout << std::endl;
	}
}

void Mazelevel::operator=(const Mazelevel& other) {

	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			delete this->locations[i][j];
		}
		delete[] this->locations[i];
	}
	delete this->locations;

	this->row = other.row;
	this->column = other.column;


	this->locations = new mazelocation**[row];
	for (int i = 0; i < row; i++) {
		this->locations[i] = new mazelocation*[column];
		for (int j = 0; j < column; j++)
			this->locations[i][j] = other.locations[i][j];
	}
}

Mazelevel::Mazelevel(){
	row = 0;
	column = 0;
}