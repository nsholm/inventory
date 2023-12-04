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
        void exetuceCommand(commands command_, item item_);
    private:
        void addItem(item item_);
        void removeItem(item item_);
        void updateItem(item item_);
        void printItemInfo(item item_);
        void printInventory();
        item * getItemPointer(std::string itemName_);
        std::list<item> itemList;
};

#endif