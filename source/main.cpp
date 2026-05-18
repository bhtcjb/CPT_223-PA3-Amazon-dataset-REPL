// Starter code by Subu Kandaswamy
// Modified for the assignment by Blake Turman
#include "AmazonLookupTables.hpp"

#include <iostream>
#include <string>


void printHelp()
{
    std::cout << "\nSupported list of commands: " << std::endl;
    std::cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory/Product not found'." << std::endl;
    std::cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << std::endl;
    std::cout << " Use :quit to quit the REPL" << std::endl;
}

bool validCommand(std::string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(std::string line, AmazonLookupTables& tables)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        tables.printDetailsFromId(line.substr(line.find(' ') + 1));
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        tables.printIdFromCategory(line.substr(line.find(' ') + 1));
    }
}

void bootStrap(AmazonLookupTables& tables)
{
    std::cout << "\n Welcome to Amazon Inventory Query System" << std::endl;
    std::cout << " enter :quit to exit. or :help to list supported commands." << std::endl;
    std::cout << "\n> ";

    tables.populateTables("data/marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data-1.csv");
}

int main(int argc, char const *argv[])
{

    AmazonLookupTables amazonLookupTables;

    std::string line;
    bootStrap(amazonLookupTables);

    while (getline(std::cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line, amazonLookupTables);
        }
        else
        {
            std::cout << "Command not supported. Enter :help for list of supported commands" << std::endl;
        }
        std::cout << "> ";
    }

    return 0;

}
