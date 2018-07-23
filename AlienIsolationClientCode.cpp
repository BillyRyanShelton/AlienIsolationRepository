/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is the client code file for a text based alien 
survival game.  The user must traverse through a series of rooms
until they can find the hidden pod.  In each room the player can change
certain aspects of that particular room and add items to their backpack.

*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Room.hpp"
#include "Bedroom1.hpp"
#include "Bedroom2.hpp"
#include "LivingRoom1.hpp"
#include "LivingRoom2.hpp"
#include "HiddenPod.hpp"
#include "Restroom1.hpp"
#include "Restroom2.hpp"
#include <time.h>
#include <stdlib.h>	
#include <stdio.h>
#include <memory>
#include <iomanip>
#include <cmath>
#include <math.h>
using std::string;
using std::cout;
using std::cin;
using std::vector;

void welcome();







int main()
{
	vector<int> backpack (2,0);  //backpack with 2 slots that are empty
								 //slot 1 is the hairspray can
								 //slot 2 is the matches
	
	
	Room* player1;				 //player 1 is created

	

	//Creating the rooms
	LivingRoom1 MiniLivingRoom;
	LivingRoom2 MainLivingRoom;
	Bedroom1 GuestBedroom;
	Bedroom2 CaptainsBedroom;
	Restroom1 GuestBathroom;
	Restroom2 CaptainsBathroom;
	HiddenPod CaptainsPod;

	//naming and connecting the rooms
	MiniLivingRoom.setRoomName("Mini-Living Room");
	MiniLivingRoom.setDown(MainLivingRoom);
	MiniLivingRoom.setLeft(GuestBedroom);

	GuestBedroom.setRoomName("Guest Bedroom");
	GuestBedroom.setDown(GuestBathroom);
	GuestBedroom.setRight(MiniLivingRoom);


	GuestBathroom.setRoomName("Guest Bathroom");
	GuestBathroom.setUp(GuestBedroom);
	GuestBathroom.setRight(MainLivingRoom);

	MainLivingRoom.setRoomName("Main Living Room");
	MainLivingRoom.setUp(MiniLivingRoom);
	MainLivingRoom.setLeft(GuestBathroom);
	MainLivingRoom.setDown(CaptainsBedroom);

	CaptainsBedroom.setRoomName("Captain's Bedroom");
	CaptainsBedroom.setUp(MainLivingRoom);
	CaptainsBedroom.setDown(CaptainsBathroom);

	CaptainsBathroom.setRoomName("Captain's Restroom");
	CaptainsBathroom.setUp(CaptainsBedroom);
	CaptainsBathroom.setDown(CaptainsPod);

	CaptainsPod.setRoomName("Captain's Secret Pod");
	CaptainsPod.setUp(CaptainsBathroom);



	
	



	
	int alive = 1;

	player1 = &MiniLivingRoom;	//player enters captain's suite 
	

	welcome();

	//radar continuously checks for the alien
	//thread first(NoAlienRadar);
	//first.detach();


	float playerStatus = 0;
	while (alive)
	{

		
		playerStatus = player1->roomMenu();

		//if player picked up matches or hairspray they are put into the backpack

		//case1 when no cans of hairspray are in the backpack yet
		if (((player1->getItem()) == 1) && (backpack.at(0)==0))
		{
			backpack[0] = 1;
			player1->setItem(3);//empties item from room
		}
		//case 2 when there is 1 can of hairspray already in the backpack
		else if (((player1->getItem()) == 1) && (backpack.at(0) == 1))
		{
			backpack[0] = 2;
			player1->setItem(3);//empties item from room
		}
		//case 3 when there is 1 set of matches already in the backpack
		else if (((player1->getItem()) == 2) && (backpack.at(1) == 1))
		{

			backpack[1] = 2;
			player1->setItem(3);//empties item from room
		}
		//case 4 when there are no matches already in the backpack
		else if (((player1->getItem()) == 2) && (backpack.at(1) == 0))
		{
			backpack[1] =1;
			player1->setItem(3);//empties item from room
		}

		//depending on the value returned from the menu the player moves to the next room, dies or survives
		if (playerStatus == 5) { player1 = (player1->getUp()); }
		else if (playerStatus == 6) { player1 = player1->getDown(); }
		else if (playerStatus == 7) { player1 = player1->getRight(); }
		else if (playerStatus == 8) { player1 = player1->getLeft(); }


		//player creates the flamethrower if they at least have 1 match and 1 can of hairspray
		else if ((playerStatus == 9) && (backpack[0] >=1) && (backpack[1] >=1)) 
		{
			cout << "Nice thinking!  You were able to temporarily deflect the Xenomorph\n";
			cout << "by creating a flamethrower with your hairspray can and matches.\n\n";
			backpack[0] = (backpack[0] - 1);		//empties out backpack
			backpack[1] = (backpack[0] - 1);
		}
		

		else if (playerStatus == 9) 
		{
			cout << "It's Game Over Man, Game Over!  The alien got you from above!  \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "Rest In Peace Bill Paxton;";
			alive = 0;

		}
		else if (playerStatus == 10)
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "You've managed to launch the pod and set a course for earth. \n";
			cout << "Estimated time of arrival:  10 years \n";
			cout << "Off to the cryosleep chamber now.  I will wake you up when we arrive.\n";
			cout << "Bishop out!\n\n\n\n\n\n\n";
			alive = 0;

		}
	}



	return 0;
}








//explains game to users
void welcome()
{
	string startGame;
	cout << "*****************************Alien Isolation - Captain's Quarters Mission***************************************\n\n";
	cout << "Hello...is anyone there?\n\n";
	cout << "...(grabs radio)\n\n";
	cout << "My name is Bishop, I am a synthetic android, model 341-B.\n\n";
	cout << "...Who am I?  What happened?\n\n";
	cout << "You got hit on the head pretty hard.\n";
	cout << "You are Amanda Ripley on board the ship Sevastopol in deep space.\n";
	cout << "You were brought here in search of your mother Ellen Ripley.\n";
	cout << "She disappeared 15 years ago.  It is apparent the ship has been overun\n";
	cout << "by a creature of some kind.  It has acid for blood, can climb walls and\n";
	cout << "has a mouth from within.\n\n";
	cout << "Mark, a person whom you were moving through Sevastopol with, told you of a possible\n";
	cout << "way off the ship in the captain's quarters.  Unfortunately he sacrificed \n";
	cout << "himself to save you.  Your mission now is to find out what Mark was talking about.\n";
	cout << "Be careful though, the Alien can be anywhere.\n\n";
	cout << "And remember to make decisions quick or else the Alien will get you.  Goodluck!\n\n";
	cout << "*****************************************************************************************************************\n\n";


	cout << "When you are ready to start your mission press any key and enter.\n";
	cin >> startGame;
}







//Alien Radar  - Only Works on Windows Though
//void NoAlienRadar()
//{
//
//
//	while (true)
//	{
//
//		Beep(500, (1)); Sleep((700));
//	}
//
//	return;
//}
