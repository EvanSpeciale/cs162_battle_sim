/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Vampire class implementation
******************************************************************************/
#include "Character.hpp"
#include "Vampire.hpp"
#include <iostream>
using std::cout;
using std::endl;

//Calls character constructor (which does nothing) and initializes character stats
Vampire::Vampire() : Character()
{
	attack = Character::d12Roll();
	defense = Character::d6Roll();
	armor = 1;
	strengthPoints = 18;
	characteristics = "Suave, debonair, but vicious and surprisingly resilient.";
	specialAbilities = "Charm: Vampires can charm a opponent into not attacking. For \na given attack there is a 50% chance that their opponent \ndoes not actually attack them. Doesn't work on other Vampires!";
	charType = "Vampire";
}

//because vampires are immune to charm, just calls to the appropriate dice roll methods
//from the character class to set attack.
void Vampire::rollAttack()
{	
	attack = Character::d12Roll();	
}

//calls to the appropriate roll methods of the Character class to set defense
void Vampire::rollDefense()
{
	defense = Character::d6Roll();
}

//returns true if the character is a vampire
bool Vampire::isVampire()
{
	return true;
}

void Vampire::hogwarts()
{
	//nothing happens
}