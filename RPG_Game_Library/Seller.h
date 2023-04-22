#pragma once
#include "GameCharacter.h"
#include "Potion.h"
#include <iostream>
#include "PlayerCharacter.h"

class Seller : public GameCharacter {


public:
	Seller(std::string name, Inventory inv) : GameCharacter(name, inv) {}
	Seller(std::string name) : GameCharacter(name) {}
	enum class ItemType { ARMOR, WEAPON, POTION};

	void ShowNPCInventory();


	void Interaction(PlayerCharacter& player);

	void SelectingEquipment(PlayerCharacter& player, ItemType type);

	void TradePotion(PlayerCharacter& player, int index);

	void Trade(PlayerCharacter& player, ItemType type);
	//void Attack(GameCharacter& target) override;

};