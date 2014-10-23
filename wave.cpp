#include "wave.h"

Wave::Wave()
{
	manaCost = 5;
	turns = 2;
	name = "Wave";
	targetsSelf = false;
}

std::string Wave::describe(Monster* caster) {
	return caster->getName() + " launches a wave of water at its opponent";
}

void Wave::apply(Monster* target) {
	 target->damageMonster(5,WATER); 
	 target->addStatusEffect(this);
}

std::string Wave::describeTick(Monster* target) {
	return target->getName() + " is drowning!";
}

void Wave::tick(Monster* target) {
	 target->damageMonster(5,WATER);
	turns-= 1;
}