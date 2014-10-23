#include "wave.h"

Wave::Wave()
{
	manaCost = 5;
	turns = 2;
	name = "Wave";
}

std::string Wave::describe(Monster* caster) {
	caster->getAttack();
	return "";
}

void Wave::apply(Monster* target) {
	 target->damageMonster(5,WATER); 
	 target->addStatusEffect(this);
}

std::string Wave::describeTick(Monster* target) {
	return "";
}

void Wave::tick(Monster* target) {
	 target->damageMonster(5,WATER);
	turns-= 1;
}