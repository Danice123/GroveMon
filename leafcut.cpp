#include "leafcut.h"

LeafCut::LeafCut()
{
	manaCost = 5;
	name = "Leaf Cut";
	targetsSelf = false;
}

std::string LeafCut::describe(Monster* caster) {
	return caster->getName() + " shoots leaves at the opponent!";
}

void LeafCut::apply(Monster* target) {
	 target->damageMonster(5,GRASS); 
}

std::string LeafCut::describeTick(Monster* target) {
	return "";
}

void LeafCut::tick(Monster* target) {

}