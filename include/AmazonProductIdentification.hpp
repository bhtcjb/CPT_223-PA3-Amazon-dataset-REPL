// Blake Turman
#ifndef AMAZON_PRODUCT_IDENTIFICATION_HPP
#define AMAZON_PRODUCT_IDENTIFICATION_HPP

#include <string>

// Data container class for AmazonLookupTables cetegoryTable
class AmazonProductIdentification {

    public:

    // Constructor
    AmazonProductIdentification(std::string uniqId = "NA", std::string productName = "NA") : 
        uniqId(uniqId), productName(productName) {
        }

    // Destructor
    ~AmazonProductIdentification() {
    }

    // Copy Constructor
    AmazonProductIdentification(const AmazonProductIdentification& other) : 

        uniqId(other.uniqId), productName(other.productName) { 
    }

    // Copy Assignment
    AmazonProductIdentification& operator=(const AmazonProductIdentification& other) {

        if (this != &other) {

            uniqId = other.uniqId; 
            productName = other.productName;            
        }

        return *this;
    }
       
    // Move Constructor
    AmazonProductIdentification(AmazonProductIdentification&& other) noexcept : 
        uniqId(std::move(other.uniqId)), productName(std::move(other.productName)) { 

        other.uniqId = other.productName = "NA";    
    }

    // Move Assignment
    AmazonProductIdentification& operator=(AmazonProductIdentification&& other) noexcept {

        if (this != &other) {

            uniqId = std::move(other.uniqId); 
            productName = std::move(other.productName);
            
            other.uniqId = other.productName = "NA";
        }

        return *this;
    }


    // Setters
    void setUniqId(const std::string& uniqId) {
        this->uniqId = uniqId;
    }

    void setProductName (const std::string& productName) {
        this->productName = productName;
    }

    // Getters
    const std::string& getUniqId() const {
        return uniqId;
    }	

    const std::string& getProductName() const {
        return productName;
    }
    

    private:

    std::string uniqId;	
    std::string productName;

};

#endif