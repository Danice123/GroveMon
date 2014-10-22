#include "buff.h"

std::string Buff::describe(Monster* caster) {
	caster->getAttack();
	return "";
}

void Buff::apply(Monster* target) {
	
}

std::string Buff::describeTick(Monster* target) {
	return "";
}

void Buff::tick(Monster* target) {

}