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
	ProductOrder po1;
	ProductOrder po2("Paper", 2);

	while (po1 != po2)
	{
		cout << po1.toString() << endl;
		cout << po2.toString() << endl;
		cout << "po1 != po2" << endl << endl;

		po1.setName("Paper");
		po1.setNumber(2);
	}

	cout << po1.toString() << endl;
	cout << po2.toString() << endl;
	cout << "po1 == po2" << endl << endl;

	return 0;
}