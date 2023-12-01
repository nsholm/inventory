#include <list>
#include <string>

enum commands
{
    ADD     = 0,
    REMOVE  = 1,
    LIST    = 2,
};

enum arguments
{
    ITEM    = 0,
    QUANTITY= 1,
};

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

class inventory
{
    public:
        inventory();
        void processCommand(commands command_, item item_);
    private:
        void addItem(item item_);
        void removeItem(item item_);
        void printItemInfo(item item_);
        void printInventory();
        item * getItemPointer(std::string itemName_);
        std::list<item> itemList;
};