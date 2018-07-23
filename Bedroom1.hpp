/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a header file for the file named Bedroom.cpp.
*********************************************************************/

#ifndef BEDROOM1_HPP
#define BEDROOM1_HPP
#include <string>
#include "Room.hpp"
using std::string;

class Bedroom1 :public Room
{
private:
	bool bed;
	bool lockDoors;

public:
	void setBed(bool bedIn);
	bool getBed();
	void setDoorLocks(bool lockDoorsIn);
	bool getDoorLocks();
	float roomMenu();

};

#endif
