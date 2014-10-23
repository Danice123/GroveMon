#include "AxeTwerk.h"

AxeTwerk::AxeTwerk(){
	name = "Axe Twerk";
	manaCost = 3;

}
void AxeTwerk::apply(Monster* target){
	target->setAttack(target->getAttack() + 2);
}
std::string AxeTwerk::describe(Monster* caster){
	return caster->getName() + " used AxeTwerk. " + caster->getName() + " attack rose by 2";
}
std::string AxeTwerk::describeTick(Monster* target){
	
}
void AxeTwerk::tick(Monster* target){

}