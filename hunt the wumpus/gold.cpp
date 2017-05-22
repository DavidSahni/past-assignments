#include "gold.hpp"


Gold::Gold() {
	goldtaken = false;
}

void Gold::runevent(int roomnum, player& p1, bool& gamerunning) {
	if (!p1.hasgold) {
		std::cout << std::endl << "As you enter the room, your eyes are immediately drawn to glimmering pile of gold in the center of the floor"
			<< std::endl << "You quickly move over and put the gold in your pack!" << std::endl << std::endl;
		p1.hasgold = true;
		goldtaken = true;
	}
}

void Gold::perception() {
	if (!goldtaken)
		std::cout << "You see a glimmer nearby..." << std::endl;
}

bool Gold::iswumpus() {
	return false;
}