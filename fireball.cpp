#include "fireball.h"

std::string Fireball::describe(Monster* caster) {
	caster->getAttack();
	return "";
}

void Fireball::apply(Monster* target) {
	
}

std::string Fireball::describeTick(Monster* target) {
	return "";
}

void Fireball::tick(Monster* target) {

}