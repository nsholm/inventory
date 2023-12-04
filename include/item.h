#ifndef __ITEM_H
#define __ITEM_H

#include <string>

class item
{
    public:
        item() :
            name(""), quantity(1) {};
        item(std::string name_) :
            name(name_), quantity(1) {};
        item(std::string name_, int quantity_) :
            name(name_), quantity(quantity_) {};
        bool operator==(item itemToCompare_) {
            if (itemToCompare_.name != this->name) return false;
            if (itemToCompare_.quantity != this->quantity) return false;
            return true;
        }
        std::string name;
        int quantity;
};

#endif