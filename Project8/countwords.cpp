// Project 8
// countwords.cpp
// Justyn Durnford
// Created on 2020-11-20
// Last updated on 2020-11-20
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

#include <utility>
using std::pair;
using std::make_pair;

// Iterates through every element of the std::map and
// prints each associated value.
// Preconditions: 
//  #1: begin <= end
//  #2: begin != nullptr
void print_map_str_ull(map<string, unsigned long long>::const_iterator begin, 
					   map<string, unsigned long long>::const_iterator end)
{
	while (begin != end)
	{
		cout << begin->first << ": " << begin->second << endl;
		++begin;
	}
}

int main()
{
	string file_dir, word;
	map<string, unsigned long long> data;

	cout << "Enter a txt file to read from." << endl;
	cin >> file_dir;

	ifstream fin(file_dir);

	if (fin.bad()) // Could not open file.
	{
		cout << "Could not open file " << file_dir << endl;
		return 1;
	}

	while (!fin.bad())
	{
		fin >> word;
		++data[word];
	}

	print_map_str_ull(data.begin(), data.end());

	return 0;
}