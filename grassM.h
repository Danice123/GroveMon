#ifndef _GRASSM_H                 // Prevent multiple definitions if this 
#define _GRASSM_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN


#include "Monster.h"
#include "constants.h"


class GrassM : public Monster
{

public:
	void damageMonster(int,type);



};

#endif