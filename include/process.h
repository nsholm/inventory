#ifndef __PROCESS_H
#define __PROCESS_H

#include <vector>
#include <string>
#include "item.h"
#include "commonDefinitions.h"

class Process
{
    public:
        Process() :
            userInputValid(false), command(ADD), item() {};
        void userInput(std::string userInput_);
        bool valid();
        commands getCommand();
        Item getItem();
    private:
        bool addAndRemoveCommand(std::vector<std::string> userInputArguments_, Item * item_);
        bool listCommand(std::vector<std::string> userInputArguments_, Item * item_);
        bool updateCommand(std::vector<std::string> userInputArguments_, Item * item_);
        bool userInputValid;
        commands command;
        Item item;
};

#endif