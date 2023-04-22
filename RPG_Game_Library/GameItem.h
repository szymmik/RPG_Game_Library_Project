#pragma once
#include <string>
#include <iostream>

class GameItem {
public:

    GameItem(std::string name, int price, std::string description)
        : name_(name), price_(price), description_(description) {}

    std::string GetName() const { return name_; }

    int GetPrice() const { return price_; }
    std::string GetDescription() const { return description_; }

    bool operator ==(const GameItem& it);
   
    virtual void Show() const;
   
private:
    std::string name_;
    int price_;
    std::string description_;
};

