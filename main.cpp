/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Main function seeds the random function, creates a Menu object,
**				and begins the gameplay loop. When the user chooses to quit,
**				the loop bool is set to false and the program exits the loop.
******************************************************************************/
#include <cstdlib>
#include <ctime>
#include "Menu.hpp"

int main()
{
	srand(time(NULL));
	bool loop = true;

	Menu menu;

	do
	{
		menu.chooseFighters();
		menu.fight();
		loop = menu.replay();
	} while (loop);
	
	return 0;
}