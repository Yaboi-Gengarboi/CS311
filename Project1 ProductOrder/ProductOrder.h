// Project1 ProductOrder
// productorder.h
// Justyn Durnford
// Created on 2020-09-02
// Last updated on 2020-09-04
// Header file for the ProductOrder class

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

#ifndef PRODUCTORDER_H
#define PRODUCTORDER_H

#include <string>
#include <ostream>

// The ProductOrder class represents an order for an item
// or product you might find in a store or on a website. 
//
// INVARIANTS: 
//     _name.empty() != true
//     _number >= 0
class ProductOrder
{
	std::string _name;
	int _number = 0;

	// This is a private member function that sets the
	// values of _name and _number. Since this is done
	// multiple times in the code, other functions will
	// simply call this function, which will make the
	// code more DRY.
	// 
	// IF name is an empty string, _name will not be changed.
	// IF number is < 0, _number will not be changed.
	void setValues(const std::string& name, int number);

	public:

	// Default Constructor.
	// _name is set to "UNSPECIFIED"
	// _number is unchanged and is still 0
	ProductOrder();

	// Primary Constructor.
	// PRECONDITIONS:
	//     _name is not an empty string
	//     _number >= 0
	// _name is set to name
	// _number is set to number
	ProductOrder(const std::string& name, int number);

	// These constructors need nothing special, so we'll just = default them.
	ProductOrder(const ProductOrder& po) = default;
	ProductOrder& operator = (const ProductOrder& po) = default;
	ProductOrder(ProductOrder&& po) = default;
	ProductOrder& operator = (ProductOrder && po) = default;

	// Destructor.
	~ProductOrder() = default;

	// Returns _name.
	std::string getName() const;

	// Returns _number.
	int getNumber() const;

	// Sets _name to name IF name.empty() returns false.
	void setName(const std::string& name);

	// Sets _number to number IF number >= 0.
	void setNumber(int number);

	// Returns true if _number is 0.
	bool empty() const;

	// Returns a std::string representation of the ProductOrder
	// in the format: "_name (_number)".
	std::string toString() const;

	// Preincrement operator.
	// This function will prevent overflow by checking if _number
	// is the maximum value of a signed int.
	ProductOrder& operator ++ ();

	// Postincrement operator.
	// This function will prevent overflow by checking if _number
	// is the maximum value of a signed int.
	ProductOrder operator ++ (int dummy);

	// Predecriment operator.
	// This function will prevent _number from going below 0 by
	// checking if _number is 0.
	ProductOrder& operator -- ();

	// Postdecriment operator.
	// This function will prevent _number from going below 0 by
	// checking if _number is 0.
	ProductOrder operator -- (int dummy);
};

// Equality operator for ProductOrder class.
// Returns true if po1.getName() == po2.getName() AND
// po1.getNumber() == po2.getNumber()
bool operator == (const ProductOrder& po1, const ProductOrder& po2);

// Inequality operator for ProductOrder class.
// Returns true if po1.getName() != po2.getName() OR
// po1.getNumber() != po2.getNumber()
bool operator != (const ProductOrder& po1, const ProductOrder& po2);

std::ostream& operator << (std::ostream& os, const ProductOrder& po);

#endif // PRODUCTORDER_H