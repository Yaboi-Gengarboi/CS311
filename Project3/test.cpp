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
		cout << i << endl;
	}
	catch (const out_of_range& error)
	{
		delete head;
		cout << error.what() << endl;
	}

	LLNode<int>* tail = new LLNode<int>(1, nullptr);
	head = new LLNode<int>(0, tail);

	try
	{
		int i = lookup(head, 1);
		cout << i << endl;
	}
	catch (const out_of_range& error)
	{
		delete head;
		cout << error.what() << endl;
	}

	try
	{
		int i = lookup(head, 2);
		cout << i << endl;
	}
	catch (const out_of_range& error)
	{
		delete head;
		cout << error.what() << endl;
	}

	vector<int> v1 = { 0, 1, 2, 3, 4, 5 };
	vector<int> v2 = { 3, 7, 2, 9, 5, 1 };
	bool sorted1 = checkSorted(v1.begin(), v1.end());
	bool sorted2 = checkSorted(v2.begin(), v2.end());

	if (sorted1)
		cout << "v1 is sorted" << endl;
	else
		cout << "v1 is not sorted" << endl;

	if (sorted2)
		cout << "v2 is sorted" << endl;
	else
		cout << "v2 is not sorted" << endl;

	cout << gcd(0, 1) << endl;
	cout << gcd(4, 16) << endl;
	cout << gcd(910, 42) << endl;

	return 0;
}