/******************************************************************************
** Name:		Evan Speciale
** Date:		July 30, 2019
** Description: Character class implementation
******************************************************************************/
#include "Menu.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <climits>
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************
 Menu default constructor just prints some into lines
******************************************************************************/
Menu::Menu()
{
	cout << "Welcome to Fantasy Battle Simulator 2k19" << endl
		<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
		
}

/******************************************************************************
 prompts the user to choose two fighters. Verifies user input and then creates
 a new instance of the chosen class and has the fighter1 and fighter2 Character
 pointers point at the new object.
******************************************************************************/
void Menu::chooseFighters()
{
	int choice;
	bool valid;
	
	//prompts user to select first fighter
	do
	{
		cin.clear();
		cout << "Choose two fighters to duel to the death!" << endl
			<< "-----------------------------------------" << endl
			<< "1 - Vampire" << endl
			<< "2 - Barbarian" << endl
			<< "3 - Blue Men" << endl
			<< "4 - Medusa" << endl
			<< "5 - Harry Potter" << endl
			<< endl;
		cout << "Choose first fighter [1-5]: ";
		cin >> choice;
		valid = this->checkIntRange(1, 5, choice);	//checks if input is int between 1 and 5
		cout << endl;
	} while (!valid);

	//creates character subclass instance and points the fighter1 variable at it
	switch (choice)
	{
	case 1:
	{
		fighter1 = new Vampire;
		break;
	}
	case 2:
	{
		fighter1 = new Barbarian;
		break;
	}
	case 3:
	{
		fighter1 = new BlueMen;
		break;
	}
	case 4:
	{
		fighter1 = new Medusa;
		break;
	}
	case 5:
	{
		fighter1 = new HarryPotter;
		break;
	}
	}

	//same for fighter2
	do
	{
		cin.clear();
		cout << "1 - Vampire" << endl
			<< "2 - Barbarian" << endl
			<< "3 - Blue Men" << endl
			<< "4 - Medusa" << endl
			<< "5 - Harry Potter" << endl
			<< endl;
		cout << "Choose second fighter [1-5]: ";
		cin >> choice;
		valid = this->checkIntRange(1, 5, choice);	//checks if input is int between 1 and 5
		cout << endl;
	} while (!valid);

	switch (choice)
	{
	case 1:
	{
		fighter2 = new Vampire;
		break;
	}
	case 2:
	{
		fighter2 = new Barbarian;
		break;
	}
	case 3:
	{
		fighter2 = new BlueMen;
		break;
	}
	case 4:
	{
		fighter2 = new Medusa;
		break;
	}
	case 5:
	{
		fighter2 = new HarryPotter;
		break;
	}
	}
}

/******************************************************************************
 The main fight loop has the first fighter attack, checks if the second fighter
 is still alive, and, if so, the second fighter attacks. If either fighter dies
 during the round, the loop calls to the hogwarts function of the dead character
 and revives them if possible. The loop then increments the round counter and 
 loops again if both fighters are still alive. After one fighter wins, announces
 the winner and deletes the character objects.
******************************************************************************/
void Menu::fight()
{
	int roundCount = 1;
	do
	{
		cout << "====================ROUND "<<roundCount<<"====================" << endl << endl;
		this->fighter1Attack();
		if (fighter2->getStrengthPoints() > 0)
		{
			this->fighter2Attack();
			if (fighter1->getStrengthPoints() <= 0)
			{
				fighter1->hogwarts();
			}
		}
		else
		{
			fighter2->hogwarts();
		}

		roundCount++;
	} while (fighter1->getStrengthPoints() > 0 && fighter2->getStrengthPoints() > 0);

	if (fighter1->getStrengthPoints() <= 0)
	{
		cout << "Fighter 2 Wins!!" << endl << endl;
	}
	else if (fighter2->getStrengthPoints() <= 0)
	{
		cout << "Fighter 1 Wins!!" << endl << endl;
	}

	delete fighter1;
	delete fighter2;
	fighter1 = nullptr;
	fighter2 = nullptr;

}

