#include "Skill.h"
#include <string>

class TestSkill : public Skill {
public:
	TestSkill();

	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
private:

};