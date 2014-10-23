#include "grassM.h"


void GrassM::damageMonster(int damage, type damagetype)
{
	switch(damagetype)
	{
	case NORMAL:
		modifyCurrentHealth(-damage);
		break;
	case FIRE:
		modifyCurrentHealth(-2*damage);
		break;
	case WATER:
		modifyCurrentHealth(-damage/2);
		break;
	case GRASS:
		modifyCurrentHealth(-damage/2);
		break;
	}

	if (currentHealth < 0) currentHealth = 0;
}