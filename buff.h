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