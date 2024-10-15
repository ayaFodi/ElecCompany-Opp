
#include "MainOffice.h"

//addbranch method to add a newbranch to the map
void MainOffice::addBranch(const std::string location, int capacity)       
{
	std::map<std::string, Branch>::iterator it;

	//check if the newbranch is already existing in the map
	it = branch.find(location);         

	//if we find it in the map is throw
	if (it != branch.end()) { throw ExistingBranchError(); }  

	//if its not in the map as add it
	branch.insert(it, { location, Branch(location,capacity) });     

}


void MainOffice::deleteBranch(const std::string location)                
{
	std::map<std::string, Branch>::iterator it;
	//check if the newbranch is already existing in the map
	it = branch.find(location);                                

	//if the wanted branch does not existing in the map as throw 
	if (it == branch.end()) { throw NonExistingBranchError(); }    

	//delete the wanted branch 
	branch.erase(location);                                     
}

//printbylocation method 
const void MainOffice::printByLocation()                                        
{
	std::cout << "There are " << branch.size() << " KSP branches" << std::endl;
	std::map<std::string, Branch>::iterator it;
	for (it = branch.begin(); it != branch.end(); ++it)
	{
		//prints the branches by id 
		it->second.print_catalog_by_id();                                           
	}
}

//getBranches method
std::map<std::string, Branch>& MainOffice::getBranches()         
{
	return branch;
}