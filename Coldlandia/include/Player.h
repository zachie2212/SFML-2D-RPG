#pragma once
#include "HealthEntity.h"
#include <vector>
#include "ItemBase.h"
class Player : public HealthEntity
{
public:
	Player();
	bool attack();

private:
	bool _is_in_wild;
	std::vector<ItemBase> _inventory;
	int _n_money;
	int _xp;
	// ability tree?
};

