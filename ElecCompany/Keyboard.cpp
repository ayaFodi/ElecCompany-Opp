#include "Keyboard.h"

using std::cout;

//To string convertion function
Keyboard::operator std::string() const
{
    std::string s1 = "Keyboard with ";
    return PeripheralDevice::operator std::string() + "," + " " + s1 + std::to_string(this->_numkeys) + " " + "keys";
}

//getNumofkeys method
const int Keyboard::getNumOfKeys() const 
{
    return _numkeys;
}

//setNumofkeys method
void Keyboard::setNumOfKeys(const int numkeys) 
{
    _numkeys = numkeys;
}

//connect fun implementation 
void Keyboard::connect(Computer* val) 
{
    cout << "Connecting a keyboard" << std::endl;
    PeripheralDevice::connect(val);
}

//Destructor
Keyboard::~Keyboard() 
{

}
