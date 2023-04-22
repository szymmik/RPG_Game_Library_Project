#pragma once
#include <string>
#include "GameItem.h"
#include <ctime>

class Weapon : public GameItem {
private:
   // int damage_;
    int minDamage_;
    int maxDamage_;
    int range_;

public:
   // Weapon() :GameItem("Hand", 0, "Your hand, you have no weapon"), damage_(5), range_(1) {}

  /*  Weapon(std::string name, int price, int damage, int range)
        : GameItem(name, price, ""), damage_(damage), range_(range) {}*/

    Weapon() :GameItem("Hand", 0, "Your hand, you have no weapon"), minDamage_(1),maxDamage_(5), range_(1) {}

    Weapon(std::string name, int price, int minDamage,int maxDamage, int range)
        : GameItem(name, price, ""), minDamage_(minDamage),maxDamage_(maxDamage), range_(range) {}

   // int GetDamage() const { return damage_; }

    int GetDamage() const;
    int GetMinDamage()  {return minDamage_;}
    int GetMaxDamage()  {return maxDamage_;}
    std::string GetDamageRange() const  {return "(" + std::to_string(minDamage_) + " - " + std::to_string(maxDamage_) + ")";}
    void UpgradeDamage(double value);
    int GetRange() const { return range_; }

    void Show() const override;


};