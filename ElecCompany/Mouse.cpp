#include "Mouse.h"

using std::cout;

//To string convertion function implementation
Mouse::operator std::string() const 
{
    std::string s1 = "Mouse with dpi ";
    return PeripheralDevice::operator std::string() + "," + " " + s1 + ":" + " " + std::to_string(this->_dpi);
}

//getDpi method
const int Mouse::getDpi() const 
{
    return _dpi;
}

//setDpi method
void Mouse::setDpi(const int dpi) 
{
    _dpi = dpi;
}

//connect fun implementation
void Mouse::connect(Computer* val) 
{

    cout << "Connecting a mouse" << std::endl;
    
    PeripheralDevice::connect(val);
}

//Destructor
Mouse::~Mouse() 
{

}