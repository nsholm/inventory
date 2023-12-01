#include "inventory.h"
#include <iostream>

inventory::inventory()
{
    this->itemList.clear();
}

void inventory::processCommand(commands command_, item item_)
{
    if (command_ == ADD)
        this->addItem(item_);
    if (command_ == REMOVE)
        this->removeItem(item_);
    if ((command_ == LIST) && (item_.name.size() == 0))
        this->printInventory();
    if ((command_ == LIST) && (item_.name.size() > 0))
        this->printItemInfo(item_);
}

item * inventory::getItemPointer(std::string itemName_)
{
    for (auto it = this->itemList.begin(); it != this->itemList.end(); ++it)
    {
        if (it->name == itemName_)
            return &(*it);
    }

    return NULL;
}

void inventory::addItem(item item_)
{
    item * itemPointer = this->getItemPointer(item_.name);

    if (itemPointer == NULL)
        this->itemList.push_back(item_);
    else
        itemPointer->quantity += item_.quantity;
}

void inventory::removeItem(item item_)
{
    item * itemPointer = this->getItemPointer(item_.name);

    if (itemPointer != NULL)
    {
        itemPointer->quantity -= item_.quantity;
        if (itemPointer->quantity <= 0)
        {
            this->itemList.remove(*itemPointer);
        }
    }
}

void inventory::printItemInfo(item item_)
{
    item * itemPointer = this->getItemPointer(item_.name);

    if (itemPointer == NULL)
        std::cout << "\tThere are no " << item_.name << " in the inventory.\n";
    else
        std::cout << "\tThere are " << itemPointer->quantity << " " << item_.name << " in the inventory.\n";
}

void inventory::printInventory()
{
    if (this->itemList.size() == 0)
        std::cout << "\tThere are no items in the inventory.\n";

    for (auto it = this->itemList.begin(); it != this->itemList.end(); ++it)
    {
        std::cout<< "\tThere are " << it->quantity << " " << it->name << " in the inventory.\n";
    }
}