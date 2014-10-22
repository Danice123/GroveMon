#include "TestMonster.h"

test::test() {
	name = "TEST MONSTER";
	creature_type = type::WATER;
	attack = 5;
	defense = 2;
	health = 10;
	speed = 2;
	crit = 0;
	mana = 5;
	currentHealth = health;
	currentMana = mana;
}

void test::damageMonster(int damage, type damage_type) {
	currentHealth -= damage;
	if (currentHealth < 0) currentHealth = 0;
}