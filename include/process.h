#ifndef __PROCESS_H
#define __PROCESS_H

#include <vector>
#include <string>
#include "item.h"
#include "commonDefinitions.h"

class Process
{
    public:
        bool userInput(std::string userInput_, commands * command_, Item * item_);
    private:
        bool addAndRemoveCommand(std::vector<std::string> userInputArguments_, Item * item_);
        bool listCommand(std::vector<std::string> userInputArguments_, Item * item_);
        bool updateCommand(std::vector<std::string> userInputArguments_, Item * item_);

};

#endif