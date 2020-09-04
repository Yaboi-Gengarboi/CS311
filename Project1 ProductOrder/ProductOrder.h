// Project1 ProductOrder
// productorder.h
// Justyn Durnford
// Created on 2020-09-02
// Last updated on 2020-09-04
// Header file for the ProductOrder class

#ifndef PRODUCTORDER_H
#define PRODUCTORDER_H

#include <string>

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

#endif // PRODUCTORDER_H