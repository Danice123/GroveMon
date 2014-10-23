#include "turtle.h"

Turtle::Turtle() : WaterM()
{
	name = "Turtle";
	attack = 8;
	defense = 5;
	speed = 5;
	health = 100;
	crit = 5;
	mana = 20;
	currentHealth = health;
	currentMana = mana;
}