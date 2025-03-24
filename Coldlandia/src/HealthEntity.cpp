#include "HealthEntity.h"

HealthEntity::HealthEntity() : EntityBase()
{
}

int HealthEntity::getHealth()
{
	return _hp;
}

void HealthEntity::dealDamage(int dmg)
{
	_hp -= dmg;
	if (_hp < 0)
	{
		_hp = 0;
	}
}
