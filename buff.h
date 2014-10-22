#ifndef _BUFF_H
#define _BUFF_H
#include "Skill.h"
#include <string>

class Buff : public Skill {
public:
	Buff();
	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
private:

};


#endif