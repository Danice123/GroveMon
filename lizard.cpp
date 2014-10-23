#include "lizard.h"

Lizard::Lizard() : FireM()
{
	name = "Lizard";
	attack = 10;
	defense = 3;
	speed = 6;
	health = 100;
	crit = 5;
	mana = 20;
	currentHealth = health;
	currentMana = mana;
}