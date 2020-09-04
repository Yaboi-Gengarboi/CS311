// Project1 ProductOrder
// debug.cpp
// Justyn Durnford
// Created on 2020-09-02
// Last updated on 2020-09-04
// Source file to test the code of the ProductOrder class

#include "productorder.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	{
		ProductOrder po;
		if (!po.empty())
			cout << po.toString() << endl << endl;
	}

	{
		ProductOrder po("Paper Plates", 3);
		cout << po.toString() << endl << endl;
	}

	return 0;
}