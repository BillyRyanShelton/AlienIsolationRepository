/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a header file for the file named Bedroom2.cpp.
*********************************************************************/

#ifndef BEDROOM2_HPP
#define BEDROOM2_HPP
#include <string>
#include "Room.hpp"
using std::string;

class Bedroom2 :public Room
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
