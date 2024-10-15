#pragma once
#include<iostream> 
#include "PeripheralDevice.h"
#include <string>

#ifndef _WEBCAM_H_
#define _WEBCAM_H

class Webcam :public PeripheralDevice {

private:
	std::string _resolution;
public:
	// constructor
	Webcam(int price, std::string manufacturer, std::string color, bool iswireless, std::string resolution) :PeripheralDevice(price, manufacturer, color, iswireless), _resolution(resolution) {} 
	
	// getResolution method
	const std::string getResolution(); 

	// setResolution method
	void setResolution(const std::string resolution); 

	// connect fun
	virtual void connect(Computer* val); 

	// To string convertion function
	virtual  operator std::string()const override; 

	// Destructor
	virtual ~Webcam(); 

};

#endif