// Project1 ProductOrder
// productorder.cpp
// Justyn Durnford
// Created on 2020-09-02
// Last updated on 2020-09-04
// Source file for the ProductOrder class

/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
*/

#include "ProductOrder.h"

#include <string>
using std::string;
using std::to_string;

#include <ostream>
using std::ostream;

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
	if (_number == 2147483647) // Max number for int
		return *this;

	++_number;
	return *this;
}

ProductOrder ProductOrder::operator ++ (int dummy)
{
	ProductOrder po(*this);
	
	if (_number == 2147483647) // Max number for int
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
	if (po1.getName() != po2.getName())
		return true;

	if (po1.getNumber() != po2.getNumber())
		return true;

	return false;
}

ostream& operator << (ostream& os, const ProductOrder& po)
{
	os << po.toString();
	return os;
}