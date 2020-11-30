// Project8 Part A
// countwords.cpp
// Justyn Durnford
// Created on 2020-11-20
// Last updated on 2020-11-25
// Source file for Part A of CS311 Project 8

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <map>
using std::map;

#include <string>
using std::string;
using std::getline;

// Iterates through every element of the std::map and
// prints each associated value.
// Preconditions: 
//  #1: begin <= end
// If Precondition #1 is met, this function should never
// throw.
void print_map_str_ull(map<string, unsigned long long>::const_iterator begin, 
					   map<string, unsigned long long>::const_iterator end) noexcept
{
	while (begin != end)
	{
		cout << begin->first << ": " << begin->second << endl;
		++begin;
	}
}

int read_file_and_count() 
{
	string file_dir, word;
	map<string, unsigned long long> data;

	cout << "Enter a txt file to read from." << endl;
	getline(cin, file_dir);

	// file_dir = "countwords_test.txt"; // Debug

	ifstream fin(file_dir);

	if (!fin.good()) // Could not open file.
	{
		cout << "Could not open file " << file_dir << endl;
		return 1;
	}

	while (fin.good())
	{
		fin >> word;

		if (fin.bad())
		{
			if (fin.eof())
				break;
			else
			{
				cout << "Error while reading file " << file_dir << endl;
				return 2;
			}
		}

		try
		{
			++data[word];
		}
		catch (...)
		{
			throw;
		}
	}

	print_map_str_ull(data.begin(), data.end());

	return 0;
}

int main()
{
	return read_file_and_count();
}