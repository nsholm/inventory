#ifndef __ITEM_H
#define __ITEM_H

#include <string>

class Item
{
    public:
        Item() :
            name(""), quantity(1) {};
        Item(std::string name_) :
            name(name_), quantity(1) {};
        Item(std::string name_, int quantity_) :
            name(name_), quantity(quantity_) {};
        bool operator==(Item itemToCompare_) {
            if (itemToCompare_.name != this->name) return false;
            if (itemToCompare_.quantity != this->quantity) return false;
            return true;
        }
        std::string name;
        int quantity;
};

#endif