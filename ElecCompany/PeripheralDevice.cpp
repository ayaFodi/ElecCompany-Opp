#include "PeripheralDevice.h"


//To string convertion function implementation
PeripheralDevice::operator std::string() const 
{
    std::string s1;
    if (this->_iswireless == 1)
    {
        s1 = "Wireless,";
    }
    else {
        s1 = "Wired,";
    }
    return Item::operator std::string() + "," + " " + s1 + " " + this->_Color ;
}

//disconnect fun 
void PeripheralDevice::disconnect()           
{
    // if not connecting to computer do nothing
    if (this->dev == NULL)              
        return;
    dev->isdisconnected(this);
    dev = NULL;
    free(dev);

}

// connect fun 
void PeripheralDevice::connect(Computer* val)               
{
    if (this->dev == NULL) { this->dev = val; }    // if the device not connecting to computer as connect it
    else if (this->dev == val)                    // if the device connecting to this computer as do nothing
    {
        return;
    }
    cout << std::string(*this) << " " << "is Connecting to computer: " << std::string(*val) << std::endl;
    if (!val->isvalid(this) || this->dev != val)               // if the connecting not valid throw
    {

        throw ConnectError();
    }

}

// getColor method
const std::string PeripheralDevice::getColor() const 
{
    return _Color;
}

// getIsWireless method
const bool PeripheralDevice::getIsWireless() const 
{
    return _iswireless;
}

// setColor method
void PeripheralDevice::setColor(const std::string color) 
{
    _Color = color;
}

// setIsWireless method
void PeripheralDevice::setIsWireless(const bool iswireless) 
{
    _iswireless = iswireless;
}


// Destructor
PeripheralDevice::~PeripheralDevice() 
{
    this->disconnect();
    free(dev);
}