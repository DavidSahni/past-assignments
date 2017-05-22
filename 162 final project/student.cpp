//Program Filename: student.cpp
//Author: David Sahni
//Date: 3/22/2017
//Description: intrepdstudent class implementation file
//Input: n/a
//Output: 
#include "student.hpp"

char intrepidstudent::get_move() {
	std::cout << "What would you like to do?(Move with WASD, use programming skills with P, ascend ladder with U)" << std::endl;
	return getusrchoice();
}


void intrepidstudent::setloc(int x, int y) {
	row = x;
	col = y;
}
int intrepidstudent::getrow() {
	return row;
}
int intrepidstudent::getcol() {
	return col;
}

void intrepidstudent::addproskill() {
	proskills++;
	std::cout << "Picked up a Programming skill!!" << std::endl << "You have " << proskills << " Programming skills!" << std::endl;
}

void intrepidstudent::useproskill() {
	proskills--;
}

int intrepidstudent::getproskill() {
	return proskills;
}

char intrepidstudent::getusrchoice() {
	bool isbad = true;
	char temp;
	while (isbad) {
		std::cout << "Please enter your choice: ";
		std::cin >> temp;
		if (temp >= 'a') {
			temp = temp - 32;
		}
		if (!(temp == 'A' || temp == 'W' || temp == 'S' || temp == 'D' || temp == 'U' || temp == 'P'))
			std::cout << "Invalid choice" << std::endl;
		else
			isbad = false;
	}
	return temp;
}

void intrepidstudent::resetskills() {
	proskills = 0;
}

intrepidstudent::intrepidstudent() {
	proskills = 0;
}