#pragma once
#include<iostream> 
#include "PeripheralDevice.h"
#include <string>

#ifndef _MOUSE_H_
#define _MOUSE_H

class Mouse : public PeripheralDevice {
private:
	int _dpi;
public:

	//constructor
	Mouse(int price, std::string manufacturer, std::string color, bool iswireless, int dpi) :PeripheralDevice(price, manufacturer, color, iswireless), _dpi(dpi) {} 
	
	//getDpi method
	const int getDpi() const; 

	//setDpi method
	void setDpi(const int dpi); 

	//connect fun
	virtual void connect(Computer* val);

	//To string convertion function
	virtual  operator std::string() const override;

	//Destructor
	virtual ~Mouse(); 
};
#endif