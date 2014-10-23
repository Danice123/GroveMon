#include "waterM.h"


void WaterM::damageMonster(int damage, type damagetype)
{
	switch(damagetype)
	{
	case NORMAL:
		modifyCurrentHealth(-damage);
		break;
	case FIRE:
		modifyCurrentHealth(-damage/2);
		break;
	case WATER:
		modifyCurrentHealth(-damage/2);
		break;
	case GRASS:
		modifyCurrentHealth(-2*damage);
		break;
	}

	if (currentHealth < 0) currentHealth = 0;
}