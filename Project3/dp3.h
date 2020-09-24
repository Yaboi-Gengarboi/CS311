// Project3
// dp3.h
// Justyn Durnford
// Created on 2020-09-21
// Last updated on 2020-09-23
// Header file for Project 3 functions

#ifndef DP3_H_INCLUDED
#define DP3_H_INCLUDED

#include "llnode.h"

#include <cstddef>
#include <functional>
#include <iterator>
#include <stdexcept>

// Iterates through a Linked List by starting with the passed head Node.
// The template type ValueType does not have any special requirements.
//
// Precondition: index must be a valid index of the Linked List.
//
// This function WILL THROW a std::out_of_range exception if the passed
// index is greater than the size of the Linked List.
template <typename ValueType>
ValueType lookup(const LLNode<ValueType>* head, const std::size_t& index)
{
    const LLNode<ValueType>* ptr = head;
    std::size_t i = 0;

    while (i != index && ptr != nullptr)
    {
        ptr = ptr->_next;
        ++i;
    }

    if (ptr == nullptr)
        throw std::out_of_range("Global function \"lookup(const LLNode<ValueType>* head, "
                                "const std::size_t& index)\" threw a std::out_of_range "
                                "exception: Invalid index.");

    return ptr->_data;
}

// Calls the passed function ff with no parameters and sets threw to true
// if the function ff threw. threw is set to false otherwise.
//
// This function WILL CATCH AND RETHROW any exception thrown by the
// function ff. Use the what() member function to see what the error was.
void didItThrow(const std::function<void()>& ff, bool& threw);

// Iterates through a container by using the passed forward iterators
// first and last, where first is pointing to the first element of the
// container and last pointing to 1 space beyond the last element of the 
// container, and comapres each element to determine if the container
// is sorted in ascending order (ie 0, 1, 2, 3...).
//
// As a Forward Iterator, this function will only compare indexes in
// ascending order. The Iterator must also overload the dereference 
// operator (*), and the less-than comparison operator (<).
template <typename FDIter>
bool checkSorted(FDIter first, FDIter last)
{
    FDIter iter1 = first;
    FDIter iter2 = std::next(iter1, 1);

    while (std::distance(iter2, last) > 0)
    {
        if (*(iter2) < *iter1)
            return false;

        std::advance(iter1, 1);
        std::advance(iter2, 1);
    }

    return true;
}

// This recursive function calculates the greatest common denominator
// (GCD) between the passed ints a and b.
//
// Specifically, the gcd is computed with the algorithm described by:
//
// If a == 0: return b
// If a > b:  return gcd(b, a)
// Otherwise: return gcd(b % a, a)
int gcd(int a, int b);

#endif DP3_H_INCLUDED