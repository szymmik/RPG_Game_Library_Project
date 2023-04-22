#pragma once
#include "GameItem.h"
#include "Seller.h"
#include "PlayerCharacter.h"
class Blacksmith : public Seller {
public:
	Blacksmith(string name) :Seller(name) {};

	void Interaction(PlayerCharacter& player);
	void WhatToUpgrade(PlayerCharacter& player);

	void Upgrade(PlayerCharacter& player, bool type);
private:

};