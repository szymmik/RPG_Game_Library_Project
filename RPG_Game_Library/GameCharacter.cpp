#include "GameCharacter.h"

void GameCharacter::SpendGold(int amount)
{
	if (gold_ >= amount)
		gold_ -= amount;
	else { cout << "Not enough gold!" << endl; }
}

void GameCharacter::LevelUp()
{
	level_++;
	SetMaxHealth(maxHealth_ * 1.2);
	SetMaxMana(maxMana_ * 1.1);
	cout << "Congratulations! You've leveled up!" << endl;
	SetCurrentHealth(maxHealth_);
	SetCurrentMana(maxMana_);
}

void GameCharacter::AddExperience(int exp)
{
	experience_ += exp;
	if (experience_ >= 150)
	{
		LevelUp();
		experience_ = 0;
	}
}
