/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is an implementation file for the file LivingRoom2.hpp.
*********************************************************************/

#include <iostream>
#include <string>
#include "LivingRoom2.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using std::string;
using std::cout;
using std::cin;









void LivingRoom2::setMatches(bool matchesIn)
{
	matches = matchesIn;
}

bool LivingRoom2::getMatches()
{
	return matches;
}




void LivingRoom2::setFlowers(bool flowersIn)
{
	tableFlowers = flowersIn;
}


bool LivingRoom2::getFlowers()
{
	return tableFlowers;
}




float LivingRoom2::roomMenu()
{

	cout << "You are now in the " << roomName << ".\n";
	cout << "The living room has a light switch, a table with some flowers, some paintings and a tv.\n ";

	if (matches == 0)	//if the matches haven't been grabbed yet
	{
		cout << "There is also a pack of matches on the floor. \n\n";
	}



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
			cout << "Hiding behind the couch worked!\n";
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




		if (C2 == 3)		//tells the user the matches are in the backpack
		{
			if (matches == 0)
			{
				cout << "The pack of matches are now in your bag.\n\n";
				matches = 1;
				item = 2;	//value of 2 signals vector to pack of matches
			}
		}





		if (C2 == 4)		//tells the user they moved the flowers
		{
			if (tableFlowers == 0)
			{
				cout << "The table flowers are now on the tv.\n\n";
				tableFlowers = 1;
			}
			else
			{
				cout << "The table flowers are now on the table.\n\n";
				tableFlowers = 0;
			}
		}

		cout << "What would you like to do now?\n";
		cout << "(1)  Hide behind the couch\n";
		if (lightSwitch == 0)		//if the light switch is off
		{
			cout << "(2)  Turn on the light switch.\n";
		}
		else						//if the light switch is on
		{
			cout << "(2)  Turn off the light switch.\n";
		}

		if (matches == 0)	//if the matches are on the floor
		{
			cout << "(3)  Pick up matches off the floor.\n";
		}

		if (tableFlowers == 0)
		{
			cout << "(4)  Put the flowers on the tv.\n";
		}
		else
		{
			cout << "(4)  Put the flowers on the table.\n";
		}

		cout << "(5)  Open the north door.\n";
		cout << "(6)  Open the south door.\n";
		//cout << "(7)  Open the right door.\n";
		cout << "(8)  Open the left door.\n";
		//c2 = 9 means player didn't hide in time


		cin >> C2;
		firstChar = cin.peek();
		cin.clear();
		cin.ignore(100, '\n');
		InputTimer = clock() - InputTimer;
		cout << "\n\n";
	} while (((C2 != 5) && (C2 != 6) && (C2 != 8)) || (fmod(C2, 1) != 0) || (firstChar != '\n'));

	
	return C2; //return values signifies the player died or they are moving to a different room

}
