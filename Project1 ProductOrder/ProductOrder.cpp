// Project1 ProductOrder
// productorder.cpp
// Justyn Durnford
// Created on 2020-09-02
// Last updated on 2020-09-04
// Source file for the ProductOrder class

#include "productorder.h"

#include <string>
using std::string;
using std::to_string;

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

bool ProductOrder::empty() const
{
	return _number == 0;
}

string ProductOrder::toString() const
{
	return _name + " (" + to_string(_number) + ")";
}

ProductOrder& ProductOrder::operator ++ ()
{
	if (_number == 2147483647)
		return *this;

	++_number;
	return *this;
}

ProductOrder ProductOrder::operator ++ (int dummy)
{
	ProductOrder po(*this);
	
	if (_number == 2147483647)
		return po;

	++(*this);
	return po;
}

ProductOrder& ProductOrder::operator -- ()
{
	if (_number == 0)
		return *this;

	--_number;
	return *this;
}

ProductOrder ProductOrder::operator -- (int dummy)
{
	ProductOrder po(*this);

	if (_number == 0)
		return po;

	--(*this);
	return po;
}

bool operator == (const ProductOrder& po1, const ProductOrder& po2)
{
	if (po1.getName() != po2.getName())
		return false;

	if (po1.getNumber() != po2.getNumber())
		return false;

	return true;
}

bool operator != (const ProductOrder& po1, const ProductOrder& po2)
{
	if (po1.getName() == po2.getName())
		return false;

	if (po1.getNumber() == po2.getNumber())
		return false;

	return true;
}