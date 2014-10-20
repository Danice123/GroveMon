#ifndef __Skill_
#define __Skill_
#include "Monster.h"
#include <string>

class Skill {
public:
	Skill();
	
	virtual std::string describe() = 0;
	virtual void apply(Monster) = 0;
	virtual void tick(Monster) = 0;
	virtual int getManaCost() { return manaCost; }
private:
	int manaCost;
};

#endif