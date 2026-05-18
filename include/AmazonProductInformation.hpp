// Blake Turman
#ifndef AMAZON_PRODUCT_INFORMATION_HPP
#define AMAZON_PRODUCT_INFORMATION_HPP

#include <string>

// Data container class for AmazonLookupTables idTable
class AmazonProductInformation {

    public:

    // Constructor
    AmazonProductInformation(std::string productName = "NA", std::string brandName = "NA",
        std::string asin = "NA", std::string category = "NA", std::string upcEanCode = "NA",
        std::string listPrice = "NA", std::string sellingPrice = "NA", std::string quantity = "NA",
        std::string modelNumber = "NA", std::string aboutProduct = "NA", std::string productSpecification = "NA",
        std::string technicalDetails = "NA", std::string shippingWeight = "NA", std::string productDimensions = "NA",
        std::string image = "NA", std::string variants = "NA", std::string sku = "NA",
        std::string productUrl = "NA", std::string stock = "NA", std::string productDetails = "NA", 
        std::string dimensions = "NA", std::string color = "NA", std::string ingredients = "NA",
        std::string directionToUse = "NA", std::string isAmazonSeller = "NA", std::string sizeQuantityVariant = "NA",
        std::string productDescription = "NA") : productName(productName), brandName(brandName),
        asin(asin), category(category), upcEanCode(upcEanCode), listPrice(listPrice), sellingPrice(sellingPrice), 
        quantity(quantity), modelNumber(modelNumber), aboutProduct(aboutProduct), 
        productSpecification(productSpecification), technicalDetails(technicalDetails), shippingWeight(shippingWeight),
        productDimensions(productDimensions), image(image), variants(variants), sku(sku),
        productUrl(productUrl), stock(stock), productDetails(productDetails), dimensions(dimensions),
        color(color), ingredients(ingredients), directionToUse(directionToUse), isAmazonSeller(isAmazonSeller), 
        sizeQuantityVariant(sizeQuantityVariant), productDescription(productDescription) {
        }

    // Destructor
    ~AmazonProductInformation() {
    }

    // Copy Constructor
    AmazonProductInformation(const AmazonProductInformation& other) : productName(other.productName), 
        brandName(other.brandName), asin(other.asin), category(other.category), upcEanCode(other.upcEanCode),
        listPrice(other.listPrice), sellingPrice(other.sellingPrice), quantity(other.quantity),
        modelNumber(other.modelNumber), aboutProduct(other.aboutProduct), 
        productSpecification(other.productSpecification), technicalDetails(other.technicalDetails),
        shippingWeight(other.shippingWeight), productDimensions(other.productDimensions),
        image(other.image), variants(other.variants), sku(other.sku), productUrl(other.productUrl),	
        stock(other.stock), productDetails(other.productDetails), dimensions(other.dimensions),
        color(other.color), ingredients(other.ingredients), directionToUse(other.directionToUse), 
        isAmazonSeller(other.isAmazonSeller), sizeQuantityVariant(other.sizeQuantityVariant),
        productDescription(other.productDescription) { 
    }

    // Copy Assignment
    AmazonProductInformation& operator=(const AmazonProductInformation& other) {

        if (this != &other) {

            productName = other.productName;
            brandName = other.brandName;
            asin = other.asin; 
            category = other.category; 
            upcEanCode = other.upcEanCode;
            listPrice = other.listPrice; 
            sellingPrice = other.sellingPrice;
            quantity = other.quantity;
            modelNumber = other.modelNumber; 
            aboutProduct = other.aboutProduct; 
            productSpecification = other.productSpecification; 
            technicalDetails = other.technicalDetails;
            shippingWeight = other.shippingWeight;
            productDimensions = other.productDimensions;
            image = other.image;	
            variants = other.variants;	
            sku = other.sku;	
            productUrl = other.productUrl;	
            stock = other.stock;
            productDetails = other.productDetails;
            dimensions = other.dimensions;	
            color = other.color;
            ingredients = other.ingredients;	
            directionToUse = other.directionToUse;	
            isAmazonSeller = other.isAmazonSeller;
            sizeQuantityVariant = other.sizeQuantityVariant;
            productDescription = other.productDescription;            
        }

        return *this;
    }
       
