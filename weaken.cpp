#include "weaken.h"

std::string Weaken::describe(Monster* caster) {
	caster->getAttack();
	return "";
}

void Weaken::apply(Monster* target) {
	
}

std::string Weaken::describeTick(Monster* target) {
	return "";
}

void Weaken::tick(Monster* target) {

}