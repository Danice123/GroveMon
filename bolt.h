#include "Skill.h"
#include <string>

class Bolt : public Skill {
public:
	Bolt();
	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
private:

};