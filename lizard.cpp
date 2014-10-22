#include "lizard.h"

Lizard::Lizard() : FireM()
{
	name = "Lizard";
	attack = 6;
	defense = 5;
	speed = 5;
	health = 5;
	crit = 5;
	mana = 5;
	currentHealth = health;
	currentMana = mana;
}