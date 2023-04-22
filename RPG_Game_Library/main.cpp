#include <iostream>
#include "GameCharacter.h"
#include "PlayerCharacter.h"
#include "Enemy.h"
#include "Potion.h"
#include "Seller.h"
#include "Blacksmith.h"
using namespace std;

int main()
{
	//Characters items
	Weapon weapon("Wooden sword", 5, 10, 15, 2); 
	Armor armor("T-Shirt", 5, 0.1);
	Potion hPotion("Paracepotion", 30, Potion::Type::HEALING, 25);
	Potion mPotion("Ecstotion", 30, Potion::Type::MANA, 25);
	Inventory eq(weapon, armor, hPotion, mPotion);
	PlayerCharacter character("Christian", 1, 100, eq);

	//NPCs items
	Weapon nWeapon("Excalibur", 75, 70, 115, 3);
	Armor nArmor("Diamond chest", 100, 0.25);
	Potion hPotion2("Morfotion", 45, Potion::Type::HEALING, 50);
	Potion mPotion2("Cocaition", 45, Potion::Type::MANA, 50);
	Inventory npcEq(nWeapon, nArmor, hPotion2,mPotion2);
	Seller npc("Mark hunter of cracks", npcEq);

	//Weak enemys items
	Weapon weWeapon("Dagger", 15, 5, 10, 6);
	Armor weArmor("Cloak", 15, 0.12);
	Inventory weEq(weWeapon, weArmor);
	Enemy weEnemy("Rogue", 1, 60, weEq);

	//Strong enemys items
	Weapon seWeapon("Hammer", 300, 60, 85, 3);
	Armor seArmor("Netherite armor", 295, 0.4);
	Inventory seEq(seWeapon, seArmor);
	Enemy seEnemy("Huge Roger", 5, 130, seEq);

	//Blacksmith
	Blacksmith bs("Anvilman");
	bool isFight = false;
	do {
		isFight = false;

		cout << "(1) Drink potion" << endl;
		cout << "(2) Open inventory" << endl;
		cout << "(3) Fight weak enemy" << endl;
		cout << "(4) Fight strong enemy" << endl;
		cout << "(5) Meet NPC" << endl;
		cout << "(6) Meet blacksmith" << endl;
		cout << "(7) Check your statistics" << endl;
		cout << "(8) Add 100 gold" << endl;
		cout << "(Anything else) EXIT" << endl;
		int selected;
		cin >> selected;
			switch(selected)
			{
			case 1:
				cout << "Which potion do you want to use?" << endl;
				cout << "Press (m) for mana potion or (h) for health potion" << endl;
				char dec;
				cin >> dec;
				if (dec == 'm') { character.UsePotion(mPotion); }
				else if (dec == 'h') { character.UsePotion(hPotion); }
				
				
				break;
			case 2:
				character.ShowMyInventory();
				break;
			case 3:
				
				do
				{
					isFight = character.Attack(weEnemy);
					if (!isFight)weEnemy.Attack(character);
				} while (!isFight);
				break;
			case 4:
				
				do
				{
					isFight = character.Attack(seEnemy);
					if (!isFight)seEnemy.Attack(character);
				} while (!isFight);
				break;
			case 5:
				npc.Interaction(character);
				break;
			case 6:
				bs.Interaction(character);
				break;
			case 7:
				character.ShowMyStats();
				break;
			case 8:
				character.AddGold(100);
				break;
			default:
				exit(0);
				break;
			}

	} while (true);

	


}