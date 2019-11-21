/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Character class implementation.
******************************************************************************/
#include "Character.hpp"


//does nothing. just makes a character object.
Character::Character()
{

}

//simulates a coin flip and returns the result
int Character::coinFlip()
{
	return (int)(1 + rand() % 2);
}

//simulates a 6-sided die roll and returns the result
int Character::d6Roll()
{
	return (int)(1 + rand() % 6);
}

//simulates a 10-sided die roll and returns the result
int Character::d10Roll()
{
	return (int)(1 + rand() % 10);
}

//simulates a 12-sided die roll and returns the result
int Character::d12Roll()
{
	return (int)(1 + rand() % 12);
}

//sets the charmed status for the character
void Character::setCharmed()
{
	charmed = true;
}

//get functions for all character stats
int Character::getStrengthPoints()
{
	return strengthPoints;
}
int Character::getAttack()
{
	return attack;
}
int Character::getDefense()
{
	return defense;
}
int Character::getArmor()
{
	return armor;
}
string Character::getCharType()
{
	return charType;
}

//if damage is positive, subtracts the damage from the character's strength points. If
//damage is negative, does nothing.
void Character::doDamage(int damage)
{
	if (damage >= 0)
	{
		strengthPoints -= damage;
	}
	
}