#include "process.h"
#include <bits/stdc++.h>

bool Process::addAndRemoveCommand(std::vector<std::string> userInputArguments_, Item * item_)
{
    // If number of user input arguments is not either 2 or 4, then return false
    if (!((userInputArguments_.size() == 2) || (userInputArguments_.size() == 4)))
        return false;
    
    // If number of user input arguments are 2, then the second argument must be the item name,
    // and the quantity is set to 1
    if (userInputArguments_.size() == 2)
    {
        item_->name = userInputArguments_[1];
        item_->quantity = 1;
        return true;
    }

    // If this point is reached, then there are 4 arguments, and the third argument must
    // be equal to "-q" to be valid, and the fourth argument must be an integer
    if (userInputArguments_[2] != "-q")
        return false;
    
    // We then try to convert the fourth argument to an integer
    char * p;
    int converted = strtol(userInputArguments_[3].c_str(), &p, 10); 
    if (*p)
        return false;
    
    item_->name = userInputArguments_[1];
    item_->quantity = stoi(userInputArguments_[3]);
    
    return true;
}

bool Process::listCommand(std::vector<std::string> userInputArguments_, Item * item_)
{
    // If number of user input arguments is not either 1 or 2, then return false
    if ((userInputArguments_.size() < 1) || userInputArguments_.size() > 2)
        return false;
    
    // If length is equal to 1, then return empty string
    if (userInputArguments_.size() == 1)
    {
        item_->name = "";
        return true;
    }

    // If length is equal to 2, then return item name
    if (userInputArguments_.size() == 2)
    {
        item_->name = userInputArguments_[1];
        return true;
    }

    // This point should not be reached, but just in case return false
    return false;
}

bool Process::updateCommand(std::vector<std::string> userInputArguments_, Item * item_)
{
    // If number of user input arguments is not 4, then return
    if (userInputArguments_.size() != 4)
        return false;

    // If third argument is not equal to "-q", then return
    if (userInputArguments_[2] != "-q")
        return false;
    
    // If fourth argument is not an integer, then return
    char * p;
    int converted = strtol(userInputArguments_[3].c_str(), &p, 10); 
    if (*p)
        return false;

    // All arguments are valid, return item_ with status=true
    item_->name = userInputArguments_[1];
    item_->quantity = stoi(userInputArguments_[3]);
    return true;
}

// This function takes the user input as an input, extracts the 
// command and arguments and returns a boolean indicating if it is 
// a valid command
void Process::userInput(std::string userInput_)
{
    // Check if length of string is zero, and return false
    if (userInput_.size() == 0)
    {
        this->userInputValid = false;
        return;
    }

    // Split string by creating a stringstream, and then loop through
    // the string as long as there is still a space left.
    // The userInput_ string is then stored in a vector of strings.
    std::stringstream stringStream(userInput_);
    std::vector<std::string> userInputArguments;
    std::string temporaryString;
    while (std::getline(stringStream, temporaryString, ' ')) {
 
        // store token string in the vector
        userInputArguments.push_back(temporaryString);
    }

    // Check if command (first argument) is valid, by checking if it exist
    // in the validCommands string vector
    std::vector<std::string> validCommands = {"add", "rem", "list", "upd"};
    int validCommandIndex = -1;
    for (int i = 0; i < validCommands.size(); i++)
    {
        if (validCommands[i] == userInputArguments[0])
            validCommandIndex = i;
    }
    if (validCommandIndex == -1)    // Return false, if command is not valid
    {
        this->userInputValid = false;
        return;
    }
    
    this->command = (commands)validCommandIndex;

    // Process the user input arguments in the function dedicated for 
    // the given command
    this->userInputValid = false;
    if ((this->command == ADD) || (this->command == REMOVE))
        this->userInputValid = this->addAndRemoveCommand(userInputArguments, &(this->item));
    if (this->command == LIST)
        this->userInputValid = this->listCommand(userInputArguments, &(this->item));
    if (this->command == UPDATE)
        this->userInputValid = this->updateCommand(userInputArguments, &(this->item));
}

bool Process::valid()
{
    return this->userInputValid;
}

commands Process::getCommand()
{
    return this->command;
}

Item Process::getItem()
{
    return this->item;
}
