#include "buff.h";

class AxeTwerk : public Buff{
public:
	AxeTwerk();
	std::string describe(Monster* caster);
	void apply(Monster*);
	std::string describeTick(Monster* target);
	void tick(Monster*);
};