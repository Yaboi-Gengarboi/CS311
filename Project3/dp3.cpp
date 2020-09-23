// Project3
// dp3.cpp
// Justyn Durnford
// Created on 2020-09-21
// Last updated on 2020-09-23
// Source file for Project 3 functions

#include "dp3.h"

#include <functional>
using std::function;

#include <stdexcept>
using std::out_of_range;

void didItThrow(const function<void()>& ff, bool& threw)
{
    try
    {
        ff();
        threw = false;
    }
    catch (...)
    {
        threw = true;
        throw;
    }
}

int gcd(int a, int b)
{
    return 0;
}