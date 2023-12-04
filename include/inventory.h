#ifndef __INVENTORY_H
#define __INVENTORY_H

#include <list>
#include <string>
#include "item.h"
#include "process.h"

class inventory
{
    public:
        inventory();
        void exetuceCommand(commands command_, Item item_);
    private:
        void addItem(Item item_);
        void removeItem(Item item_);
        void updateItem(Item item_);
        void printItemInfo(Item item_);
        void printInventory();
        Item * getItemPointer(std::string itemName_);
        std::list<Item> itemList;
};

#endif