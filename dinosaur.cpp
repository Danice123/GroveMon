#include "dinosaur.h"

Dinosaur::Dinosaur() : GrassM()
{
	name = "Dinosaur";
	attack = 5;
	defense = 5;
	speed = 5;
	health = 5;
	crit = 5;
	mana = 5;
	currentHealth = health;
	currentMana = mana;
}