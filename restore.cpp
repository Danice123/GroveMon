#include "restore.h"

std::string Restore::describe(Monster* caster) {
	caster->getAttack();
	return "";
}

void Restore::apply(Monster* target) {
	
}

std::string Restore::describeTick(Monster* target) {
	return "";
}

void Restore::tick(Monster* target) {

}