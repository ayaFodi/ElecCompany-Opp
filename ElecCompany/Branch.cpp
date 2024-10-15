#include "Branch.h"


 //struct to implement in it operator to tell the sort fun how to compare
struct compare_price     
{
	//operator to compare sort fun with  price
	bool operator()(Item* item1, Item* item2)     
	{
		return   item1->getPrice() < item2->getPrice();
	}

};

//struct to implement in it operator to tell the sort fun how to compare
struct compare_id 
{
	//operator to compare sort fun with  id
	bool operator()(Item* item1, Item* item2) 
	{
		return   item1->getId() < item2->getId();
	}

};

//default constructor
Branch::Branch() 
{
	_location = "~";
	_capacity = 0;
}

//constructor
Branch::Branch(const std::string& location, int capacity)    
{
	_location = location;
	_capacity = capacity;

}

//copy constructor
Branch::Branch(const Branch& other)                      
{
	this->_location = other._location;
	this->_capacity = other._capacity;
}

//addItem fun
void Branch::addItem(Item* val)    
{
	//check if val is already existing
	if (this->contains(val->getId())) { throw ExistingItemError(); }

	//check if the current number of items is equal to the store capacity
	if (catalog.size() == _capacity)    
	{
		throw FullCatalogError();
	}
	else if (catalog.size() != _capacity)
	{
		catalog.push_back(val);
	}
}

//fun that checks if the giving id is existing in the vector 
bool Branch::contains(int _id)         
{
	for (unsigned int i = 0; i < catalog.size(); i++)
	{
		if (catalog[i]->getId() == _id) {

			return true;
		}
	}
	return false;
}

//delete item fun
Item* Branch::deleteItem(int _id)       
{
	Item* item = catalog[0];
	//checks if id not exists in the vector
	if (!this->contains(_id))              
		throw NonExistingItemError();

	//checks if id exists in the vector 
	else if (this->contains(_id))		
	{

		std::vector<Item*>::iterator it = catalog.begin();
		for (int i = 0; i < catalog.size(); i++)
		{
			//checking if we find the wanted id
			if (catalog[i]->getId() == _id)           
			{



				item = catalog[i];
				catalog.erase(catalog.begin() + i);
				return item;

			}

		}
	}

}

// print catalog by id fun
void Branch::print_catalog_by_id()                       
{
	this->help_print();
	// sort the items by id using compare operator
	std::sort(catalog.begin(), catalog.end(), compare_id());  
	for (int i = 0; i < catalog.size(); i++)
	{
		std::cout << std::string(*catalog[i]) << std::endl;
	}
}

// print catalog by price fun
void Branch::print_catalog_by_price()                                  
{
	this->help_print();
	// sort the items by price using compare operator
	std::stable_sort(catalog.begin(), catalog.end(), compare_price());        
	for (int i = 0; i < catalog.size(); i++)
	{
		std::cout << std::string(*catalog[i]) << std::endl;
	}
}

// getcatalog method 
const std::vector<Item*> Branch::getCatalog() 
{
	return catalog;

}

// getlocation method
const std::string& Branch::getLocation() const 
{
	return _location;
}

//setlocation method
void Branch::setLocation(const std::string& location) 
{

	_location = location;
}

//getCapacity method
const int Branch::getCapacity() const
{
	return _capacity;
}

//setCapacity method
void Branch::setCapacity(const int capacity)
{
	_capacity = capacity;
}

//destructor 
Branch::~Branch() 
{

	for (int i = 0; i < catalog.size(); i++)
	{
		delete catalog[i];
	}
	catalog.clear();

}

//fun to calculate the branch value and return it 
int Branch::sumval()            
{
	int sum = 0;
	for (int i = 0; i < this->catalog.size(); i++) {
		sum += catalog[i]->getPrice();
	}
	return sum;
}

//print help fun using it in printing by id and price fun
const void Branch::help_print()                
{
	std::cout << "Printing KSF branch in " << this->getLocation() << std::endl;
	std::cout << "There are " << catalog.size() << " item in the catalog" << std::endl;
	std::cout << "Catalog value is: " << this->sumval() << std::endl;
}
