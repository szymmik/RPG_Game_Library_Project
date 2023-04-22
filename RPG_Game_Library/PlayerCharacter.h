#pragma once
#include "GameCharacter.h"
#include "GameItem.h"
#include "Potion.h"
#include <vector>
#include <iostream>
using namespace std;

class PlayerCharacter : public GameCharacter {
private:
  

public:
    PlayerCharacter(std::string name) : GameCharacter(name) {}

    PlayerCharacter(std::string name, int level, int health, Inventory inv) : GameCharacter(name, inv, level, health)
    {}

    void AddItemToInventory(const GameItem& item) { inventory_.AddItem(item); }
    void AddPotionToInventory(const Potion& potion) { inventory_.AddPotion(potion); }

    void RemoveItemFromInventory(const GameItem& item) { inventory_.RemoveItem(item); }
    void RemovePotionFromInventory(const Potion& potion) { inventory_.RemovePotion(potion); }

   // bool HasItemInInventory(const GameItem& item) const { return inventory_.HasItem(item); }

    void AddWeaponToInventory(Weapon weapon) { inventory_.setWeapon(weapon); }
    void AddArmorToInventory(Armor armor) { inventory_.setArmor(armor); }



    bool Attack(GameCharacter& target);


    void UsePotion(Potion& potion);

    void ShowMyStats();

    void ShowMyInventory();


};