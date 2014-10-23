#include "dinosaur.h"

Dinosaur::Dinosaur() : GrassM()
{
	name = "Dinosaur";
	attack = 9;
	defense = 4;
	speed = 4;
	health = 100;
	crit = 5;
	mana = 20;
	currentHealth = health;
	currentMana = mana;
}