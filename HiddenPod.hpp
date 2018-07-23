/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description: This is a header file for the file named HiddenPod.cpp.
*********************************************************************/

#ifndef HIDDENPOD_HPP
#define HIDDENPOD_HPP
#include <string>
#include "Room.hpp"
using std::string;

class HiddenPod :public Room
{
private:
	bool engine;
	
public:
	void setEngine(bool engineIn);
	bool getEngine();
	float roomMenu();

};

#endif
