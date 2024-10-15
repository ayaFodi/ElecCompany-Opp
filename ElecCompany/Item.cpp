#include "Item.h"

int Item::id = 0; // starts id 

// constructor
Item::Item(int price, const std::string& manufacturer) 
{
    _price = price;
    _manufacturer = manufacturer;
    id++;
    ide = id;
}

//To string convertion function implementation
Item::operator std::string() const    
{
    std::string s1 = "id";
    std::string s2 = " " + std::to_string(this->ide) + ":" + " ";
    std::string s3 = this->_manufacturer + " ";
    std::string s4 = std::to_string(this->_price) + "$" ;
    std::string s = s1 + s2 + s3 + s4;
    return s;
}

//getPrice method
const int& Item::getPrice() const   
{
    return _price;
}

//getManufacturer method
const std::string& Item::getManufacturer() const 
{
    return _manufacturer;
}

//getId method
const int& Item::getId() const 
{
    return ide;
}

// setPrice method
void Item::setPrice(const int price) 
{
    _price = price;
}

//setManufacturer method
void Item::setManufacturer(const std::string& manufacturer) 
{
    _manufacturer = manufacturer;
}

// Destructor
Item::~Item()  
{
    std::cout << "Throwing away an item" << std::endl;
}