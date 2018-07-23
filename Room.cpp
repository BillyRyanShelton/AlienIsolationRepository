/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is an implementation file for the file Room.hpp.
*********************************************************************/

#include <iostream>
#include <string>
#include "Room.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using std::string;
using std::cout;
using std::cin;


Room::Room()
{
	up = NULL;
	down = NULL;
	right = NULL;
	left = NULL;
}


void Room::setHide(bool hideIn)
{
	hide = hideIn;
}

//int Room::getHide()
//{
//	return hide;
//}

float Room::roomMenu()
{
	float blankFloat = -1;
	//nothing for abstract class
	return blankFloat;
}



void Room::setItem(int itemIn)
{
	item = itemIn;
}

int Room::getItem()
{
	return item;
}




void Room::setLightSwitch(bool lightSwitchIn)
{
	lightSwitch = lightSwitchIn;
}

bool Room::getLightSwitch()
{
	return lightSwitch;
}







void Room::setRoomName(string roomNameIn)
{
	roomName = roomNameIn;
}

string Room::getRoomName()
{
	return roomName;
}







void Room::setLeft(Room &roomIn)
{
	left = &roomIn;
}
Room* Room::getLeft()
{
	return left;
}






void Room::setRight(Room &roomIn)
{
	right = &roomIn;
}
Room* Room::getRight()
{
	return right;
}



void Room::setUp(Room &roomIn)
{
	up = &roomIn;
}
Room* Room::getUp()
{
	return up;
}




void Room::setDown(Room &roomIn)
{
	down = &roomIn;
}
Room* Room::getDown()
{
	return down;
}
