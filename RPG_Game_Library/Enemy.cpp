#include "Enemy.h"

void Enemy::Attack(GameCharacter& target)
{
	int damageDealt = GetInventory().getWeapon().GetDamage() * target.GetInventory().getArmor().GetDefense();
	target.SetCurrentHealth(target.GetCurrentHealth() - damageDealt);
	if (GetCurrentHealth() > 0) {
		cout << "You received " << damageDealt << " damage." << endl;
		cout << "Your HP after enemy's attack: " << target.GetCurrentHealth() << endl;
	}
	cout << endl;

	if (target.GetCurrentHealth() <= 0)
	{
		cout << "You've died!" << endl;
		cout << "Game over" << endl;
		exit(0);
	}
}
