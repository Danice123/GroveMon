#include "Skill.h"
#include <string>

class Weaken : public Skill {
public:
	Weaken();
	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
private:

};