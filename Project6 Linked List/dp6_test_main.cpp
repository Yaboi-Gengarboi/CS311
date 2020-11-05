// Project6 Linked List
// dp6_test_main.cpp
// Justyn Durnford
// Created on 2020-10-30
// Last updated on 2020-11-04
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
	unique_ptr<LLNode2<int>> np = nullptr;
	unique_ptr<LLNode2<int>> n4 = make_unique<LLNode2<int>>(4, np);
	unique_ptr<LLNode2<int>> n3 = make_unique<LLNode2<int>>(3, n4);
	unique_ptr<LLNode2<int>> n2 = make_unique<LLNode2<int>>(2, n3);
	unique_ptr<LLNode2<int>> n1 = make_unique<LLNode2<int>>(1, n2);

	cout << n1->_data << ", ";
	cout << n1->_next->_data << ", ";
	cout << n1->_next->_next->_data << ", ";
	cout << n1->_next->_next->_next->_data;
	cout << endl;

	reverseList(n1);

	cout << n1->_data << ", ";
	cout << n1->_next->_data << ", ";
	cout << n1->_next->_next->_data << ", ";
	cout << n1->_next->_next->_next->_data;
	cout << endl;

	return 0;
}