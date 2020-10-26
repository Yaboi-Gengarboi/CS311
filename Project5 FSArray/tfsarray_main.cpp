// Project5 FSArray
// fsarray_main.cpp
// Justyn Durnford
// Created on 2020-10-14
// Last updated on 2020-10-26
// Test file for FSArray template class.

#include "tfsarray.h"

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

template <typename T>
void print_tfsarr(const TFSArray<T>& arr)
{
	cout << "{ ";

	for (size_t i = 0; i < arr.size() - 1; ++i)
		cout << to_string(arr[i]) << ", ";

	cout << to_string(arr[arr.size() - 1]) << " }" << endl;
}

int main()
{
	TFSArray<int> arr1(10, 1);
	TFSArray<int> arr2(10, 2);

	cout << "Before swap: " << endl;
	print_tfsarr(arr1);
	print_tfsarr(arr2);

	arr1.swap(arr2);

	cout << "After swap: " << endl;
	print_tfsarr(arr1);
	print_tfsarr(arr2);
	
	return 0;
}