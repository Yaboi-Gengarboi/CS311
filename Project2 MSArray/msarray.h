// Project2 MSArray
// msarray.h
// Justyn Durnford
// Created on 2020-09-09
// Last updated on 2020-09-16
// Header file for the MSArray class
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non - commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all presentand future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#ifndef MSARRAY_H_INCLUDED
#define MSARRAY_H_INCLUDED

#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <utility>

// This class serves as a moderately smart array container.
// The given objects to be contained must satisfy the following
// conditions:
// The objects must have a default constructor
// The objects must have a copy assignment
// The objects must define the == operator
// The objects must define the < operator 
// Invariants: None
template <typename T>
class MSArray
{
	public:

	using size_type = std::size_t;
	using value_type = T;

	private:

	value_type* _array = nullptr;
	size_type _size = 0;

	// Sets _size to size and allocates sufficient memory
	// to store an array of the given value_type with the
	// given amount of elements.
	void alloc(const size_type& size)
	{
		_size = size;
		_array = new value_type[_size];
	}

	// Sets _size to 0 and frees the allocated memory
	// before setting the pointer to nullptr.
	void dealloc() noexcept
	{
		_size = 0;
		delete[] _array;
		_array = nullptr;
	}

	// Calls std::swap to swap the _array pointer and
	// _size value of this MSArray and the given MSArray.
	void mswap(MSArray& other) noexcept
	{
		std::swap(_array, other._array);
		std::swap(_size, other._size);
	}

	public:

	// Creates 8 elements of the given value_type.
	MSArray()
	{
		alloc(8);
	}

	// Creates size elements of the given value_type.
	MSArray(const size_type& size)
	{
		alloc(size);
	}

	// Creates size elements of the given value_type and sets each
	// element to t.
	MSArray(const size_type& size, const value_type& t)
	{
		alloc(size);

		for (size_type i = 0; i < _size; ++i)
			_array[i] = t;
	}

	// Creates a copy of the passed MSArray.
	MSArray(const MSArray& arr)
	{
		alloc(arr.size());

		for (size_type i = 0; i < _size; ++i)
			_array[i] = arr[i];
	}

	// Moves the passed MSArray to this MSArray.
	MSArray(MSArray&& arr) noexcept
	{
		_array = arr._array;
		_size = arr._size;
		arr._array = nullptr;
	}

	// Turns this MSArray into a copy of the passed MSArray.
	MSArray& operator = (const MSArray& arr)
	{
		dealloc();
		MSArray copy(arr);
		mswap(copy);
		return *this;
	}

	// Moves the passed MSArray to this MSArray.
	MSArray& operator = (MSArray&& arr) noexcept
	{
		mswap(arr);
		return *this;
	}

	// Destructor. Calls dealloc.
	~MSArray()
	{
		dealloc();
	}

	// Returns _size.
	size_type size() const
	{
		return _size;
	}

	// Returns a pointer to the first element of the MSArray.
	value_type* begin()
	{
		return _array;
	}

	// Returns a const pointer to the first element of the MSArray.
	const value_type* begin() const
	{
		return (const value_type*)(_array);
	}

	// Returns a pointer to 1 past the last element of the MSArray.
	value_type* end()
	{
		return _array + _size;
	}
	
	// Returns a const pointer to 1 past the last element of the MSArray.
	const value_type* end() const
	{
		return (const value_type*)(_array + _size);
	}

	// Returns a reference to the element specified by index.
	// Preconditions: 0 <= index < _size
	value_type& operator [] (const size_type& index)
	{
		return _array[index];
	}

	// Returns a const reference to the element specified by index.
	// Preconditions: 0 <= index < _size
	const value_type& operator [] (const size_type& index) const
	{
		return _array[index];
	}
};

// Returns true if every element of each MSArray is equal.
template <typename T>
bool operator == (const MSArray<T>& arr1, const MSArray<T>& arr2)
{
	if (arr1.size() != arr2.size())
		return false;

	for (std::size_t i = 0; i < arr1.size(); ++i)
	{
		if (arr1[i] == arr2[i])
			continue;
		else
			return false;
	}

	return true;
}

// Returns true if at least 1 element of the given MSArrays are different.
template <typename T>
bool operator != (const MSArray<T>& arr1, const MSArray<T>& arr2)
{
	if (arr1.size() != arr2.size())
		return true;

	return !( arr1 == arr2 );
}

// Returns true if at least 1 element of this MSArray is less than
// the corresponding element of the passed MSArray.
template <typename T>
bool operator < (const MSArray<T>& arr1, const MSArray<T>& arr2)
{
	return std::lexicographical_compare(arr1.begin(), arr1.end(), arr2.begin(), arr2.end());
}

// Returns true if at least 1 element of this MSArray is greater than
// the corresponding element of the passed MSArray.
template <typename T>
bool operator > (const MSArray<T>& arr1, const MSArray<T>& arr2)
{
	return std::lexicographical_compare(arr2.begin(), arr2.end(), arr1.begin(), arr1.end());
}

// Returns true if at least 1 element of this MSArray is less than
// the corresponding element of the passed MSArray or if the 2 passed
// MSArrays are equal.
template <typename T>
bool operator <= (const MSArray<T>& arr1, const MSArray<T>& arr2)
{
	return (!std::lexicographical_compare(arr2.begin(), arr2.end(), arr1.begin(), arr1.end()));
}

// Returns true if at least 1 element of this MSArray is greater than
// the corresponding element of the passed MSArray or if the 2 passed
// MSArrays are equal.
template <typename T>
bool operator >= (const MSArray<T>& arr1, const MSArray<T>& arr2)
{
	return (!std::lexicographical_compare(arr1.begin(), arr1.end(), arr2.begin(), arr2.end()));
}

#endif // MSARRAY_H_INCLUDED