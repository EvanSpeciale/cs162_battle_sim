/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Harry Potter class declaration; inherits from character class.
**				includes special deathCount variable to interact with "hogwarts"
**				ability. Includes default constructor and overridding functions
**				for virtual Character methods
******************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Character.hpp"

class HarryPotter : public Character
{
private:
	int deathCount = 0;
public:
	HarryPotter();
	void rollAttack();		//override
	void rollDefense();		//override
	void hogwarts();		//override
	bool isVampire();		//override
};

#endif	//HARRYPOTTER_HPP