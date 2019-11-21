/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Barbarian class declaration; inherits from character class.
**				Includes default constructor and overridding functions
**				for virtual Character methods
******************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Character.hpp"

class Barbarian : public Character
{
public:
	Barbarian();
	void rollAttack();
	void rollDefense();
	bool isVampire();
	void hogwarts();
};

#endif	//BARBARIAN_HPP