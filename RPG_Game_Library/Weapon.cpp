#include "Weapon.h"

int Weapon::GetDamage() const
{
	int damage = rand() % (maxDamage_ - minDamage_ + 1) + minDamage_;
	return  damage;
}

void Weapon::UpgradeDamage(double value)
{
	double temp = maxDamage_ * value;
	double temp2 = minDamage_ * value;
	maxDamage_ = maxDamage_ + temp;
	minDamage_ = minDamage_ + temp2;
}

void Weapon::Show() const
{
	std::cout << " Name: " << GetName() << ", Price: " << GetPrice() << ", Damage : " << GetDamageRange() << ", Range: " << GetRange() << std::endl;
	std::cout << " Description: " << GetDescription() << std::endl;
}
