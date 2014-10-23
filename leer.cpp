#include "leer.h"

leer::leer(){
	name = "leer";
	manaCost = 3;

}
void leer::apply(Monster* target){
	target->setDefense(target->getDefense() - 2);
}
std::string leer::describe(Monster* caster){
	return caster->getName() + " used leer. Opponents defense decreased by 2";
}
std::string leer::describeTick(Monster* target){
	
}
void leer::tick(Monster* target){

}