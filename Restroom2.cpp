/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is an implementation file for the file Restroom2.hpp.
*********************************************************************/

#include <iostream>
#include <string>
#include "Restroom2.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using std::string;
using std::cout;
using std::cin;








void Restroom2::setAersolCan(bool canIn)
{
	grabAerosolCan = canIn;
}

bool Restroom2::getAersolCan()
{
	return grabAerosolCan;
}




void Restroom2::setShower(bool showerIn)
{
	showerOn = showerIn;
}


bool Restroom2::getShower()
{
	return showerOn;
}




float Restroom2::roomMenu()
{
	
	cout << "You are now in the " << roomName << ".\n";
	cout << "The restroom has a light switch, a shower, a toliet and a sink.\n ";

	if (grabAerosolCan == 0)	//if the can of hairspray hasn't been grabbed yet
	{
		cout << "Also, there is a can of hairspray on the counter. \n\n";
	}




	//creates player input timer
	clock_t InputTimer = 0;

	float C2 = 0;
	char firstChar;
	do
	{

		//if player took too long to hide they die.
		if ((InputTimer > 1000))
		{
			C2 = 9;
			return C2;
		}
		InputTimer = clock();



		if (C2 == 1)		//tells the user hiding worked
		{
			cout << "Hiding under the skink worked!\n";
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




		if (C2 == 3)		//tells the user the hairspray is in backpack
		{
			if (grabAerosolCan == 0)
			{
				cout << "The can of hairspray is now in your bag.\n\n";
				grabAerosolCan = 1;
				item = 1;	//value of 1 signals vector to add can of hairspray
			}
		}





		if (C2 == 4)		//tells the user they have turned the shower on/off
		{
			if (showerOn == 0)
			{
				cout << "The shower is now on.\n\n";
				showerOn = 1;
			}
			else
			{
				cout << "The shower is now off.\n\n";
				showerOn = 0;
			}
		}

		cout << "What would you like to do now?\n";
		cout << "(1)  Hide Under the Sink\n";
		if (lightSwitch == 0)		//if the light switch is off
		{
			cout << "(2)  Turn on the light switch.\n";
		}
		else						//if the light switch is on
		{
			cout << "(2)  Turn off the light switch.\n";
		}

		if (grabAerosolCan == 0)	//if the hairspray can is on the counter
		{
			cout << "(3)  Grab the can of hairspray.\n";
		}

		if (showerOn == 0)
		{
			cout << "(4)  Turn on the shower.\n";
		}
		else
		{
			cout << "(4)  Turn off the shower.\n";
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
		InputTimer = clock() - InputTimer;
		cout << "\n\n";
	} while (((C2 != 5) && (C2 != 6)) || (fmod(C2, 1) != 0) || (firstChar != '\n'));

	return C2; //return values signifies the player died or they are moving to a different room

}
