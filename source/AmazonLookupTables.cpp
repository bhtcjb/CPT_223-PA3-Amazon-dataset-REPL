// Blake Turman
#include "AmazonLookupTables.hpp"

// Public

void AmazonLookupTables::populateTables(const std::string& productFile) {

    std::string uniqId = "",
        category = "",
        currentField = "",
        currentCategory = "",
        line = "";

    productFileStream.open(productFile);

    // skip first line
    getline(productFileStream, line);

    // get whole line until end of file
    while (getline(productFileStream, line)) {

        // create data container objects, default "NA" for all values
        AmazonProductInformation productDetails;
        AmazonProductIdentification productIdentification;

        // uniqId is expected to exist and be unique
        uniqId = extractNextField(line);
        productIdentification.setUniqId(uniqId);

        // for each of the 27 remaining fields, extract a cleaned field, and if not empty, set value in corresponding data containers
        currentField = extractNextField(line);
        if (currentField != "") {

            productIdentification.setProductName(currentField);
            productDetails.setProductName(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setBrandName(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setAsin(currentField);
        }
            
        category = extractNextField(line);
        if (category != "") {

            productDetails.setCategory(category);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setUpcEanCode(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setListPrice(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setSellingPrice(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setQuantity(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setModelNumber(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setAboutProduct(currentField);
        }
            
        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setProductSpecification(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setTechnicalDetails(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setShippingWeight(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setProductDimensions(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setImage(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setVariants(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setSku(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setProductUrl(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setStock(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setProductDetails(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setDimensions(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setColor(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setIngredients(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setDirectionToUse(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setIsAmazonSeller(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setSizeQuantityVariant(currentField);
        }

        currentField = extractNextField(line);
        if (currentField != "") {

            productDetails.setProductDescription(currentField);
        }

        // data is now ready to be inserted into idTable
        idTable.insert(uniqId, productDetails);
            
        // process category to be inserted into categoryTable
        if (category != "") {
            
            // create bool to determine stopping point for extractNextCategory() calls
            bool isLastCategory = false;

            // divide category field into individual categories before inserting - same data is inserted multiple times, 1 per each category
            while (!isLastCategory) {
                
                currentCategory = extractNextCategory(category, isLastCategory);

                categoryTable.insert(currentCategory, productIdentification);
            }
        }
        else {

            // if no category data insert as "NA"
            categoryTable.insert("NA", productIdentification);
        }

    }

    productFileStream.close();

}

void AmazonLookupTables::printDetailsFromId(const std::string& id) {

    // find id in table
    HashTable<std::string, AmazonProductInformation>::BucketIterator product = idTable.find(id);

    // if id is found
    if (!product.atEnd()) {

        std::cout << std::endl << "Product Details for ID: " << id << std::endl << std::endl << std::endl;

        // for each of the 27 fields, only print information if not "NA"
        if (product.getData().getProductName() != "NA") {

            std::cout << "Product Name: " << product.getData().getProductName() << std::endl << std::endl;
        }

        if (product.getData().getBrandName() != "NA") {

            std::cout << "Brand Name: " << product.getData().getBrandName() << std::endl << std::endl;
        }

        if (product.getData().getAsin() != "NA") {

            std::cout << "Asin: " << product.getData().getAsin() << std::endl << std::endl;
        }

        if (product.getData().getCategory() != "NA") {

            std::cout << "Category: " << product.getData().getCategory() << std::endl << std::endl;
        }

        if (product.getData().getUpcEanCode() != "NA") {

            std::cout << "Upc Ean Code: " << product.getData().getUpcEanCode() << std::endl << std::endl;
        }

        if (product.getData().getListPrice() != "NA") {

            std::cout << "List Price: " << product.getData().getListPrice() << std::endl << std::endl;
        }

        if (product.getData().getSellingPrice() != "NA") {

            std::cout << "Selling Price: " << product.getData().getSellingPrice() << std::endl << std::endl;
        }

        if (product.getData().getQuantity() != "NA") {

            std::cout << "Quantity: " << product.getData().getQuantity() << std::endl << std::endl;
        }

        if (product.getData().getModelNumber() != "NA") {

            std::cout << "Model Number: " << product.getData().getModelNumber() << std::endl << std::endl;
        }

        if (product.getData().getAboutProduct() != "NA") {

            std::cout << "About Product: " << product.getData().getAboutProduct() << std::endl << std::endl;
        }

        if (product.getData().getProductSpecification() != "NA") {

            std::cout << "Product Specification: " << product.getData().getProductSpecification() << std::endl << std::endl;
        }

        if (product.getData().getTechnicalDetails() != "NA") {

            std::cout << "Technical Details: " << product.getData().getTechnicalDetails() << std::endl << std::endl;
        }

        if (product.getData().getShippingWeight() != "NA") {

            std::cout << "Shipping Weight: " << product.getData().getShippingWeight() << std::endl << std::endl;
        }

        if (product.getData().getProductDimensions() != "NA") {

            std::cout << "Product Dimensions: " << product.getData().getProductDimensions() << std::endl << std::endl;
        }

        if (product.getData().getImage() != "NA") {

            std::cout << "Image: " << product.getData().getImage() << std::endl << std::endl;
        }

        if (product.getData().getVariants() != "NA") {

            std::cout << "Variants: " << product.getData().getVariants() << std::endl << std::endl;
        }

        if (product.getData().getSku() != "NA") {

            std::cout << "Sku: " << product.getData().getSku() << std::endl << std::endl;
        }

        if (product.getData().getProductUrl() != "NA") {

            std::cout << "Product Url: " << product.getData().getProductUrl() << std::endl << std::endl;
        }

        if (product.getData().getStock() != "NA") {

            std::cout << "Stock: " << product.getData().getStock() << std::endl << std::endl;
        }

        if (product.getData().getProductDetails() != "NA") {

            std::cout << "Product Details: " << product.getData().getProductDetails() << std::endl << std::endl;
        }

        if (product.getData().getDimensions() != "NA") {

            std::cout << "Dimensions: " << product.getData().getDimensions() << std::endl << std::endl;
        }

        if (product.getData().getColor() != "NA") {

            std::cout << "Color: " << product.getData().getColor() << std::endl << std::endl;
        }

        if (product.getData().getIngredients() != "NA") {

            std::cout << "Ingredients: " << product.getData().getIngredients() << std::endl << std::endl;
        }

        if (product.getData().getDirectionToUse() != "NA") {

            std::cout << "Direction To Use: " << product.getData().getDirectionToUse() << std::endl << std::endl;
        }

        if (product.getData().getIsAmazonSeller() != "NA") {

            std::cout << "Is Amazon Seller: " << product.getData().getIsAmazonSeller() << std::endl << std::endl;
        }

        if (product.getData().getSizeQuantityVariant() != "NA") {

            std::cout << "Size Quantity Variant: " << product.getData().getSizeQuantityVariant() << std::endl << std::endl;
        }
            
        if (product.getData().getProductDescription() != "NA") {

            std::cout << "Product Description: " << product.getData().getProductDescription() << std::endl << std::endl;
        }

    }
    else {

        std::cout << "Inventory/Product not found" << std::endl;
    }

}

void AmazonLookupTables::printIdFromCategory(const std::string& category) {

    // find id in table
    HashTable<std::string, AmazonProductIdentification>::BucketIterator product = categoryTable.find(category);

    // if id is found
    if (!product.atEnd()) {

        std::cout << std::endl << "All Products Under Category: " << category << std::endl << std::endl;

        // iterate through entire list and print all id's and product names
        for (; !product.atEnd(); ++product) {

            // check for key in case multiple are hashed to the same index
            if (product.getKey() == category) {
                
                std::cout << "ID: " << product.getData().getUniqId() << std::endl;
                std::cout << "Product Name: " << product.getData().getProductName() << std::endl << std::endl;
            }
        }

    }
    else {

        std::cout << "Invalid Category" << std::endl;
    }

}

// Private

std::string AmazonLookupTables::extractNextField(const std::string& line) {

    std::string currentField = "";
    bool inQuotes = false,
        foundDelim = false;

    // set static so same line can be used for sequential calls
    static size_t i = 0;
    for (; i < line.length() && !foundDelim; ++i) {

        // remove problem byte sequence
        if ((unsigned char)line[i] == 0xC2) {

            i += 2;
        }

        // check for quotes
        if (line[i] == '"') {

            if (inQuotes) {

                // if within quotes, check for sequential quotes
                if (line[i + 1] == '"') {

                    // add one of the quotes to the field buffer
                    currentField += line[i++];
                }
                else {

                    // if no sequential quotes, that means end of quoted section
                    foundDelim = true;
                    inQuotes = false;
                    ++i;
                }
            }
            else {

                // if not in already in quotes that means a quoted section was started
                inQuotes = true;
            }


        } 
        else if (line[i] == ',' && !inQuotes) {

            // if not in quotes, the delimiter is simply a comma 
            foundDelim = true;
        }
        else {
        
            // add all non-delimiting characters to the field buffer
            currentField += line[i];
        }
    }

    // if at end of the line
    if (!foundDelim) {

        // reset the character index
        i = 0;
    }

    return currentField;
}

std::string AmazonLookupTables::extractNextCategory(const std::string& category, bool& endFlag) {

    std::string currentCategory;
    bool foundDelim = false;

    // set static so same category list can be used for sequential calls
    static size_t i = 0;
    for (; i < category.length() && !foundDelim; ++i) {

        // check for delimiter
        if (category[i] == ' ' && category[i + 1] == '|') {

            // move index by two for extra space
            i += 2;
            foundDelim = true;
        }
        else {

            // add all non-delimiting characters to the field buffer            
            currentCategory += category[i];
        }
    }

    // if at end of category list
    if (!foundDelim) {

        // reset character index and set flag end of list indicator
        endFlag = true;
        i = 0;
    }

    return currentCategory;
    
}