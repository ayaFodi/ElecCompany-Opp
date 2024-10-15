#pragma once
#include<iostream> 
#include <string>

#ifndef _ITEM_H_
#define _ITEM_H
#define ID 212001812

class Item {

protected:
	int _price;
	std::string _manufacturer;
	static int id;
	 int ide;

public:

	//constructor
	Item(int price, const std::string& manufacturer); 

	//pure To string convertion function
	virtual   operator std::string() const = 0;     

	//getprice method
	const int& getPrice() const;                             

	//getManufacturer method
	const std::string& getManufacturer() const;              

	//getId method
	const int& getId() const;                                

	//setPrice method
	void setPrice(const int price);                    

	//setManufacturer method
	void setManufacturer(const std::string& manufacturer); 

	//Destructor
	virtual ~Item();  
};
#endif
