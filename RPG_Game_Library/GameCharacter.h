#pragma once
#include <string>
#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"

using namespace std;
class GameCharacter {
protected:
	std::string name_;
	int level_;
	int experience_;
	int maxHealth_;
	int currentHealth_;
	int maxMana_;
	int currentMana_;
	Inventory inventory_;
	int gold_;
	
public:
	GameCharacter(std::string name, Inventory inv, int level = 1, int health = 100, int gold = 0 ) : name_(name), level_(level), experience_(0), maxHealth_(health),currentHealth_(health), maxMana_(50),currentMana_(50), inventory_(inv), gold_(gold) {}
	GameCharacter(std::string name) : name_(name), level_(1), experience_(0), maxHealth_(100),currentHealth_(100),maxMana_(50),currentMana_(50), gold_(0) {}

	std::string GetName() const { return name_; }
	int GetLevel() const { return level_; }
	int GetExperience() const { return experience_; }
	int GetMaxHealth() const { return maxHealth_; }
	int GetCurrentHealth() const { return currentHealth_; }
	int GetMaxMana() const { return maxMana_; }
	int GetCurrentMana() const { return currentMana_; }
	Inventory GetInventory() const { return inventory_; }

	void SetExperience(int experience) { experience_ = experience; }
	void SetMaxHealth(int health) { maxHealth_ = health; }
	void SetCurrentHealth(int health) { currentHealth_ = health; }
	void SetMaxMana(int mana) { maxMana_ = mana; }
	void SetCurrentMana(int mana) { currentMana_ = mana; }

	int GetGold() const { return gold_; }
	void AddGold(int amount) { gold_ += amount; }

	void SpendGold(int amount);

	void LevelUp();

	void AddExperience(int exp);

};