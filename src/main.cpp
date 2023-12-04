#include "inventory.h"
#include <iostream>
#include <vector>
#include "process.h"

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

int main()
{
    // Decleration of variables and classes
    inventory inventory;
    Process process;
    std::string userInput;

    // Print help text for the user
    printHelp();

    while (1)
    {
        // Get user input
        std::cout << "Please enter input: ";
        std::getline(std::cin, userInput);

        // Proccess user input, then either perform the required command 
        // or print help text
        process.userInput(userInput);
        if (process.valid() == true)
            inventory.exetuceCommand(process.getCommand(), process.getItem());
        else
            printHelp();
    }
}