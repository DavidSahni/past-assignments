#ifndef shinygold
#define shinygold

#include "event.hpp"

class Gold : public Events {
private: 
	bool goldtaken;
public: 
	Gold();
	void runevent(int, player&, bool&);
	void perception();
	bool iswumpus();
};


#endif