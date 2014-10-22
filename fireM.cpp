#include "fireM.h"


void FireM::damageMonster(int damage, type damagetype)
{
	switch(damagetype)
	{
	case NORMAL:
		modifyCurrentHealth(damage);
		break;
	case FIRE:
		modifyCurrentHealth(damage/2);
		break;
	case WATER:
		modifyCurrentHealth(2*damage);
		break;
	case GRASS:
			 modifyCurrentHealth(damage/2);
		break;
	}

}