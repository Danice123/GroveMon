#ifndef _WATERM_H                 // Prevent multiple definitions if this 
#define _WATERM_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#include "Monster.h"


class WaterM : public Monster
{

public:
	WaterM() { creature_type = type::WATER; }
	void damageMonster(int, type);



};

#endif