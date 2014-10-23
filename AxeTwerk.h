#include "Skill.h"

class AxeTwerk : public Skill {
public:
	AxeTwerk();
	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
};