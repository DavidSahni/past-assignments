//Program Filename: mazelocation.hpp
//Author: David Sahni
//Date: 3/22/2017
//Description: mazelocation header file
//Input: n/a
//Output: mazelocation class defined
#ifndef mazeloc
#define mazeloc

class mazelocation {

public:
	virtual bool is_occupiable();
	virtual char get_display_character();
	virtual void set_student(bool);
	virtual bool has_student();
	virtual void set_start(bool);
	virtual bool is_start();
	virtual void set_ladder(bool);
	virtual bool is_ladder();
	virtual void set_ta(bool);
	virtual bool has_ta();
	virtual void set_instructor(bool);
	virtual bool has_instructor();
	virtual void set_skills(bool);
	virtual bool has_skills();
};

#endif