/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is an implementation file for the file HiddenPod.hpp.
*********************************************************************/

#include <iostream>
#include <string>
#include "HiddenPod.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using std::string;
using std::cout;
using std::cin;





void HiddenPod::setEngine(bool engineIn)
{
	engine = engineIn;
}

bool HiddenPod::getEngine()
{
	return engine;
}






float HiddenPod::roomMenu()
{
	
	cout << "You are now in the " << roomName << ".\n";
	cout << "This pod will allow you to set a course for earth, enter cryosleep and\n";
	cout << "get off this ship of death.\n\n";

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
			cout << "Hiding under the floor worked!\n";
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

		
		cout << "What would you like to do now?\n";
		cout << "(1)  Hide\n";
		if (lightSwitch == 0)		//if the light switch is off
		{
			cout << "(2)  Turn on the light switch.\n";
		}
		else						//if the light switch is on
		{
			cout << "(2)  Turn off the light switch.\n";
		}


		
		

		cout << "(5)  Open the north door.\n";
		cout << "(10) Launch Pod!!!!!\n";
		//cout << "(6)  Open the south door.\n";
		//cout << "(7)  Open the right door.\n";
		//cout << "(8)  Open the left door.\n";
		//c2 = 9 means player didn't hide in time


		cin >> C2;
		firstChar = cin.peek();
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n\n";
		InputTimer = clock() - InputTimer;
	} while (((C2 != 5) && (C2 != 10)) || (fmod(C2, 1) != 0) || (firstChar != '\n'));

	
	return C2; //return values signifies the player died or they are moving to a different room

}
