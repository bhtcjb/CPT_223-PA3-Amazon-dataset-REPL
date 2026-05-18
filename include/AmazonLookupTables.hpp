// Blake Turman
#include "HashTable.hpp"
#include "AmazonProductInformation.hpp"
#include "AmazonProductIdentification.hpp"

#include <fstream>
#include <iostream>

class AmazonLookupTables {

    public:

    // Constructor
    AmazonLookupTables() : idTable(), categoryTable() {
    }

    // Destructor
    ~AmazonLookupTables() {

        if (productFileStream.is_open()) {

            productFileStream.close();
        }
    }

    // Copy Constructor
    AmazonLookupTables(const AmazonLookupTables& other) : idTable(other.idTable), 
        categoryTable(other.categoryTable) {
    }

    // Copy Assignment
    AmazonLookupTables& operator=(const AmazonLookupTables& other) {

        if (this != &other) {

            idTable = other.idTable;
            categoryTable = other.categoryTable;
        }

        return *this;
    }

    // Move Constructor
    AmazonLookupTables(AmazonLookupTables&& other) noexcept : idTable(std::move(other.idTable)), 
        categoryTable(std::move(other.categoryTable)), productFileStream(std::move(other.productFileStream)) {        
        }

    // Move Assignment
    AmazonLookupTables& operator=(AmazonLookupTables&& other) noexcept {

        if (this != &other) {
        
            idTable = std::move(other.idTable);
            categoryTable = std::move(other.categoryTable);
            productFileStream = std::move(other.productFileStream);

        }

        return *this;
    }

    // Opens denoted product file and populates idTable and categoryTable with cleaned data
    // File format: Uniq Id,Product Name,Brand Name,Asin,Category,Upc Ean Code,List Price,Selling Price,Quantity,Model Number,About Product,Product Specification,Technical Details,Shipping Weight,Product Dimensions,Image,Variants,Sku,Product Url,Stock,Product Details,Dimensions,Color,Ingredients,Direction To Use,Is Amazon Seller,Size Quantity Variant,Product Description
    void populateTables(const std::string& productFile);

    // Looks for given id, if found prints all non-NA details, otherwise prints not found
    void printDetailsFromId(const std::string& id);

    // Looks for given category, if found prints all product id's and names within the category, otherwise prints invalid category
    void printIdFromCategory(const std::string& category);

    private:

    HashTable<std::string, AmazonProductInformation> idTable; // table for REPL find operation
    HashTable<std::string, AmazonProductIdentification> categoryTable; // table for REPL listInventory operation
    std::ifstream productFileStream;

    // Returns string of next cleaned field
    // Delimeter is comma, except in quoted fields. removes quotes from quoted fields and one of each sequential quote within quoted fields
    // Post-cond: index designating the current char in line is moved along, or reset if at end of line
    // Pre-cond: the same line should be used each call until reaching the end
    std::string extractNextField(const std::string& line);

    // Returns string of next cleaned category
    // Delimeter is a vertical bar surrounded by two spaces
    // Post-cond: index designating the current char in category list is moved along or reset if at end
    //            endFlag is set to true when comma delimeter is reached
    // Pre-cond: the same category list should be used each call until reaching the end
    std::string extractNextCategory(const std::string& category, bool& endFlag);

};