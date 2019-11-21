/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Character class declaration. Member variables for pointers to
**				character objects. Class methods include default constructor,
**				gameplay loop functions, and an input validation function
******************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

class Menu
{
private:
	Character* fighter1 = nullptr;
	Character* fighter2 = nullptr;
public:
	Menu();
	void chooseFighters();
	void fight();
	void fighter1Attack();
	void fighter2Attack();
	bool replay();

	bool checkIntRange(int, int, int);
};

#endif //MENU_HPP