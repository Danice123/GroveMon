#ifndef _FIREM_H                 // Prevent multiple definitions if this 
#define _FIREM_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#include "Monster.h"


class FireM : public Monster
{

public:
	FireM() { creature_type = type::FIRE; }
	void damageMonster(int,type);



};

#endif