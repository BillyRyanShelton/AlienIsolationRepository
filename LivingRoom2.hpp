/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a header file for the file named LivingRoom2.cpp
*********************************************************************/

#ifndef LIVINGROOM2_HPP
#define LIVINGROOM2_HPP
#include <string>
#include "Room.hpp"
using std::string;

class LivingRoom2 :public Room
{
private:
	bool matches;
	bool tableFlowers;

public:
	void setMatches(bool matchesIn);
	bool getMatches();
	void setFlowers(bool flowersIn);
	bool getFlowers();
	float roomMenu();

};

#endif
