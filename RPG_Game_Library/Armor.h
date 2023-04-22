#pragma once
#include <string>
#include "GameItem.h"
#include <iostream>

class Armor : public GameItem {
private:

	double defense_;

public:
	Armor() : GameItem("None", 0, "You have no armor"), defense_(0) {}

	Armor(std::string name, int price, double defense)
		: GameItem(name, price, ""), defense_(defense) {}

	double GetDefense() const { return defense_; 
	}
	void UpgradeDefense(double value);
	void Show() const override;
};

