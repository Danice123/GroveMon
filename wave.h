#include "Skill.h"
#include <string>

class Wave : public Skill {
public:
	Wave();
	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
private:

};