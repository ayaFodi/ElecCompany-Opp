#pragma once
#include <iostream> 
#include "Branch.h"
#include <string>
#include <map>
#include<algorithm>




#ifndef _MAINOFFICE _H_
#define _MAINOFFICE_H

// MainOffice class using singleton
class MainOffice       
{
private:
	std::map<std::string, Branch> branch;
	MainOffice() {};
	MainOffice(MainOffice& other) = delete;
	MainOffice& operator=(MainOffice& other) = delete;
public:
	static MainOffice& getInstance()
	{
		static MainOffice instance;
		return instance;
	}
	void addBranch(const std::string location, int capacity);
	void deleteBranch(const  std::string location);
	const void printByLocation();
	std::map<std::string, Branch>& getBranches();

};
#endif

class ExistingBranchError :public std::exception
{

private:
	std::exception exception;
public:
	ExistingBranchError() {}
	~ExistingBranchError() {}
	const char* what() const noexcept
	{

		return  "Trying to add a branch with an already existing location";

	}
};
class NonExistingBranchError :public std::exception
{

private:
	std::exception exception;
public:
	NonExistingBranchError() {}
	~NonExistingBranchError() {}
	const char* what() const noexcept
	{

		return  "Trying to delete a branch with an non existing location";

	}
};