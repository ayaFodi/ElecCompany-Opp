#pragma once
#include<iostream> 
#include "PeripheralDevice.h"
#include <string>

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H

using std::cout;

class Keyboard :public PeripheralDevice {

private:
	int _numkeys;
public:

	//constructor
	Keyboard(int price, std::string manufacturer, std::string color, bool iswireless, int numkeys) :PeripheralDevice(price, manufacturer, color, iswireless), _numkeys(numkeys) {} 
	
	//getNumOfKeys method
	const int getNumOfKeys() const; 

	//setNumOfKeys
	void setNumOfKeys(const int numkeys); 

	//connect fun
	virtual void connect(Computer* val); 

	//To string convertion function
	virtual  operator std::string() const override; 

	//Destructor
	virtual ~Keyboard(); 

};
#endif
