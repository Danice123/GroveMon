#ifndef __Skill_
#define __Skill_
#include <string>

class Monster;

class Skill {
public:
	virtual std::string describe() = 0;
	virtual void apply(Monster*) = 0;
	virtual void tick(Monster*) = 0;
	virtual int getManaCost() { return manaCost; }
private:
	int manaCost;
};

#endif