/******************************************************************************
 Function prints information about attacker and defender. If one or both of the
 fighters are vampires, sets the "charmed" status on the vampire's opponent.
 The function then rolls attack and defense, then calculates the damage to the
 defender. If the damage is 0 or less, prints "NO DAMAGE" instead. Prints the
 defender's remaining strength points.
******************************************************************************/
void Menu::fighter1Attack()
{
	
	//prints attacker and defender stats
	cout << "========================================" << endl
		<< "|| Attacker:\t" << fighter1->getCharType() << endl
		<< "========================================" << endl
		<< "|| Defender:\t" << fighter2->getCharType() << endl
		<< "|| Armor Rating:\t" << fighter2->getArmor() << endl
		<< "|| Strength Points:\t" << fighter2->getStrengthPoints() << endl
		<< "========================================" << endl << endl;
	
	//sets charmed status if opponent is a vampire
	if (fighter2->isVampire())
	{
		if (fighter1->isVampire())
		{
			cout << "The Vampires remembers how gross it is to be a vampire with all the blood" << endl
				<< "and coffins stuff and resist their opponent's charm!" << endl << endl;
		}
		else
		{
			fighter1->setCharmed();
		}
	}
	
	//rolls attack and defense, calculates damage to defender
	fighter1->rollAttack();
	fighter2->rollDefense();
	int damage = fighter1->getAttack() - fighter2->getDefense() - fighter2->getArmor();
	fighter2->doDamage(damage);

	//displays damage calculation
	cout << "========================================" << endl
		<< "|| Attack Roll:\t\t" << fighter1->getAttack() << endl
		<< "|| Defense Roll:\t" << fighter2->getDefense() << endl
		<< "|| Armor Rating:\t" << fighter2->getArmor() << endl
		<< "|| ---------------------------" << endl
		<< "|| Total Damage:\t";
	//prints total damage or NO DAMAGE if damage is 0 or less
	if (damage <= 0)
	{
		cout << "NO DAMAGE!";
	}
	else
	{
		cout << damage;
	}
	cout << endl
		<< "||" << endl
		<< "|| Fighter 2's Strength Points:\t" << fighter2->getStrengthPoints() << endl
		<< "========================================" << endl << endl;
}

/******************************************************************************
 same as fighter1Attack function
******************************************************************************/
void Menu::fighter2Attack()
{
	cout << "========================================" << endl
		<< "|| Attacker:\t" << fighter2->getCharType() << endl
		<< "========================================" << endl
		<< "|| Defender:\t" << fighter1->getCharType() << endl
		<< "|| Armor Rating:\t" << fighter1->getArmor() << endl
		<< "|| Strength Points:\t" << fighter1->getStrengthPoints() << endl
		<< "========================================" << endl << endl;
	if (fighter1->isVampire())
	{
		fighter2->setCharmed();
	}
	fighter2->rollAttack();
	fighter1->rollDefense();
	int damage = fighter2->getAttack() - fighter1->getDefense() - fighter1->getArmor();
	fighter1->doDamage(damage);

	cout << "========================================" << endl
		<< "|| Attack Roll:\t\t" << fighter2->getAttack() << endl
		<< "|| Defense Roll:\t" << fighter1->getDefense() << endl
		<< "|| Armor Rating:\t" << fighter1->getArmor() << endl
		<< "|| ---------------------------" << endl
		<< "|| Total Damage:\t";
	if (damage <= 0)
	{
		cout << "NO DAMAGE!";
	}
	else
	{
		cout << damage;
	}
	cout << endl
		<< "||" << endl
		<< "|| Fighter 1's Strength Points:\t" << fighter1->getStrengthPoints() << endl
		<< "========================================" << endl << endl;
}

/******************************************************************************
 prompts the user to play again or quit. If user chooses to quit, returns false
 and exits the gameplay loop in the main function
******************************************************************************/
bool Menu::replay()
{
	int choice;
	bool valid;
	bool loop = true;
	do
	{
		cin.clear();
		cout << "Play Again?" << endl
			<< "-----------" << endl
			<< "1 - Play Again" << endl
			<< "2 - Quit Program" << endl << endl;
		cout << "Enter Selection: ";
		cin >> choice;
		valid = this->checkIntRange(1, 2, choice);	//checks if input is int between 1 and 5
		cout << endl;
	} while (!valid);

	switch (choice)
	{
	case 1:
	{
		loop = true;
		break;
	}
		
	case 2:
	{
		loop = false;
		break;
	}
	}
	return loop;
}

/******************************************************************************
 input validation function checks if input is within chosen range
******************************************************************************/
bool Menu::checkIntRange(int min, int max, int input)
{
	if (input < min || input > max)
	{
		cout << "Please enter a valid choice [" << min << "-" << max << "]" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return false;
	}
	else
	{
		return true;
	}
}