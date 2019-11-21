/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Vampire class declaration; inherits from character class.
**				Includes default constructor and overridding functions
**				for virtual Character methods
******************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"

class Vampire : public Character
{
public:
	Vampire();
	void rollAttack();
	void rollDefense();
	bool isVampire();
	void hogwarts();
};

#endif	//VAMPIRE_HPP