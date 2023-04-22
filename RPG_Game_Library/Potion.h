#pragma once
#include <string>
#include "GameItem.h"

class Potion : public GameItem {
public:
	enum class Type { HEALING, MANA };

	Potion():GameItem("nazwa",5,"") {}
	Potion(std::string name, int price, Type type, int value)
		: GameItem(name, price, ""), type_(type), value_(value) {}

	Type GetType() const { return type_; }
	int GetValue() const { return value_; }
	

	void Show() const override;

private:
	Type type_;
	int value_;
};