    // Move Constructor
    AmazonProductInformation(AmazonProductInformation&& other) noexcept :
        productName(std::move(other.productName)), brandName(std::move(other.brandName)), 
        asin(std::move(other.asin)), category(std::move(other.category)), upcEanCode(std::move(other.upcEanCode)),
        listPrice(std::move(other.listPrice)), sellingPrice(std::move(other.sellingPrice)), 
        quantity(std::move(other.quantity)), modelNumber(std::move(other.modelNumber)), 
        aboutProduct(std::move(other.aboutProduct)), productSpecification(std::move(other.productSpecification)), 
        technicalDetails(std::move(other.technicalDetails)), shippingWeight(std::move(other.shippingWeight)), 
        productDimensions(std::move(other.productDimensions)), image(std::move(other.image)), 
        variants(std::move(other.variants)), sku(std::move(other.sku)), productUrl(std::move(other.productUrl)),	
        stock(std::move(other.stock)), productDetails(std::move(other.productDetails)), 
        dimensions(std::move(other.dimensions)), color(std::move(other.color)), 
        ingredients(std::move(other.ingredients)), directionToUse(std::move(other.directionToUse)), 
        isAmazonSeller(std::move(other.isAmazonSeller)), sizeQuantityVariant(std::move(other.sizeQuantityVariant)),
        productDescription(std::move(other.productDescription)) { 


        other.productName = other.brandName = other.category = other.asin = other.upcEanCode = 
        other.listPrice = other.sellingPrice = other.quantity = other.modelNumber = 
        other.aboutProduct = other.productSpecification = other.technicalDetails = 
        other.shippingWeight = other.productDimensions = other.image = other.variants = 
        other.sku = other.productUrl = other.stock = other.productDetails = other.dimensions = 
        other.color = other.ingredients  = other.directionToUse = other.isAmazonSeller = 
        other.sizeQuantityVariant = other.productDescription = "NA";    
    }

    // Move Assignment
    AmazonProductInformation& operator=(AmazonProductInformation&& other) noexcept {

        if (this != &other) {
 
            productName = std::move(other.productName);
            brandName = std::move(other.brandName);
            asin = std::move(other.asin); 
            category = std::move(other.category); 
            upcEanCode = std::move(other.upcEanCode);
            listPrice = std::move(other.listPrice); 
            sellingPrice = std::move(other.sellingPrice);
            quantity = std::move(other.quantity);
            modelNumber = std::move(other.modelNumber); 
            aboutProduct = std::move(other.aboutProduct); 
            productSpecification = std::move(other.productSpecification); 
            technicalDetails = std::move(other.technicalDetails);
            shippingWeight = std::move(other.shippingWeight);
            productDimensions = std::move(other.productDimensions);
            image = std::move(other.image);	
            variants = std::move(other.variants);	
            sku = std::move(other.sku);	
            productUrl = std::move(other.productUrl);	
            stock = std::move(other.stock);
            productDetails = std::move(other.productDetails);
            dimensions = std::move(other.dimensions);	
            color = std::move(other.color);
            ingredients = std::move(other.ingredients);	
            directionToUse = std::move(other.directionToUse);	
            isAmazonSeller = std::move(other.isAmazonSeller);
            sizeQuantityVariant = std::move(other.sizeQuantityVariant);
            productDescription = std::move(other.productDescription);
            

            other.productName = other.brandName = other.category = other.asin = other.upcEanCode = 
            other.listPrice = other.sellingPrice = other.quantity = other.modelNumber = 
            other.aboutProduct = other.productSpecification = other.technicalDetails = 
            other.shippingWeight = other.productDimensions = other.image = other.variants = 
            other.sku = other.productUrl = other.stock = other.productDetails = other.dimensions = 
            other.color = other.ingredients  = other.directionToUse = other.isAmazonSeller = 
            other.sizeQuantityVariant = other.productDescription = "NA";
        }

        return *this;
    }


    // Setters

    void setProductName (const std::string& productName) {
        this->productName = productName;
    }

    void setBrandName(const std::string& brandName) {
        this->brandName = brandName;
    }

    void setAsin(const std::string& asin) {
        this->asin = asin;
    }

    void setCategory(const std::string& category) {
        this->category = category;
    }

    void setUpcEanCode(const std::string& upcEanCode) {
        this->upcEanCode = upcEanCode;
    }

    void setListPrice(const std::string& listPrice) {
        this->listPrice = listPrice;
    }

    void setSellingPrice(const std::string& sellingPrice) {
        this->sellingPrice = sellingPrice;
    }

    void setQuantity(const std::string& quantity) {
        this->quantity = quantity;
    }

    void setModelNumber(const std::string& modelNumber) {
        this->modelNumber = modelNumber;
    }

