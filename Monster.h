#ifndef __Monster_
#define __Monster_
#include "Skill.h"
#include <vector>
#include <string>

enum type{WATER, GRASS, FIRE};

class Monster {
public:
	virtual void damageMonster(int, type) = 0;

	Skill** getSkills() { return skills; }
	Skill** getStatusEffects() { return statusEffects; }

	std::string getName() { return name; }
	type getType() { return creature_type; }

	int getAttack() { return attack; }
	int getDefense() { return defense; }
	int getHealth() { return health; }
	int getSpeed() { return speed; }
	int getCrit() { return crit; }
	int getMana() { return mana; }

	int getCurrentHealth() { return currentHealth; }
	int getCurrentMana() { return currentMana; }

	void setAttack(int i) { attack = i; }
	void setDefense(int i) { defense = i; }
	void setHealth(int i) { health = i; }
	void setSpeed(int i) { speed = i; }
	void setCrit(int i) { crit = i; }
	void setMana(int i) { mana = i; }

	void modifyCurrentMana(int i) { currentMana = i; }
protected:
	std::string name;
	type creature_type;
	int attack, defense, health, speed, crit, mana, currentHealth, currentMana;
	Skill** skills;
	int nSkills;
	Skill** statusEffects;
	int nStatusEffects;
};
#endif