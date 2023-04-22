#include "PlayerCharacter.h"

bool PlayerCharacter::Attack(GameCharacter& target)
{
    double defense = target.GetInventory().getArmor().GetDefense();
    int damageDealt = GetInventory().getWeapon().GetDamage() * defense;
    target.SetCurrentHealth(target.GetCurrentHealth() - damageDealt);
    cout << "You have dealt " << damageDealt << " damage to your opponent." << endl;
    cout << "Enemy's HP after your attack: " << target.GetCurrentHealth() << endl;
    cout << endl;
    if (target.GetCurrentHealth() <= 0)
    {
        AddGold(target.GetGold());
        cout << "Enemy defeated!" << endl;
        cout << "You've earned " << target.GetGold() << " gold and " << 50 << " experience." << endl;
        AddExperience(50);
        return 1;
    }
    return 0;
}

void PlayerCharacter::UsePotion(Potion& potion)
{
    if (GetInventory().IfPotionExist(potion.GetName()))
    {
        if (potion.GetType() == Potion::Type::HEALING)
        {
            if (currentHealth_ == maxHealth_) cout << "You are already fully healed." << endl;
            else
            {
                int surplus = currentHealth_ + potion.GetValue() - maxHealth_;
                currentHealth_ += potion.GetValue();
                int healthRestored = potion.GetValue();
                if (surplus > 0)
                {
                    healthRestored -= surplus;
                }
                if (currentHealth_ > maxHealth_) currentHealth_ = maxHealth_;

                cout << "You restored " << healthRestored << " health points." << endl;
                RemovePotionFromInventory(potion);
            }

        }
        if (potion.GetType() == Potion::Type::MANA)
        {
            if (currentMana_ == maxMana_) cout << "You have full mana." << endl;
            else
            {
                int surplus = currentMana_ + potion.GetValue() - maxMana_;
                currentMana_ += potion.GetValue();
                int manaRestored = potion.GetValue();
                if (surplus > 0)
                {
                    manaRestored -= surplus;
                }
                if (currentMana_ > maxMana_) currentMana_ = maxMana_;

                cout << "You restored " << manaRestored << " mana points." << endl;
                RemovePotionFromInventory(potion);
            }
        }

    }
    else
    {
        cout << "You do not have such a potion!" << endl;
    }
}

void PlayerCharacter::ShowMyStats()
{
    cout << endl;
    cout << "Your statistics:" << endl << endl;
    cout << "Name: " << GetName() << ", Level: " << GetLevel() << ", Experience: " << GetExperience() << endl;
    cout << "Health: " << GetCurrentHealth() << "/" << GetMaxHealth() << ", Mana: " << GetCurrentMana() << "/" << GetMaxMana() << ", Gold: " << GetGold() << endl;
    cout << endl; cout << endl;
}

void PlayerCharacter::ShowMyInventory()
{
    cout << endl;
    cout << "Your inventory: " << endl << endl;
    inventory_.getWeapon().Show();
    cout << endl;
    inventory_.getArmor().Show();
    cout << endl;
    for (auto& item : inventory_.GetPotions())
    {
        item.Show(); cout << endl;
    }
    cout << endl; cout << endl;
}
