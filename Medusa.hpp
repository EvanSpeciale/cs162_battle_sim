/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Medusa class declaration; inherits from character class.
**				Includes default constructor and overridding functions
**				for virtual Character methods
******************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Character.hpp"

class Medusa : public Character
{
public:
	Medusa();
	void rollAttack();
	void rollDefense();
	bool isVampire();
	void hogwarts();
};

#endif	//MEDUSA_HPP