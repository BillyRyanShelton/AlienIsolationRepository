/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a header file for the abstract class Room.
*********************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP
#include <string>
using std::string;

class Room
{
protected:
	//Doors
	Room* right;
	Room* left;
	Room* up;
	Room* down;

	//Room things
	bool lightSwitch;
	bool hide;
	string roomName;
	int	item;		//if item = 0 after menu, nothing goes in the player's backpack
					//if item = 1 afer menu, hairspray goes into the player's backpack
					//if item = 2 afer menu, match goes into the player's backpack


public:
	Room();

	void setHide(bool);			//don't think we need set or get hide
								//virtual  getHide();		//the return value of hide will depend on the room
								//							//since rooms have different hiding spots


								//roomMenu is the primary UI for each room.
	virtual float roomMenu();	//tell user about room.  If light is on or off.  items in room
								//and if they want to hide.

								//This get and set function creates a light switch
	void setLightSwitch(bool);	//sets and returns if the lights are on or off in a room
	bool getLightSwitch();

	//This get and set function is for naming the room
	void setRoomName(string);	//sets message for room
	string getRoomName();


	void setItem(int);
	int getItem();


	//The following get and set functions refer to the doors of each room
	void setLeft(Room &);		//set and get where left door points
	Room* getLeft();

	void setRight(Room &);		//set and get where right door points
	Room* getRight();

	void setUp(Room &);			//set and get where up door points
	Room* getUp();

	void setDown(Room &);			//set and get where down door points
	Room* getDown();
};

#endif
