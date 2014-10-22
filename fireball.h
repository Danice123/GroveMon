#ifndef _FIREBALL_H
#define _FIREBALL_H
#include "Skill.h"
#include <string>

class Fireball : public Skill {
public:
	Fireball();
	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
private:

};

#endif