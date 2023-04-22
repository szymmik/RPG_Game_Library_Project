#include "Armor.h"

void Armor::UpgradeDefense(double value)
{
	defense_ = defense_ + defense_ * value;
}

void Armor::Show() const
{
	std::cout << " Name: " << GetName() << ", Price: " << GetPrice() << ", Defense : " << GetDefense() << std::endl;
	std::cout << " Description: " << GetDescription() << std::endl;
}
