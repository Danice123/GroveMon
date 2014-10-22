#include "TestSkill.h"

TestSkill::TestSkill() {
	name = "Test Skill";
	manaCost = 5;
}

std::string TestSkill::describe(Monster* caster) {
	return caster->getName() + " dances around for a bit";
}

void TestSkill::apply(Monster*) {

}

std::string TestSkill::describeTick(Monster* target) {
	return "";
}

void TestSkill::tick(Monster*) {

}