// Project3
// dp3.h
// Justyn Durnford
// Created on 2020-09-21
// Last updated on 2020-09-21
// Header file for Project 3 functions

#ifndef DP3_H_INCLUDED
#define DP3_H_INCLUDED

#include "llnode.h"

#include <cstddef>
#include <functional>
#include <stdexcept>

template <typename ValueType>
ValueType lookup(const LLNode<ValueType>* head, const std::size_t& index)
{
    const LLNode<ValueType>* ptr = head;
    std::size_t i = 0;

    while (ptr != nullptr && i != index)
    {
        ptr = ptr->_next;
        ++i;
    }

    if (ptr == nullptr && i != index)
        throw std::out_of_range("Global function \"lookup(const LLNode<ValueType>* head,"
                                "const std::size_t& index)\" threw a std::out_of_range"
                                "exception: Invalid index.");

    return ptr->_data;
}

void didItThrow(const std::function<void()>& ff, bool& threw);

template <typename FDIter>
bool checkSorted(FDIter first, FDIter last)
{
    return false;  // Dummy return
}

int gcd(int a, int b);

#endif DP3_H_INCLUDED