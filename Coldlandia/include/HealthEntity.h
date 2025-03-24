#pragma once
#include "EntityBase.h"
class HealthEntity : public EntityBase
{
public:
	HealthEntity();
	int getHealth();
	void dealDamage(int dmg);

private: 
	int _hp;
};

