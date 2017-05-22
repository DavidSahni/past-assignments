//Program Filename: card.hpp
//Author: David Sahni
//Date: 2/6/2017
//Description: card class header file
//Input: n/a
//Output:n/a
#ifndef card_
#define card_

using namespace std;

class card {
private:
	int rank;
	int suit;
public:
	card();
	~card();
	void setcard(int r, int s);
	int getsuit();
	int getrank();
};

#endif