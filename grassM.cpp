#include "grassM.h"


void GrassM::damageMonster(int damage, type damagetype)
{
	switch(damagetype)
	{

	case NORMAL:
		{
			 modifyCurrentHealth(getCurrentHealth() - damage);
		}
	case FIRE:
		{
			 modifyCurrentHealth(getCurrentHealth() - (2*damage));
		}
	case WATER:
		{
			 modifyCurrentHealth(getCurrentHealth() - (damage/2));
		}
	case GRASS:
		{
			 modifyCurrentHealth(getCurrentHealth() - (damage/2));
		}
	default:
		{

		}
	}

}