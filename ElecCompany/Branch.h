
#pragma once
#include <iostream> 
#include "Item.h"
#include <string>
#include<algorithm>
#include <vector>
#include"HWExceptions.h"


#ifndef _BRANCH_H_
#define _BRANCH_H

class Branch {

private:

	std::vector<Item*> catalog;	  // an vector of Item pointer
	int _capacity;				 // the capacity of the vectoor
	std::string _location;		// the location 

public:

	// default con's
	Branch();																		  

	//constructor
	Branch(const std::string& location, int capacity);							

	//copy constructor
	Branch(const Branch& other);

	//function to add an item
	void addItem(Item* val);		

	//checks if there is an item with the sent id in the vector

	//delete item fun
	bool contains(int _id);														

	//printing catalog items by id
	Item* deleteItem(int _id);		

	//printing catalog items by price
	void print_catalog_by_id();						

	//returnin the catalog vector
	void print_catalog_by_price();		

	//get location fun
	const std::vector<Item*> getCatalog();					

	//set location fun
	const std::string& getLocation() const;      

	// setlocation fun 
	void setLocation(const std::string& location);

	// getcapacity fun
	const int getCapacity() const;

	// setcapacity fun
	void setCapacity(const int capacity);			

	// Destructor
	~Branch();															  

	// fun to calculate the branch value and return it 
	int sumval();													

	// helping fun to print
	const void help_print();							


	// retrieveFinest fun
	template <typename T >
	T* retrieveFinest(const T* item)								   
	{
		int max = 0;
		T* maximum = NULL;
		std::vector<Item*>::iterator it;
		for (it = catalog.begin(); it != catalog.end(); ++it)
		{
			// if we find item in the vector with the same type of wanted item
			if (typeid(*item) == typeid(**it))       
			{
				// check which item has the max price and point to it
				if ((*it)->getPrice() > max)         
				{
					max = (*it)->getPrice();
					maximum = (T*)(*it);

				}
			}

		}
		// if maximum is null that's mean that there is no item with the wanted type in the vector
		if (maximum == NULL) { throw NoneExistingItemTypeError(); } 

		return   maximum;

	}

};



#endif // !_Branch_H_
