// Project8 Part B
// squarer_test.cpp 
// Skeleton file provided by Glenn G. Chappell
// Further contributions by Justyn Durnford
// Created on 2020-11-20 by Glenn G. Chappell
// Last updated on 2020-11-29 by Justyn Durnford
//
// For CS 311 Fall 2020
// Test program for class Squarer
// For Project 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.h

// Includes for code to be tested
#include "squarer.h"         // For class Squarer
#include "squarer.h"         // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <random>
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

#include <string>
using std::string;
using std::to_string;

// Printable name for this test suite
const string test_suite_name =
"class Squarer"
" - CS 311 Proj 8, Ex B";

// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE("Squarer: Positive integers")
{
    random_device rand_dev;
    default_random_engine rand_engine(rand_dev());
    uniform_int_distribution<int> rand_int_dist(2, 1000);

    Squarer sq;
    int rand_int = 0;
    int expected_int = 0;

    for (int i = 0; i < 25; ++i)
    {
        rand_int = rand_int_dist(rand_engine);
        expected_int = rand_int * rand_int;

        INFO(to_string(rand_int) + " squared = " + to_string(expected_int));
        REQUIRE(sq(rand_int) == expected_int);
    }
}

TEST_CASE("Squarer: Negative integers")
{
    random_device rand_dev;
    default_random_engine rand_engine(rand_dev());
    uniform_int_distribution<int> rand_int_dist(-1000, -2);

    Squarer sq;
    int rand_int = 0;
    int expected_int = 0;

    for (int i = 0; i < 25; ++i)
    {
        rand_int = rand_int_dist(rand_engine);
        expected_int = rand_int * rand_int;

        INFO(to_string(rand_int) + " squared = " + to_string(expected_int));
        REQUIRE(sq(rand_int) == expected_int);
    }
}

TEST_CASE("Squarer: Positive floating-points")
{
    random_device rand_dev;
    default_random_engine rand_engine(rand_dev());
    uniform_real_distribution<float> rand_float_dist(2.0f, 1000.0f);

    Squarer sq;
    float rand_float = 0.0f;
    float expected_float = 0.0f;

    for (int i = 0; i < 25; ++i)
    {
        rand_float = rand_float_dist(rand_engine);
        expected_float = rand_float * rand_float;

        INFO(to_string(rand_float) + " squared = " + to_string(expected_float));
        REQUIRE(sq(rand_float) == expected_float);
    }
}

TEST_CASE("Squarer: Negative floating-points")
{
    random_device rand_dev;
    default_random_engine rand_engine(rand_dev());
    uniform_real_distribution<float> rand_float_dist(-1000.0f, -2.0f);

    Squarer sq;
    float rand_float = 0.0f;
    float expected_float = 0.0f;

    for (int i = 0; i < 25; ++i)
    {
        rand_float = rand_float_dist(rand_engine);
        expected_float = rand_float * rand_float;

        INFO(to_string(rand_float) + " squared = " + to_string(expected_float));
        REQUIRE(sq(rand_float) == expected_float);
    }
}

TEST_CASE("Special cases: 0, -1, 1")
{
    Squarer sq;

    INFO("0 squared = 0");
    REQUIRE(sq(0) == 0);

    INFO("-1 squared = 1");
    REQUIRE(sq(-1) == 1);

    INFO("1 squared = 1");
    REQUIRE(sq(1) == 1);
}

TEST_CASE("Const Squarer objects")
{
    random_device rand_dev;
    default_random_engine rand_engine(rand_dev());
    uniform_int_distribution<int> rand_int_dist(2, 1000);

    const Squarer sq;
    int rand_int = 0;
    int expected_int = 0;

    for (int i = 0; i < 25; ++i)
    {
        rand_int = rand_int_dist(rand_engine);
        expected_int = rand_int * rand_int;

        INFO(to_string(rand_int) + " squared = " + to_string(expected_int));
        REQUIRE(sq(rand_int) == expected_int);
    }
}

// *********************************************************************
// Main Program
// *********************************************************************

// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n');
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc, char* argv[])
{
    doctest::Context dtcontext;
    // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        cout << "BEGIN tests for " << test_suite_name << "\n" << endl;
        dtresult = dtcontext.run();
        cout << "END tests for " << test_suite_name << "\n" << endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}