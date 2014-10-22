#include "waterM.h"


void WaterM::damageMonster(int damage, type damagetype)
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
			 modifyCurrentHealth(getCurrentHealth() - (damage/2));
		}
	case GRASS:
		{
			 modifyCurrentHealth(getCurrentHealth() - (2*damage));
		}
	default:
		{

		}
	}

}