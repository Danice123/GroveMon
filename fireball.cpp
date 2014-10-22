#include "fireball.h"

Fireball::Fireball() {
	name = "Fireball";
	manaCost = 5;
}

std::string Fireball::describe(Monster* caster) {
	return caster->getName() + " throws a huge fireball!";
}

void Fireball::apply(Monster* target) {
	target->damageMonster(5, type::FIRE);
}

std::string Fireball::describeTick(Monster* target) {
	return "";
}

void Fireball::tick(Monster* target) {

}