#include "fireball.h"

Fireball::Fireball() {
	name = "Fireball";
	manaCost = 5;
	targetsSelf = false;
	turns = 2;
}

std::string Fireball::describe(Monster* caster) {
	return caster->getName() + " throws a huge fireball!";
}

void Fireball::apply(Monster* target) {
	target->damageMonster(5, type::FIRE);
	target->addStatusEffect(this);
}

std::string Fireball::describeTick(Monster* target) {
	return target->getName() + " is on FIRE!";
}

void Fireball::tick(Monster* target) {
	turns--;
	target->damageMonster(1, type::FIRE);
}