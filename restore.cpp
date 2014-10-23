#include "restore.h"

Restore::Restore() {
	name = "Restore Health";
	manaCost = 3;
	targetsSelf = true;
}

std::string Restore::describe(Monster* caster) {
	return caster->getName() + " heals itself";
}

void Restore::apply(Monster* target) {
	target->modifyCurrentHealth(10);
}

std::string Restore::describeTick(Monster* target) {
	return "";
}

void Restore::tick(Monster* target) {

}