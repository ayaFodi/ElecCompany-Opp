
#pragma once
#include<iostream> 
#include "Item.h"
#include <string>
#include<algorithm>
#include <vector>
#include"HWExceptions.h"

#ifndef _COMPUTER_H_
#define _COMPUTER_H
using std::cout;
class Computer : public Item
{
private:
	std::string _cpu;
	bool _isalaptop;
	int _ports;
	std::vector<Item*> comp;    //vector of items we using it in connect fun
public:

	// constructor
	Computer(int price, std::string manufacturer, std::string cpu, bool isalaptop, int ports) :Item(price, manufacturer), _cpu(cpu), _isalaptop(isalaptop), _ports(ports) {} 
	
	//Destructor
	virtual ~Computer(); 

	//To string convertion function
	virtual  operator std::string() const override; 

	//getCpu method
	const std::string getCpu() const; 

	//getIsalap method
	const bool getIsalap() const;

	//setCpu method
	void setCpu(const std::string cpu); 

	//setIsalap
	void setIsalap(const bool isalap); 

	//getports fun
	const int getPorts() const;            

	//fun to check if allow to make a device connecting to computer
	bool isvalid(Item* device);  

	//fun to disconnect device from cumputer
	void isdisconnected(Item* device); 

	//print connect fun
	const void print_connected();      

};
#endif