#include "fireM.h"


void FireM::damageMonster(int damage, type damagetype)
{
	switch(damagetype)
	{

	case NORMAL:
		{
			 modifyCurrentHealth(getCurrentHealth() - damage);
		}
	case FIRE:
		{
			 modifyCurrentHealth(getCurrentHealth() - (damage/2));
		}
	case WATER:
		{
			 modifyCurrentHealth(getCurrentHealth() - (2*damage));
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