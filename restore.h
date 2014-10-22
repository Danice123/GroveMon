#include "Skill.h"
#ifndef _RESTORE_H
#define _RESTORE_H
#include <string>

class Restore : public Skill {
public:
	Restore();
	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
private:

};

#endif