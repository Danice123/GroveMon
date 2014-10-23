#include "wave.h"

std::string Wave::describe(Monster* caster) {
	caster->getAttack();
	return "";
}

void Wave::apply(Monster* target) {
	target->damageMonster(5,WATER);
}

std::string Wave::describeTick(Monster* target) {
	return "";
}

void Wave::tick(Monster* target) {

}