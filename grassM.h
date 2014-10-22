#ifndef _GRASSM_H                 // Prevent multiple definitions if this 
#define _GRASSM_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#include "Monster.h"


class GrassM : public Monster
{

public:
	GrassM() { creature_type = type::GRASS; }
	void damageMonster(int,type);



};

#endif