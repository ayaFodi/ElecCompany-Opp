
#include "Webcam.h"

using std::cout;

// To string convertion function implementation
Webcam::operator std::string()const 
{
    std::string s1 = "Webcam with HD resolution";
    return PeripheralDevice::operator std::string() + "," + " " + s1;
}

// getResolution method
const std::string Webcam::getResolution() 
{
    return _resolution;
}

// setResolution method
void Webcam::setResolution(const std::string resolution) 
{
    _resolution = resolution;
}

// connect fun implementation
void Webcam::connect(Computer* val)  
{

    cout << "Connecting a webcam" << std::endl;
    PeripheralDevice::connect(val);

}

// Destructor
Webcam::~Webcam() 
{

}