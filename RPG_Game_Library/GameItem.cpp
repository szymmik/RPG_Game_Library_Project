#include "GameItem.h"

bool GameItem::operator==(const GameItem& it)
{
    if (this->name_ == it.name_ && this->price_ == it.price_ && this->description_ == it.description_)
        return true;
    else
        return false;
}

void GameItem::Show() const
{
    std::cout << " Name: " << GetName() << ", Price: " << GetPrice() << std::endl;
    std::cout << " Description: " << GetDescription() << std::endl;
}
