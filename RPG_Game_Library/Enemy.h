#pragma once
#include <string>
#include "GameCharacter.h"
#include "PlayerCharacter.h"

class Enemy : public GameCharacter {
protected:

public:
	Enemy(std::string name, int level, int health, Inventory inv) : GameCharacter(name,  inv, level, health)
	{
		gold_ = level * 100;
	}
	
	int GetGold() const { return gold_; }

	void Attack(GameCharacter& target);
};

