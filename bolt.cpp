#include "bolt.h"

Bolt::Bolt()
{

}

std::string Bolt::describe(Monster* caster) {
	caster->getAttack();
	return "";
}

void Bolt::apply(Monster* target) {
	 target->damageMonster(5,ELECTRIC); 
}

std::string Bolt::describeTick(Monster* target) {
	return "";
}

void Bolt::tick(Monster* target) {

}