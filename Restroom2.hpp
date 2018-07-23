/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a header file for the file named Restroom2.cpp
*********************************************************************/

#ifndef RESTROOM2_HPP
#define RESTROOM2_HPP
#include <string>
#include "Room.hpp"
using std::string;

class Restroom2 :public Room
{
private:
	bool grabAerosolCan;
	bool showerOn;

public:
	void setAersolCan(bool canIn);
	bool getAersolCan();
	void setShower(bool showerIn);
	bool getShower();
	float roomMenu();

};

#endif