    void setAboutProduct(const std::string& aboutProduct) {
        this->aboutProduct = aboutProduct;
    }	

    void setProductSpecification(const std::string& productSpecification) {
        this->productSpecification = productSpecification;
    }

    void setTechnicalDetails(const std::string& technicalDetails) {
        this->technicalDetails = technicalDetails;
    }

    void setShippingWeight(const std::string& shippingWeight) {
        this->shippingWeight = shippingWeight;
    }

    void setProductDimensions(const std::string& productDimensions) {
        this->productDimensions = productDimensions;
    }

    void setImage(const std::string& image) {
        this->image = image;
    }

    void setVariants(const std::string& variants) {
        this->variants = variants;
    }	

    void setSku(const std::string& sku) {
        this->sku = sku;
    }	

    void setProductUrl(const std::string& productUrl) {
        this->productUrl = productUrl;
    }

    void setStock(const std::string& stock) {
        this->stock = stock;
    }

    void setProductDetails(const std::string& productDetails) {
        this->productDetails = productDetails;
    }

    void setDimensions(const std::string& dimensions) {
        this->dimensions = dimensions;
    }

    void setColor(const std::string& color) {
        this->color = color;
    }
    
    void setIngredients(const std::string& ingredients) {
        this->ingredients = ingredients;
    }

    void setDirectionToUse(const std::string& directionToUse) {
        this->directionToUse = directionToUse;
    }

    void setIsAmazonSeller(const std::string& isAmazonSeller) {
        this->isAmazonSeller = isAmazonSeller;
    }

    void setSizeQuantityVariant(const std::string& sizeQuantityVariant) {
        this->sizeQuantityVariant = sizeQuantityVariant;
    }

    void setProductDescription(const std::string& productDescription) {
        this->productDescription = productDescription;
    }


    // Getters
    const std::string& getProductName() const {
        return productName;
    }

    const std::string& getBrandName() const {
        return brandName;
    }

    const std::string& getAsin() const {
        return asin;
    }	

    const std::string& getCategory() const {
        return category;
    }

    const std::string& getUpcEanCode() const {
        return upcEanCode;
    }

    const std::string& getListPrice() const {
        return listPrice;
    }
    
    const std::string& getSellingPrice() const {
        return sellingPrice;
    }

    const std::string& getQuantity() const {
        return quantity;
    }

    const std::string& getModelNumber() const {
        return modelNumber;
    }

    const std::string& getAboutProduct() const {
        return aboutProduct;
    }

    const std::string& getProductSpecification() const {
        return productSpecification;
    }

    const std::string& getTechnicalDetails() const {
        return technicalDetails;
    }

    const std::string& getShippingWeight() const {
        return shippingWeight;
    }

    const std::string& getProductDimensions() const {
        return productDimensions;
    }

    const std::string& getImage() const {
        return image;
    }

    const std::string& getVariants() const {
        return variants;
    }
    
    const std::string& getSku() const {
        return sku;
    }
    
    const std::string& getProductUrl() const {
        return productUrl;
    }
    
    const std::string& getStock() const {
        return stock;
    }
    
    const std::string& getProductDetails() const {
        return productDetails;
    }
    
    const std::string& getDimensions() const {
        return dimensions;
    }
    
    const std::string& getColor() const {
        return color;
    }
    
    const std::string& getIngredients() const {
        return ingredients;
    }
    
    const std::string& getDirectionToUse() const {
        return directionToUse;
    }
    
    const std::string& getIsAmazonSeller() const {
        return isAmazonSeller;
    }
    
    const std::string& getSizeQuantityVariant() const {
        return sizeQuantityVariant;
    }
    
    const std::string& getProductDescription() const {
        return productDescription;
    }
    

    private:

    std::string productName;
    std::string brandName;	
    std::string asin;	
    std::string category;
    std::string upcEanCode;
    std::string listPrice;
    std::string sellingPrice;
    std::string quantity;
    std::string modelNumber;
    std::string aboutProduct;	
    std::string productSpecification;
    std::string technicalDetails;
    std::string shippingWeight;
    std::string productDimensions;
    std::string image;	
    std::string variants;	
    std::string sku;	
    std::string productUrl;	
    std::string stock;
    std::string productDetails;
    std::string dimensions;	
    std::string color;
    std::string ingredients;	
    std::string directionToUse;	
    std::string isAmazonSeller;
    std::string sizeQuantityVariant;
    std::string productDescription;

};

#endif