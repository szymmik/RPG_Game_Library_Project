#include "Inventory.h"

void Inventory::RemoveItem(const GameItem& item)
{
	auto it = std::find(items_.begin(), items_.end(), item);
	if (it != items_.end()) items_.erase(it);
}

void Inventory::RemovePotion(const Potion& potion)
{
	auto it = std::find(potions_.begin(), potions_.end(), potion);
	if (it != potions_.end()) potions_.erase(it);
}

bool Inventory::IfItemExist(std::string name)
{
	for (auto& item : items_)
	{
		if (item.GetName() == name) return true;
	}
	return false;
}

bool Inventory::IfPotionExist(std::string name)
{
	for (auto& item : potions_)
	{
		if (item.GetName() == name) return true;
	}
	return false;
}
