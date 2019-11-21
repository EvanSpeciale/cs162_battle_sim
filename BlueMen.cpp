/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Blue Men class implementation
******************************************************************************/
#include "Character.hpp"
#include "BlueMen.hpp"
#include <iostream>
using std::cout;
using std::endl;

//Calls character constructor (which does nothing) and initializes character stats
BlueMen::BlueMen() : Character()
{
	attack = Character::d10Roll() + Character::d10Roll();
	defense = Character::d6Roll() + Character::d6Roll() + Character::d6Roll();
	armor = 3;
	strengthPoints = 12;
	characteristics = "They are small, 6 inch tall, but fast and tough. They are hard \nto hit so they can take some damage. They can also do a LOT of \ndamage when they crawl inside enemies’ armor or clothing.";
	specialAbilities = "Mob: Blue Men are actually a swarm of small individuals. For \nevery 4 points of damage, they lose one defense die. For \nexample, if they have a strength of 8, they would have 2d6 \nfor defense.";
	charType = "Blue Men";
}

//checks if the character has the "charmed" status. If so, flips a coin to determine
//if the character attacks. Attack is set to the result of the dice roll, simulated by
//calling to the Character "roll" methods.
void BlueMen::rollAttack()
{
	if (charmed == true)
	{
		int flip = Character::coinFlip();
		if (flip == 1)
		{
			cout << "The swarm erupts into a massive brawl after arguing about which one gets" << endl
				<< "to try and put the moves on this Very Hot(TM) Vampire." << endl << endl;
			attack = 0;
		}
		else if (flip == 2)
		{
			cout << "The whole swarm puts on thier little mirrored sunglasses and the Vampire's" << endl
				<< "bounces right off. Without the charm, the Vampire is merely normal Vampire-hot," << endl
				<< "which is still pretty hot because of the cool long hair, but nothing special." << endl
				<< "Charm resisted!" << endl << endl;
			attack = Character::d10Roll() + Character::d10Roll();
		}
	}
	else
	{
		attack = Character::d10Roll() + Character::d10Roll();
	}
	
}

//calls to the appropriate roll methods of the Character class to set defense. As Blue Men's
//strength points decrease, the number of dice used to roll defense goes down.
void BlueMen::rollDefense()
{
	if (strengthPoints >= 9)
	{
		defense = Character::d6Roll() + Character::d6Roll() + Character::d6Roll();
	}
	else if (strengthPoints >= 5 && strengthPoints < 9)
	{
		defense = Character::d6Roll() + Character::d6Roll();
	}
	else
	{
		defense = Character::d6Roll();
	}
	
}

//returns true if the character is a vampire
bool BlueMen::isVampire()
{
	return false;
}

void BlueMen::hogwarts()
{
	//nothing happens
}