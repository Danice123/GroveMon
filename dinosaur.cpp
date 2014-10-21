#include "dinosaur.h"

Dinosaur::Dinosaur() 
{
	setAttack(5);
	setDefense(5);
	setSpeed(5);
	setHealth(5);
	setCrit(5);
	setMana(5);
	modifyCurrentHealth(getHealth());
	modifyCurrentMana(getMana());




}