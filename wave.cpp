#include "wave.h"

std::string Wave::describe(Monster* caster) {
	caster->getAttack();
	return "";
}

void Wave::apply(Monster* target) {
	
}

std::string Wave::describeTick(Monster* target) {
	return "";
}

void Wave::tick(Monster* target) {

}