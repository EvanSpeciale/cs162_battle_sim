/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Harry Potter class implementation
******************************************************************************/
#include "Character.hpp"
#include "HarryPotter.hpp"
#include <iostream>
using std::cout;
using std::endl;

//Calls character constructor (which does nothing) and initializes character stats
HarryPotter::HarryPotter() : Character()
{
	attack = Character::d6Roll() + Character::d6Roll();
	defense = Character::d6Roll() + Character::d6Roll();
	armor = 0;
	strengthPoints = 10;
	characteristics = "Harry Potter is a wizard.";
	specialAbilities = "Hogwarts: If Harry Potter's strength reaches 0 or below, he \nimmediately recovers and his total strength becomes 20. If he \nwere to die again, then he’s dead.";
	charType = "Harry Potter";
}

//checks if the character has the "charmed" status. If so, flips a coin to determine
//if the character attacks. Attack is set to the result of the dice roll, simulated by
//calling to the Character "roll" methods.
void HarryPotter::rollAttack()
{
	if (charmed == true)
	{
		int flip = Character::coinFlip();
		if (flip == 1)
		{
			cout << "Harry's wand does a wolf-whistle and some kiss-shaped pink sparks fly out." << endl
				<< "Harry tryna snog this sexy Vampire." << endl << endl;
			attack = 0;
		}
		else if (flip == 2)
		{
			cout << "Harry uses Diffindo, the Severing Charm, to cut off a bit of the Vampire's" << endl
				<< "hair. This lopsided look is ridiculous. Charm resisted!" << endl << endl;
			attack = Character::d6Roll() + Character::d6Roll();
		}
	}
	else
	{
		attack = Character::d6Roll() + Character::d6Roll();
	}
	
}

//calls to the appropriate roll methods of the Character class to set defense
void HarryPotter::rollDefense()
{
	defense = Character::d6Roll() + Character::d6Roll();
}

//Checks how many times Harry has died. If this is the first time, increments his death
//counter and resets his strength points to 20. Otherwise, nothing happens and the game ends
void HarryPotter::hogwarts()
{
	if (deathCount == 0)
	{
		cout << "Harry's special pendant or whatever starts to glow and he rises\nagain with renewed strength!" << endl << endl;
		strengthPoints = 20;
		deathCount++;
	}
	else
	{
		deathCount++;
		cout << "Harry's Plot Armor broke!" << endl << endl;
	}
}

//returns true if the character is a vampire
bool HarryPotter::isVampire()
{
	return false;
}