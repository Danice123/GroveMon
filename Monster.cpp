#include "Monster.h"

void Monster::addSkill(Skill* s) {
	skills.push_back(s);
}

void Monster::addStatusEffect(Skill* s) {
	statusEffects.push_back(s);
}