// Project1 ProductOrder
// productorder.cpp
// Justyn Durnford
// Created on 2020-09-02
// Last updated on 2020-09-04
// Source file for the ProductOrder class

#include "productorder.h"

#include <string>
using std::string;

void ProductOrder::setValues(const string& name, int number)
{
	if (!name.empty())
		_name = name;
	if (number >= 0)
		_number = number;
}

ProductOrder::ProductOrder()
{
	setValues("UNSPECIFIED", -1);
}

ProductOrder::ProductOrder(const string& name, int number)
{
	setValues(name, number);
}

string ProductOrder::getName() const
{
	return _name;
}

int ProductOrder::getNumber() const
{
	return _number;
}

void ProductOrder::setName(const string& name)
{
	setValues(name, -1);
}

void ProductOrder::setNumber(int number)
{
	setValues("", number);
}