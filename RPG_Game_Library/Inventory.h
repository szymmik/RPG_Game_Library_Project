#pragma once
#include <vector>
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"


class Inventory {
private:
    std::vector<GameItem> items_;
    std::vector<Potion> potions_;
    Weapon weapon_;
    Armor armor_;


public:
    Inventory(){}
    Inventory(Weapon weapon, Armor armor) 
    {
        setWeapon(weapon); setArmor(armor);
    }
    Inventory(Weapon weapon, Armor armor, Potion p1, Potion p2)
    {
        setWeapon(weapon); setArmor(armor),AddPotion(p1),AddPotion(p2);
    }
    void AddItem(const GameItem& item) { items_.push_back(item); }
    void AddPotion(const Potion& potion) { potions_.push_back(potion); }

    void RemoveItem(const GameItem& item);
    void RemovePotion(const Potion& potion);

     std::vector<GameItem>& GetItems()  { return items_; }
     std::vector<Potion>& GetPotions() { return potions_; }

    bool IfItemExist(std::string name);
    bool IfPotionExist(std::string name);

    void InvUpgradeDamage(double value) {
        weapon_.UpgradeDamage(value);
    }
    void InvUpgradeDefense(double value) {
        armor_.UpgradeDefense(value);
    }
    void setWeapon(Weapon weapon) { weapon_ = weapon; }
    void setArmor(Armor armor) { armor_ = armor; }

    Weapon getWeapon() { return weapon_; }
    Armor getArmor() { return armor_; }

};