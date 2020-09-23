// Project3
// test.cpp
// Justyn Durnford
// Created on 2020-09-21
// Last updated on 2020-09-23
// Test file

#include "llnode.h"
#include "dp3.h"

#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::out_of_range;

int main()
{
	LLNode<int>* head = nullptr;

	try
	{
		int i = lookup(head, 10);
	}
	catch (const out_of_range& error)
	{
		cout << error.what() << endl;
	}

	return 0;
}