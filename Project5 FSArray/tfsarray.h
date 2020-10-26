// Project5 FSArray
// tfsarray.h
// Justyn Durnford
// Created on 2020-10-08
// Last updated on 2020-10-26
// Header file for FSArray template class.

#ifndef TFSARRAY_H_INCLUDED
#define TFSARRAY_H_INCLUDED

#include <algorithm>
#include <cstddef>
#include <stdexcept>

// -Template parameters:
//
// -Invariants:
//  #1: _array points to an array that contains at least _size elements, 
//      unless _size is 0, in which case _array may be nullptr
//  #2: 0 <= _size <= _capacity
template <typename T>
class TFSArray
{
	public:

	// value_type: type of data.
	using value_type = T;

	// size_type: type of sizes and indices.
	using size_type = std::size_t;

	// iterator, const_iterator: random-access iterator types.
	using iterator = value_type*;
	using const_iterator = const value_type*;

	// reference, const_reference: reference types.
	using reference = value_type&;
	using const_reference = const value_type&;

	private:

	value_type* _array = nullptr;
	size_type _size = 0;
	size_type _capacity = 0;

	// Sets _size to size and allocates sufficient memory
	// to store an array of the given value_type with the
	// given amount of elements.
	// Strong Garuntee: If the function throws an exception, the state
	// of the program is rolled back to the state just before the 
	// function call.
	// This function is exception neutral.
	void allocate(size_type size)
	{
		_size = size;
		
		// Normally _capacity should be twice as large as _size,
		// but if _size is over half the maximum size of std::size_t,
		// then _capacity is simply set to the maximum size to prevent
		// arithmetic overflow.
		if (_size >= ((size_type) - 1) / 2)
			_capacity = (size_type) -1 ;
		else
			_capacity = _size * 2;

		try
		{
			// Attempt to allocate memory for the new array.
			_array = new value_type[_capacity];
		}
		catch (...)
		{
			// Reset the data if allocation fails.
			deallocate();
		}
	}

	// Sets _size and _capacity to 0 and frees the allocated memory.
	// Nothrow guarantee. This function will never throw.
	void deallocate() noexcept
	{
		_size = 0;
		_capacity = 0;
		delete[] _array;
	}

	//
	// -Preconditions:
	//  
	void reallocate(size_type newsize)
	{
		
	}

	// Copies the elements of the other TFSArray to this TFSArray,
	// including each element in the range [begin, end) to the
	// index specified by dest.
	// -Preconditions:
	//  #1: other._array != nullptr
	//  #2: begin < end <= other._size
	//  #3: dest + (end - begin) <= _size
	// Nothrow guarantee. This function will never throw.
	void copy(const TFSArray& other, size_type begin, size_type end, size_type dest) noexcept
	{
		for (size_type i = begin; i < end; ++i)
			_array[dest + i] = other[i];
	}

	// Moves the data from other to this TFSArray, along
	// with the values of _size and _capacity.
	// -Preconditions:
	//  #1: other is not an empty TFSArray.
	// Nothrow guarantee. This function will never throw.
	void move(TFSArray& other) noexcept
	{
		_array = other._array;
		_size = other._size;
		_capacity = other._capacity;
		other._array = nullptr;
	}

	public:

	// Default constructor AND 1-parameter constructor.
	// Creates size elements of the given value_type (size is 0 if
	// the TFSArray is constructed with no parameters).
	// Strong Garuntee: If the function throws an exception, the state
	// of the program is rolled back to the state just before the 
	// function call.
	explicit TFSArray(size_type size = 0)
	{
		allocate(size);
	}

	// Copy constructor.
	// Creates a copy of the passed TFSArray.
	// Strong Garuntee: If the function throws an exception, the state
	// of the program is rolled back to the state just before the 
	// function call.
	TFSArray(const TFSArray& other)
	{
		allocate(other._size);

		copy(other, 0, other._size, _array);
	}

	// Move constructor.
	// Moves the passed FSArray to this TFSArray.
	// Nothrow guarantee. This function will never throw.
	TFSArray(TFSArray&& other) noexcept
	{
		move(other);
	}

	// 2-parameter constructor.
	// Creates size elements of the given value_type and sets each
	// element to t.
	// Strong Garuntee: If the function throws an exception, the state
	// of the program is rolled back to the state just before the 
	// function call.
	// This function is exception neutral.
	TFSArray(size_type size, const value_type& value)
	{
		allocate(size);

		for (size_type i = 0; i < _size; ++i)
			_array[i] = value;
	}

