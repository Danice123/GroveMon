#ifndef _Leer_H
#define _Leer_H


#include "Skill.h"
#include <string>

class leer : public Skill {
public:
	leer();
	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
private:

};
#endif 