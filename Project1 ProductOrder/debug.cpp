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
	cout << "TESTING PRODUCTORDER CONSTRUCTORS, SETTERS AND GETTERS..." << endl << endl;

	{
		ProductOrder po;
		cout << "TESTING DEFAULT CONSTRUCTOR..." << endl;
		cout << "NAME: " << po.getName() << endl;
		cout << "NUMBER: " << po.getNumber() << endl << endl;
	}

	{
		ProductOrder po("Paper Towels", 2);
		cout << "TESTING PRIMARY CONSTRUCTOR..." << endl;
		cout << "NAME: " << po.getName() << endl;
		cout << "NUMBER: " << po.getNumber() << endl << endl;
	}

	{
		ProductOrder po;
		cout << "TESTING SETTER METHODS..." << endl;
		cout << "DEFAULT VALUES:" << endl;
		cout << "NAME: " << po.getName() << endl;
		cout << "NUMBER: " << po.getNumber() << endl << endl;

		po.setName("Napkins");
		po.setNumber(4);
		cout << "NEW VALUES:" << endl;
		cout << "NAME: " << po.getName() << endl;
		cout << "NUMBER: " << po.getNumber() << endl << endl;
	}

	return 0;
}