	// Copy assignment operator.
	// Turns this FSArray into a copy of the passed TFSArray.
	// Strong Garuntee: If the function throws an exception, the state
	// of the program is rolled back to the state just before the 
	// function call.
	// This function is exception neutral.
	TFSArray& operator = (const TFSArray& other)
	{
		try
		{
			// Attempt to create a copy of the other TFSArray.
			// If this successful, move the copy to this TFSArray.
			TFSArray copy(other);
			move(copy);
		}
		catch (...)
		{
			// If this fails, keep the current TFSArray.
			throw;
		}

		return *this;
	}

	// Moves the passed TFSArray to this TFSArray.
	// Nothrow guarantee. This function will never throw.
	TFSArray& operator = (TFSArray&& other) noexcept
	{
		deallocate();
		move(other);

		return *this;
	}

	// Destructor.
	// Frees allocated memory.
	// Nothrow guarantee. This function will never throw.
	~TFSArray() noexcept
	{
		deallocate();
	}

	// Returns _size.
	// Nothrow guarantee. This function will never throw.
	size_type size() const noexcept
	{
		return _size;
	}

	// Returns _capacity.
	// Nothrow guarantee. This function will never throw.
	size_type capacity() const noexcept
	{
		return _capacity;
	}

	// Returns true if _size == 0.
	// Nothrow guarantee. This function will never throw.
	bool empty() const noexcept
	{
		return _size == 0;
	}

	// Returns a pointer to the first element of the TFSArray.
	// This will be a nullptr if the TFSArray has a size of 0.
	// Nothrow guarantee. This function will never throw.
	iterator begin() noexcept
	{
		return _array;
	}

	// Returns a const pointer to the first element of the TFSArray.
	// This will be a nullptr if the TFSArray has a size of 0.
	// Nothrow guarantee. This function will never throw.
	const_iterator begin() const noexcept
	{
		return (const_iterator*)(_array);
	}

	// Returns a pointer to 1 past the last element of the TFSArray.
	// This will be a nullptr if the TFSArray has a size of 0.
	// Nothrow guarantee. This function will never throw.
	iterator end()noexcept
	{
		if (empty())
			return nullptr;

		return begin() + size();
	}

	// Returns a const pointer to 1 past the last element of the TFSArray.
	// This will be a nullptr if the TFSArray has a size of 0.
	// Nothrow guarantee. This function will never throw.
	const_iterator end() const noexcept
	{
		if (empty())
			return nullptr;

		return const_iterator(begin() + size());
	}

	// Resizes and reallocates the TFSArray.
	void resize(const size_type& size)
	{
		if (size > _size)
		{
			if (size < _capacity)
				_size = size;
			else // size >= _capacity
			{

			}
		}
		else
		{

		}
	}

	//
	void insert()
	{

	}

	//
	void erase()
	{

	}

	//
	void push_back(const value_type& value)
	{

	}

	// Removes and destroys 
	void pop_back()
	{

	}

	// Swaps the values of this TFSArray and the passed TFSArray.
	// Nothrow guarantee. This function will never throw.
	void swap(TFSArray& other) noexcept
	{
		std::swap(*this, other);
	}

	// Returns a reference to the element specified by index.
	// This member function DOES NOT perform bounds-checking.
	// -Preconditions:
	//  #1: _array != nullptr
	//  #2: index is a valid index for the TFSArray (index < _size).
	// If the TFSArray is not empty, this function will never throw.
	// Otherwise, it causes undefined behavior.
	reference operator [] (size_type index)
	{
		return _array[index];
	}

	// Returns a const reference to the element specified by index.
	// This member function DOES NOT perform bounds-checking.
	// -Preconditions:
	//  #1: _array != nullptr
	//  #2: index is a valid index for the TFSArray (index < _size).
	// If the TFSArray is not empty, this function will never throw.
	// Otherwise, it causes undefined behavior.
	const_reference operator [] (size_type index) const
	{
		return _array[index];
	}

	// Returns a reference to the element specified by index.
	// This member function DOES perform bounds-checking, and
	// it will throw a std::out_of_range error if an invalid
	// index is passed.
	// Basic Garuntee: If the function throws an exception, 
	// the program is in a valid state.
	reference at(size_type index)
	{
		if (index < 0 || index >= size)
			throw std::out_of_range("Attempted to access an invalid index of the array.");

		return _array[index];
	}

	// Returns a const reference to the element specified by index.
	// This member function DOES perform bounds-checking, and
	// it will throw a std::out_of_range error if an invalid
	// index is passed.
	// Basic Garuntee: If the function throws an exception, 
	// the program is in a valid state.
	const_reference at(size_type index) const
	{
		if (index < 0 || index >= size)
			throw std::out_of_range("Attempted to access an invalid index of the array.");

		return _array[index];
	}
};

#endif // TFSARRAY_H_INCLUDED