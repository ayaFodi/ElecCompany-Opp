#include "Computer.h"

//To string convertion function implementation
Computer::operator std::string() const  
{
    std::string s1;
    if (this->_isalaptop == 1)
    {
        s1 = "Laptop,";
    }
    else
    {
        s1 = "Desktop,";
    }
    std::string s2 = " " + this->_cpu;

    return Item::operator std::string() + "," + " " + s1 + s2;
}


//getCpu method
const std::string Computer::getCpu() const 
{
    return _cpu;
}


//getIsalap method
const bool Computer::getIsalap() const 
{
    return _isalaptop;
}

//setCpu method
void Computer::setCpu(const std::string cpu) 
{
    _cpu = cpu;
}

//setIsalap method
void Computer::setIsalap(const bool isalap) 
{
    _isalaptop = isalap;
}

//getports method
const int Computer::getPorts() const       
{
    return _ports;
}

//fun to check if allow to make a device connecting to computer
bool Computer::isvalid(Item* device)   
{
    if (comp.size() == _ports) { return false; }
    std::vector<Item*>::iterator it;
    for (it = comp.begin(); it != comp.end(); ++it)
    {
        if (typeid(device) == typeid(**it)) { return  false; }
    }
    comp.push_back(device);
    return true;

}

//fun to disconnect device from cumputer
void Computer::isdisconnected(Item* device)             
{
    std::vector<Item*>::iterator it;
    for (it = comp.begin(); it != comp.end(); ++it)
    {
        //if the device is connecting to the computer as disconnect it 
        if (typeid(*device) == typeid(**it))           
        {
            comp.erase(it);
            return;


        }
    }
}

//print connected fun
const void Computer::print_connected()               
{
    cout << "There are " << comp.size() << " connection to " << std::string(*this) << std::endl;
    for (int i = 0; i < comp.size(); i++) {
        cout << std::string(*comp[i]) << std::endl;
    }
}

// Destructor
Computer::~Computer() 
{
    for (int i = 0; i < comp.size(); i++)
    {
        comp.pop_back();
    }
    comp.clear();
}
