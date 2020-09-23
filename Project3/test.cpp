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

#include <vector>
using std::vector;

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

	vector<int> v = { 0, 1, 2, 3, 4, 5 };
	bool sorted = checkSorted(v.begin(), v.end());

	if (sorted)
		cout << "v is sorted" << endl;
	else
		cout << "v is not sorted" << endl;

	return 0;
}