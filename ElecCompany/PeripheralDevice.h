#pragma once
#include<iostream> 
#include "Item.h"
#include "Computer.h"
#include <string>

#ifndef _PERIPHERALDEVICE_H_
#define _PERIPHERALDEVICE_H

using std::cout;
using std::endl;

class PeripheralDevice : public Item
{
private:
	std::string _Color;
	bool _iswireless;
	Computer* dev;      // pointer to computer we using it to connect

public:

	// disconnect fun
	void disconnect();   

	// constructor
	PeripheralDevice(int price, std::string manufacturer, std::string Color, bool iswireless) :Item(price, manufacturer), _Color(Color), _iswireless(iswireless) {} 
	
	// pure function
	virtual void connect(Computer* val) = 0;  

	// To string convertion function
	virtual  operator std::string() const override;   

	// getColor method
	const std::string getColor() const;           

	// getIsWireless method
	const bool getIsWireless() const;             

	// setColor method
	void setColor(const std::string color); 

	// setIsWireless method
	void setIsWireless(const bool iswireless); 

	// Destructor 
	virtual ~PeripheralDevice();        

};
#endif