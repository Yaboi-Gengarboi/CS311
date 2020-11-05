// Project6 Linked List
// dp6_test_main.cpp
// Justyn Durnford
// Created on 2020-10-30
// Last updated on 2020-11-05
// Test file for Project 6.

#include "llnode2.h"
#include "dp6.h"

#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::unique_ptr;
using std::make_unique;

int main()
{
	LLMap<int, char> list;
	list.insert(0, 'a');
	list.insert(1, 'b');
	list.insert(2, 'c');
	list.insert(3, 'd');

	char* value = list.find(2);
	cout << *value << endl;

	list.erase(1);

	return 0;
}