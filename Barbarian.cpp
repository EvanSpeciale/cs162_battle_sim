/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Barbarian class implementation
******************************************************************************/
#include "Character.hpp"
#include "Barbarian.hpp"
#include <iostream>
using std::cout;
using std::endl;

//Calls character constructor (which does nothing) and initializes character stats
Barbarian::Barbarian() : Character()
{
	attack = Character::d6Roll() + Character::d6Roll();
	defense = Character::d6Roll() + Character::d6Roll();
	armor = 0;
	strengthPoints = 12;
	characteristics = "Think Conan or Hercules from the movies. Big sword, big muscles, \nbare torso.";
	specialAbilities = "";
	charmed = false;
	charType = "Barbarian";
}

//checks if the character has the "charmed" status. If so, flips a coin to determine
//if the character attacks. Attack is set to the result of the dice roll, simulated by
//calling to the Character "roll" methods.
void Barbarian::rollAttack()
{
	if (charmed == true)
	{
		int flip = Character::coinFlip();
		if (flip == 1)
		{
			cout << "The Barbarian's eyes bulge out of their head, their jaw drops to the" << endl
				<< "floor, and their tongue unspools like so much BubbleTape. This Vampire" << endl
				<< "is simply too hot to be murdered." << endl << endl;
			attack = 0;
		}
		else if (flip == 2)
		{
			cout << "The Barbarian imagines the Vampire clipping their toenails or something" << endl
				<< "and manages to resist the Vampire's charm!" << endl << endl;
			attack = Character::d6Roll() + Character::d6Roll();
		}
	}
	else
	{
		attack = Character::d6Roll() + Character::d6Roll();
	}
}

//calls to the appropriate roll methods of the Character class to set defense
void Barbarian::rollDefense()
{
	defense = Character::d6Roll() + Character::d6Roll();
}

//returns true if the character is a vampire
bool Barbarian::isVampire()
{
	return false;
}

void Barbarian::hogwarts()
{
	//nothing happens
}