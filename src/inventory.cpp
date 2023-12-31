#include "inventory.h"
#include <iostream>

inventory::inventory()
{
    this->itemList.clear();
}

void inventory::exetuceCommand(commands command_, Item item_)
{
    if (command_ == ADD)
        this->addItem(item_);
    if (command_ == REMOVE)
        this->removeItem(item_);
    if (command_ == UPDATE)
        this->updateItem(item_);
    if ((command_ == LIST) && (item_.name.size() == 0))
        this->printInventory();
    if ((command_ == LIST) && (item_.name.size() > 0))
        this->printItemInfo(item_);
}

// This function returns a pointer to the item in the itemList 
// that matches the item name given.
// If no item in the list matches, a NULL pointer is returned
Item * inventory::getItemPointer(std::string itemName_)
{
    for (auto it = this->itemList.begin(); it != this->itemList.end(); ++it)
    {
        if (it->name == itemName_)
            return &(*it);
    }

    return NULL;
}

void inventory::addItem(Item item_)
{
    Item * itemPointer = this->getItemPointer(item_.name);

    // If item exist in list, then add the quantity
    // If item does not exist, then add to the list
    if (itemPointer != NULL)
        itemPointer->quantity += item_.quantity;
    else
        this->itemList.push_back(item_);
    
    std::cout << "\tAdded " << item_.quantity << " " << item_.name << " to the inventory.\n";
}

void inventory::removeItem(Item item_)
{
    Item * itemPointer = this->getItemPointer(item_.name);

    // If item exist then subtract the quantity, if quantity becomes 0 or less,
    // then remove from list.
    // If item does not exist, then inform user
    if (itemPointer != NULL)
    {
        itemPointer->quantity -= item_.quantity;
        if (itemPointer->quantity <= 0)
        {
            this->itemList.remove(*itemPointer);
            std::cout << "\tRemoved all " << item_.name << " from the inventory.\n";
        }
        else
        {
            std::cout << "\tRemoved " << item_.quantity << " " << item_.name << " from the inventory.\n";
        }
    }
    else
    {
        std::cout << "\tThere are no " << item_.name << " in the inventory.\n";
    }
}

void inventory::updateItem(Item item_)
{
    Item * itemPointer = this->getItemPointer(item_.name);

    // If item exist, then update its quantity
    // If item does not exist, then inform user
    if (itemPointer != NULL)
    {
        itemPointer->quantity = item_.quantity;
        std::cout << "\tUpdated quantity of " << item_.name << " to " << item_.quantity << ".\n";
    }
    else
    {
        std::cout << "\t" << item_.name << " was not found in invetory, please run \"add " << item_.name << "\" before updating quantity.\n";
    }
}

void inventory::printItemInfo(Item item_)
{
    Item * itemPointer = this->getItemPointer(item_.name);

    // If item exist, then print quantity and name of item
    // If item does not exist, then inform user
    if (itemPointer != NULL)
        std::cout << "\tThere are " << itemPointer->quantity << " " << item_.name << " in the inventory.\n";
    else
        std::cout << "\tThere are no " << item_.name << " in the inventory.\n";
}

void inventory::printInventory()
{
    if (this->itemList.size() == 0)
        std::cout << "\tThere are no items in the inventory.\n";

    for (auto it = this->itemList.begin(); it != this->itemList.end(); ++it)
        std::cout<< "\tThere are " << it->quantity << " " << it->name << " in the inventory.\n";
}