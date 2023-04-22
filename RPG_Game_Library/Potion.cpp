#include "Potion.h"

void Potion::Show() const
{
	std::string type = "";
	if (GetType() == Potion::Type::HEALING)
	{
		type = "Healing potion";
	}
	if (GetType() == Potion::Type::MANA)
	{
		type = "Mana potion";
	}
	std::cout << " Name: " << GetName() << ", Type: " << type << ", Price: " << GetPrice() << ", Value: " << GetValue() << std::endl;
	std::cout << " Description: " << GetDescription() << std::endl;
}
