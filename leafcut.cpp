#include "leafcut.h"

LeafCut::LeafCut()
{

}

std::string LeafCut::describe(Monster* caster) {
	caster->getAttack();
	return "";
}

void LeafCut::apply(Monster* target) {
	 target->damageMonster(5,GRASS); 
}

std::string LeafCut::describeTick(Monster* target) {
	return "";
}

void LeafCut::tick(Monster* target) {

}