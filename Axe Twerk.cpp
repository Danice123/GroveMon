#include "AxeTwerk.h"

AxeTwerk::AxeTwerk() {
	name = "Axe Twerk";
	manaCost = 3;
	turns = 5;
	targetsSelf = true;
}
void AxeTwerk::apply(Monster* target){
	target->setAttack(target->getAttack() + 2);
	target->addStatusEffect(this);
}
std::string AxeTwerk::describe(Monster* caster){
	return caster->getName() + " used AxeTwerk. " + caster->getName() + " attack rose by 2";
}
std::string AxeTwerk::describeTick(Monster* target){
	return target->getName() + " is still twerking!";
}

void AxeTwerk::tick(Monster* target){
	turns--;
	if (turns == 0) target->setAttack(target->getAttack() - 2);
}