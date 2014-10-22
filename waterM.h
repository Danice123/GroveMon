#ifndef _WATERM_H                 // Prevent multiple definitions if this 
#define _WATERM_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#include "Monster.h"
#include "constants.h"


class WaterM : public Monster
{

public:
	void damageMonster(int, type);



};

#endif