#include "Seller.h"

void Seller::ShowNPCInventory()
{
	cout << endl;

	cout << "(1) ";
	inventory_.getWeapon().Show();
	cout << endl;
	cout << "(2) ";
	inventory_.getArmor().Show();
	cout << endl;
	int i = 2;
	for (auto& item : inventory_.GetPotions())
	{
		i++;
		cout << "(" << i << ") ";
		item.Show(); cout << endl;

	}
	cout << endl; cout << endl;
}

void Seller::Interaction(PlayerCharacter& player)
{
	std::cout << "Hi " << player.GetName() << " my name is " << this->GetName() << ". " << endl << "Would you like to buy somethig?" << endl;
	int dec;
	ShowNPCInventory();
	cout << "Choose what you want to buy (if you dont want to buy anything press 0)." << endl;
	cin >> dec;
	switch (dec) {
	case 0:
		break;
	case 1:
		SelectingEquipment(player, Seller::ItemType::WEAPON);
		break;
	case 2:
		SelectingEquipment(player, Seller::ItemType::ARMOR);
		break;
	case 3:
		TradePotion(player, 0);
		break;
	case 4:
		TradePotion(player, 1);
		break;
	default:
		break;
	}
}

void Seller::SelectingEquipment(PlayerCharacter& player, ItemType type)
{
	string itemName, description;
	int itemPrice;
	switch (type)
	{
	case Seller::ItemType::ARMOR:
		itemName = this->GetInventory().getArmor().GetName();
		itemPrice = this->GetInventory().getArmor().GetPrice();
		description = "Defense: " + std::to_string(this->GetInventory().getArmor().GetDefense());
		break;
	case Seller::ItemType::WEAPON:
		itemName = this->GetInventory().getWeapon().GetName();
		itemPrice = this->GetInventory().getWeapon().GetPrice();
		description = "Damage: " + std::to_string(this->GetInventory().getWeapon().GetDamage());
		break;


	default:
		break;
	}
	bool decision;

	std::cout << "Are you sure that you are interested in buying an item called " << itemName << " (" << description << ") " << " at a bargain price of " << itemPrice << " gold ? " << endl;
	std::cout << "YES (1)	NO (0)" << endl;
	std::cin >> decision;
	if (decision) Trade(player, type);
}

void Seller::TradePotion(PlayerCharacter& player, int index)
{
	bool decision;
	string itemName = inventory_.GetPotions().at(index).GetName();
	string description = "value: " + std::to_string(inventory_.GetPotions().at(index).GetValue());
	int itemPrice = inventory_.GetPotions().at(index).GetPrice();
	std::cout << "Are you sure that you are interested in buying a potion called " << itemName << " (" << description << ") " << " at a bargain price of " << itemPrice << " gold ? " << endl;
	std::cout << "YES (1)	NO (0)" << endl;
	std::cin >> decision;
	if (decision) {
		if (player.GetGold() >= this->GetInventory().GetPotions().at(index).GetPrice()) {
			player.AddPotionToInventory(this->GetInventory().GetPotions().at(index));
			player.SpendGold(this->GetInventory().GetPotions().at(index).GetPrice());
			cout << "You bought a potion named " << this->GetInventory().GetPotions().at(index).GetName() << " for " << this->GetInventory().GetPotions().at(index).GetPrice() << " gold" << endl;
		}
		else std::cout << "NOT ENOUGH GOLD!" << endl;
	}
}

void Seller::Trade(PlayerCharacter& player, ItemType type)
{

	switch (type)
	{
	case Seller::ItemType::ARMOR:
		if (player.GetGold() >= this->GetInventory().getArmor().GetPrice()) {

			player.AddArmorToInventory(this->GetInventory().getArmor());
			player.SpendGold(this->GetInventory().getArmor().GetPrice());
			cout << "You bought an item named " << this->GetInventory().getArmor().GetName() << " for " << this->GetInventory().getArmor().GetPrice() << " gold" << endl;
		}
		else std::cout << "NOT ENOUGH GOLD!" << endl;
		break;
	case Seller::ItemType::WEAPON:
		if (player.GetGold() >= this->GetInventory().getWeapon().GetPrice()) {
			player.AddWeaponToInventory(this->GetInventory().getWeapon());
			player.SpendGold(this->GetInventory().getWeapon().GetPrice());
			cout << "You bought an item named " << this->GetInventory().getWeapon().GetName() << " for " << this->GetInventory().getWeapon().GetPrice() << " gold" << endl;
		}
		else std::cout << "NOT ENOUGH GOLD!" << endl;
		break;
	default:
		break;
	}
}
