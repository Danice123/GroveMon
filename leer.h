#ifndef _LeafCut_H
#define _LeafCut_H


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