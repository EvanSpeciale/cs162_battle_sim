/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Medusa class implementation
******************************************************************************/
#include "Character.hpp"
#include "Medusa.hpp"
#include <iostream>
using std::cout;
using std::endl;

//Calls character constructor (which does nothing) and initializes character stats

Medusa::Medusa() : Character()
{
	attack = Character::d6Roll() + Character::d6Roll();
	defense = Character::d6Roll();
	armor = 3;
	strengthPoints = 8;
	characteristics = "Scrawny lady with snakes for hair which helps her during combat.\nJust don’t look at her!";
	specialAbilities = "Glare: If a Medusa rolls a 12 when attacking then the target \ninstantly gets turned into stone and Medusa wins! If Medusa \nuses Glare on Harry Potter on his first life, then Harry Potter \ncomes back to life.";
	charType = "Medusa";
}

//checks if the character has the "charmed" status. If so, flips a coin to determine
//if the character attacks. Attack is set to the result of the dice roll, simulated by
//calling to the Character "roll" methods. If Medusa rolls a 12, attack is set to 255
//for an insta-kill
void Medusa::rollAttack()
{
	int attackRoll = 0;
	
	if (charmed == true)
	{
		int flip = Character::coinFlip();
		if (flip == 1)
		{
			cout << "All of Medusa's hair snakes go awooga and their eyes turn into big cartoon" << endl
				<< "hearts. The snake wig jumps off Medusa's head and tries to get a piece of that" << endl
				<< "totally shredded Vampire. Medusa loses a turn trying to get her snakes back." << endl << endl;
			attackRoll = 0;
		}
		else if (flip == 2)
		{
			cout << "Medusa's hair snakes get distracted by a mouse wearing a t-bone steak costume" << endl
				<< "and forget about the Vampire altogether. Charm resisted!" << endl << endl;
			attackRoll = Character::d6Roll() + Character::d6Roll();
		}
	}
	else
	{
		attackRoll = Character::d6Roll() + Character::d6Roll();
	}

	if (attackRoll == 12)
	{
		cout << "Medusa's hair snakes do a little fusion dance and blast out a big ol' petrify" << endl
			<< "ray. Critical Hit!!" << endl;
		attackRoll = 255;
	}
	
	attack = attackRoll;
}

//calls to the appropriate roll methods of the Character class to set defense
void Medusa::rollDefense()
{
	defense = Character::d6Roll();
}

//returns true if the character is a vampire
bool Medusa::isVampire()
{
	return false;
}

void Medusa::hogwarts()
{
	//nothing happens
}