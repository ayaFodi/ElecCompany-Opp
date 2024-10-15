#pragma once

#ifndef HWExceptions_H
#define HWExceptions_H

#include<string.h>
#include<string>
#include <exception>

class ExistingItemError :public std::exception
{
public:
	ExistingItemError() {}
	~ExistingItemError() {}
	const char* what() const noexcept
	{

		return  "Trying to add an item with an id already in the catalog";

	}
};

class FullCatalogError :public std::exception
{
public:
	FullCatalogError() {}
	~FullCatalogError() {}
	const char* what() const noexcept
	{

		return  "Trying to add an item to a full catalog";

	}
};

class NonExistingItemError :public std::exception
{
public:
	NonExistingItemError() {}
	~NonExistingItemError() {}
	const char* what() const noexcept
	{

		return  "Trying to delete an item with a non existing id";


	}

};

class NoneExistingItemTypeError :public std::exception
{
public:
	NoneExistingItemTypeError() {}
	~NoneExistingItemTypeError() {}
	const char* what() const noexcept
	{

		return  "Trying to get an item with a non existing type";
	}

};

class ConnectError :public std::exception
{
public:
	ConnectError() {}
	~ConnectError() {}
	const char* what() const noexcept
	{

		return  "Failed connection attempt";
	}

};
#endif
