#include "Blacksmith.h"

void Blacksmith::Interaction(PlayerCharacter& player)
{
	std::cout << "Hello " << player.GetName() << " my name is " << this->GetName() << ". If you want, I can upgrade your equipment for a small fee." << endl;
	std::cout << "Agree (1)	Refuse (0)" << endl;
	bool dec;
	cin >> dec;
	if (dec)
	{
		WhatToUpgrade(player);
	}
	else { std::cout << "Too bad, see you next time" << endl; }
}

void Blacksmith::WhatToUpgrade(PlayerCharacter& player)
{
	std::cout << "Your inventory: " << endl << endl;
	std::cout << "(1)";
	player.GetInventory().getWeapon().Show();
	std::cout << endl;
	std::cout << "(2)";
	player.GetInventory().getArmor().Show();
	std::cout << endl;

	int whatToUpgrade;


	std::cout << "What do you want to upgrade?" << endl;
	cin >> whatToUpgrade;

	switch (whatToUpgrade)
	{
	case 1:
		std::cout << "Looks like you'd like your weapons to be a little stronger" << endl;
		Upgrade(player, 0);
		break;
	case 2:
		std::cout << "It looks like you'd like your armor to be more durable" << endl;
		Upgrade(player, 1);
		break;
	default:
		break;
	}
}

void Blacksmith::Upgrade(PlayerCharacter& player, bool type)
{
	std::cout << "How much would you like to upgrade your item?" << endl
		<< "(0) about 10% - 50 gold" << endl
		<< "(1) about 20% - 80 gold" << endl
		<< "(2) about 30% - 100 gold" << endl;
	int dec, price;
	double value;
	cin >> dec;
	if (dec == 0)
	{
		value = 0.1;
		price = 50;
	}
	else if (dec == 1)
	{
		value = 0.2;
		price = 80;
	}
	else
	{
		value = 0.3;
		price = 100;
	}

	if (type == 0)
	{
		if (player.GetGold() >= price) {

			string tempName = player.GetInventory().getWeapon().GetName();
			int tempPrice = player.GetInventory().getWeapon().GetPrice();
			int tempMinDamage = player.GetInventory().getWeapon().GetMinDamage();
			int tempMaxDamage = player.GetInventory().getWeapon().GetMaxDamage();
			tempMinDamage = tempMinDamage + tempMinDamage * value;
			tempMaxDamage = tempMaxDamage + tempMaxDamage * value;
			int tempRange = player.GetInventory().getWeapon().GetRange();

			Weapon tempWeapon(tempName, tempPrice, tempMinDamage, tempMaxDamage, tempRange);
			player.AddWeaponToInventory(tempWeapon);
			std::cout << "Wow! Your weapon now has " << player.GetInventory().getWeapon().GetDamageRange() << " damage" << endl;
			player.SpendGold(price);
		}
		else std::cout << "NOT ENOUGH GOLD!" << endl;

	}
	else
	{
		if (player.GetGold() >= price) {
			if (player.GetInventory().getArmor().GetDefense() <= 0.75) {
				string tempName = player.GetInventory().getArmor().GetName();
				int tempPrice = player.GetInventory().getArmor().GetPrice();
				double tempDefense = player.GetInventory().getArmor().GetDefense();
				tempDefense = tempDefense + tempDefense * value;
				Armor tempArmor(tempName, tempPrice, tempDefense);
				player.AddArmorToInventory(tempArmor);
				std::cout << "Wow! Your armor now has " << player.GetInventory().getArmor().GetDefense() << " defense" << endl;
				player.SpendGold(price);
			}
			else std::cout << "YOU ARE TO STRONG!";
		}
		else std::cout << "NOT ENOUGH GOLD!" << endl;
	}

	std::cout << "Would you like to upgrade something again?" << endl << "YES (1)	NO(0)" << endl;
	bool dec2;
	cin >> dec2;
	if (dec2)
	{
		WhatToUpgrade(player);
	}
}
