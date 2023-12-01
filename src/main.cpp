#include "inventory.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define MAX_USER_INPUT_LENGTH 100

// This function prints help text for the user
void printHelp()
{
    std::cout << "Inventory system made by Nicklas Holm.\n";
    std::cout << "The following commands are supported:\n";
    std::cout << "\tadd : Adds an item to the inventory.\n";
    std::cout << "\t\t\"add milk\" adds 1 milk to the inventory\n";
    std::cout << "\t\t\"add milk -q 5\" adds 5 milk to the inventory\n";
    std::cout << "\trem : Removes an item from the inventory.\n";
    std::cout << "\t\t\"rem milk\" removes 1 milk from the inventory\n";
    std::cout << "\t\t\"rem milk -q 5\" removes 5 milk from the inventory\n";
    std::cout << "\tupd : Updates the quantity of an existing item in the inventory.\n";
    std::cout << "\t\t\"upd milk -q 10\" updates the quantity of milk to 10\n"; 
    std::cout << "\tlist : Prints info about the inventory.\n";
    std::cout << "\t\t\"list\" prints all items and their quantaties in the inventory.\n";
    std::cout << "\t\t\"list milk\" prints the number of milks in the inventory.\n";
    std::cout << "If an unsupported command is given, then this text is printed.\n";
}

bool processAddAndRemoveCommand(std::vector<std::string> userInputArguments_, item * item_)
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

bool processListCommand(std::vector<std::string> userInputArguments_, item * item_)
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

bool processUpdateCommand(std::vector<std::string> userInputArguments_, item * item_)
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
bool processUserInput(std::string userInput_, commands * command_, item * item_)
{
    // Check if length of string is zero, and return false
    if (userInput_.size() == 0)
        return false;

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
        return false;
    
    *command_ = (commands)validCommandIndex;

    // Process the user input arguments in the function dedicated for 
    // the given command
    bool status = false;
    if ((*command_ == ADD) || (*command_ == REMOVE))
        status = processAddAndRemoveCommand(userInputArguments, item_);
    if (*command_ == LIST)
        status = processListCommand(userInputArguments, item_);
    if (*command_ == UPDATE)
        status = processUpdateCommand(userInputArguments, item_);
    
    return status;
}

int main()
{
    // Decleration of variables
    inventory inventory;
    std::string userInput;
    bool userInputValid;
    commands command;
    item item;

    // Print help text for the user
    printHelp();

    while (1)
    {
        // Get user input
        std::cout << "Please enter input: ";
        std::getline(std::cin, userInput);

        // Proccess user input, then either perform the required command 
        // or print help text
        userInputValid = processUserInput(userInput, &command, &item);
        if (userInputValid == true)
            inventory.processCommand(command, item);
        else
            printHelp();
    }
}