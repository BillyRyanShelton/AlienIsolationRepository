/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is an implementation file for the file Bedroom2.hpp.
*********************************************************************/

#include <iostream>
#include <string>
#include "Bedroom2.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using std::string;
using std::cout;
using std::cin;






void Bedroom2::setBed(bool bedIn)
{
	bed = bedIn;
}

bool Bedroom2::getBed()
{
	return bed;
}




void Bedroom2::setDoorLocks(bool lockDoorsIn)
{
	lockDoors = lockDoorsIn;
}


bool Bedroom2::getDoorLocks()
{
	return lockDoors;
}




float Bedroom2::roomMenu()
{

	cout << "You are now in the " << roomName << ".\n";
	cout << "This room has a light switch, a bed, some heavy duty door locks and is decorated in blood.\n ";

	//creates player input timer
	clock_t InputTimer = 0;
	float C2 = 0;
	char firstChar;
	do
	{
		

		//if player took too long to hide they die.
		if ((InputTimer > 50000))
		{
			C2 = 9;
			return C2;
		}
		InputTimer = clock();



		if (C2 == 1)		//tells the user hiding worked
		{
			cout << "Hiding under the bed worked!\n";
			cout << "The Xenomorph just missed you.  Whew!\n\n";
		}





		if (C2 == 2)		//tells the user they have turned the lights on/off
		{
			if (lightSwitch == 0)
			{
				cout << "The light switch is now on.\n\n";
				lightSwitch = 1;
			}
			else
			{
				cout << "The light switch is now off.\n\n";
				lightSwitch = 0;
			}
		}

		if (C2 == 3)		//tells the user if the door is locked or not
		{
			if (lightSwitch == 0)
			{
				cout << "The door is now deadbolted.\n\n";
				lightSwitch = 1;
			}
			else
			{
				cout << "The door is now unlocked.\n\n";
				lightSwitch = 0;
			}
		}



		if (C2 == 4)		//tells the user they have turned the shower on/off
		{
			if (bed == 0)
			{
				cout << "The bed is now set.\n\n";
				bed = 1;
			}
			else
			{
				cout << "You have now ruined the perfectly nice bed.\n\n";
				bed = 0;
			}
		}

		cout << "What would you like to do now?\n";
		cout << "(1)  Hide Under the bed\n";
		if (lightSwitch == 0)		//if the light switch is off
		{
			cout << "(2)  Turn on the light switch.\n";
		}
		else						//if the light switch is on
		{
			cout << "(2)  Turn off the light switch.\n";
		}


		if (lockDoors == 0)		//if the doors are locks
		{
			cout << "(3)  Deadbolt a door.\n";
		}
		else					//if the doors are unlocked
		{
			cout << "(3)  Unlock the locked door.\n";
		}


		if (bed == 0)
		{
			cout << "(4)  Fix Bed.\n";
		}
		else
		{
			cout << "(4)  Jump on bed.\n";
		}

		cout << "(5)  Open the north door.\n";
		cout << "(6)  Open the south door.\n";
		//cout << "(7)  Open the right door.\n";
		//cout << "(8)  Open the left door.\n";
		//c2 = 9 means player didn't hide in time


		cin >> C2;
		firstChar = cin.peek();
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n\n";
		InputTimer = clock() - InputTimer;
	} while (((C2 != 5) && (C2 != 6)) || (fmod(C2, 1) != 0) || (firstChar != '\n'));

	
	return C2; //return values signifies the player died or they are moving to a different room

}
