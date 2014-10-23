#include "leer.h"

leer::leer(){
	name = "leer";
	manaCost = 3;
	turns = 5;
	targetsSelf = false;
}
void leer::apply(Monster* target){
	target->setDefense(target->getDefense() - 2);
	target->addStatusEffect(this);
}
std::string leer::describe(Monster* caster){
	return caster->getName() + " used leer. Opponents defense decreased by 2";
}
std::string leer::describeTick(Monster* target){
	return target->getName() + " is still effected by the leer";
}

void leer::tick(Monster* target){
	turns--;
	if (turns == 0) target->setDefense(target->getDefense() + 2);
}