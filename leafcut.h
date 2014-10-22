#ifndef _LeafCut_H
#define _LeafCut_H


#include "Skill.h"
#include <string>

class LeafCut : public Skill {
public:
	LeafCut();
	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
private:

};
#endif 
