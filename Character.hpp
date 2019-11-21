/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Character class declaration. Includes all character stats as
**				member variables, coin flip and dice roll stats to be called
**				by subclasses, pure virtual functions for attack and defense
**				rolls, the hogwarts ability, and isVampire, which returns true
**				if the character is a vampire. Includes get functions for all
**				necessary stats. doDamage function subtracts damage from char's
**				strength points total.
******************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
using std::string;

class Character
{
protected:
	int attack;
	int defense;
	int armor;
	int strengthPoints;
	string characteristics;
	string specialAbilities;
	bool charmed;
	int deathCount = 0;			//interacts with hogwarts ability
	string charType;

public:
	Character();
	int coinFlip();				//returns 1 or 2
	int d6Roll();				//returns 1-6
	int d10Roll();				//returns 1-10
	int d12Roll();				//returns 1-12
	virtual void rollAttack() = 0;		//pure virtual
	virtual void rollDefense() = 0;		//pure virtual
	virtual void hogwarts() = 0;		//pure virtual
	virtual bool isVampire() = 0;		//pure virtual
	void setCharmed();			//sets the charmed status
	int getStrengthPoints();
	int getAttack();
	int getDefense();
	int getArmor();
	string getCharType();
	void doDamage(int);			//substracts damage from strenght point total
};

#endif //CHARACTER_HPP