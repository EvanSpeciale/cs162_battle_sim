/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Blue Men class declaration; inherits from character class.
**				Includes default constructor and overridding functions
**				for virtual Character methods
******************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"

class BlueMen : public Character
{
public:
	BlueMen();
	void rollAttack();
	void rollDefense();
	bool isVampire();
	void hogwarts();
};

#endif	//BLUEMEN_HPP