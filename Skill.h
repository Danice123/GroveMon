#ifndef __Skill_
#define __Skill_
#include "Monster.h"
#include <string>

class Skill {
public:
	virtual std::string describe(Monster* caster) = 0;
	virtual void apply(Monster*) = 0;
	virtual std::string describeTick(Monster* target) = 0;
	virtual void tick(Monster*) = 0;
	
	int getManaCost() { return manaCost; }
	std::string getName() { return name; }
	int getTurns() { return turns; }
	bool getTargetsSelf() { return targetsSelf; }
protected:
	int manaCost;
	std::string name;
	int turns;
	bool targetsSelf;
};

#endif