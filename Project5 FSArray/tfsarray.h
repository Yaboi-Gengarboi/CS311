// Project5 FSArray
// tfsarray.h
// Justyn Durnford
// Created on 2020-10-08
// Last updated on 2020-10-29
// Header file for FSArray template class.

#ifndef TFSARRAY_H_INCLUDED
#define TFSARRAY_H_INCLUDED

#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <utility>

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

	// Creates a new TFSArray of new_size and move it into this TFSArray
	// if succesful.
	// -Preconditions:
	//  #1: new_size > _size
	// Strong Garuntee: If the function throws an exception, the state
	// of the program is rolled back to the state just before the 
	// function call.
	// This function is exception neutral.
	void reallocate(size_type new_size)
	{
		try
		{
			// Attempt to create a new TFSArray of new_size.
			// If this succeeds, copy every element of the this TFSArray
			// into the new TFSArray up until the end of this TFSArray.
			// Then, move the new TFSArray into this TFSArray.
			TFSArray new_arr(new_size);
			new_arr.index_copy(*this, 0, _size, 0);
			*this = std::move(new_arr);
		}
		catch (...)
		{
			// If this fails, keep the current TFSArray.
			throw;
		}
	}

	// Copies each element of the other TFSArray in the range [begin, end)
	// into this TFSArray, starting at index dest.
	// Basic Garuntee: If the function throws an exception, the program is 
	// in a valid state. No resources are leaked, and all objects' invariants 
	// are intact.
	// This function is exception neutral.
	void index_copy(const TFSArray& other, size_type begin, size_type end, size_type dest)
	{
		try
		{
			for (size_type i = begin; i < end; ++i)
				_array[i + dest] = other._array[i];
		}
		catch (...)
		{
			deallocate();
			throw;
		}
	}

	// Deallocates the TFSArray and moves the other TFSArray into this
	// TFSArray.
	// No-throw guarantee. This function will never throw.
	void move_from(TFSArray& other) noexcept
	{
		deallocate();
		
		_size = other._size;
		_capacity = other._capacity;
		_array = other._array;

		other._size = 0;
		other._capacity = 0;
		other._array = nullptr;
	}

	// Moves every element of the TFSArray in the range [begin, end]
	// forward by 1 index. 
	// Basic Garuntee: If the function throws an exception, the program is 
	// in a valid state. No resources are leaked, and all objects' invariants 
	// are intact.
	// This function is exception neutral.
	void move_forward(size_type begin, size_type end)
	{
		try
		{
			value_type tmp = _array[begin];

			for (size_type i = end - 1; i > begin; --i)
				_array[i + 1] = _array[i];

			_array[begin + 1] = tmp;
		}
		catch (...)
		{
			deallocate();
			throw;
		}
	}

	// Moves every element of the TFSArray in the range [begin, end]
	// backward by 1 index. 
	// Basic Garuntee: If the function throws an exception, the program is 
	// in a valid state. No resources are leaked, and all objects' invariants 
	// are intact.
	// This function is exception neutral.
	void move_back(size_type begin, size_type end)
	{
		try
		{
			value_type tmp = _array[end];

			for (size_type i = begin; i < end; ++i)
				_array[i] = _array[i + 1];

			_array[end - 1] = tmp;
		}
		catch (...)
		{
			deallocate();
			throw;
		}
	}

	public:

	// Default constructor AND 1-parameter constructor.
	// Creates size elements of the given value_type (size is 0 if
	// the TFSArray is constructed with no parameters).
	// Strong Garuntee: If the function throws an exception, the state
	// of the program is rolled back to the state just before the 
	// function call.
	// This function is exception neutral.
	explicit TFSArray(size_type size = 0)
	{
		allocate(size);
	}

	// Copy constructor.
	// Creates a copy of the passed TFSArray.
	// Strong Garuntee: If the function throws an exception, the state
	// of the program is rolled back to the state just before the 
	// function call.
	// This function is exception neutral.
	TFSArray(const TFSArray& other)
	{
		allocate(other._size);
		index_copy(other, 0, other._size, 0);
	}

	// Move constructor.
	// Moves the passed FSArray to this TFSArray.
	// No-throw guarantee. This function will never throw.
	TFSArray(TFSArray&& other) noexcept
	{
		move_from(other);
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
	// Basic Garuntee: If the function throws an exception, 
	// the program is in a valid state.
	// This function is exception neutral.
	TFSArray& operator = (const TFSArray& other)
	{
		try
		{
			deallocate();
			allocate(other._size);
			index_copy(other, 0, other._size, 0);
		}
		catch (...)
		{
			// If this fails, keep the current TFSArray.
			throw;
		}

		return *this;
	}

	// Moves the passed TFSArray to this TFSArray.
	// No-throw guarantee. This function will never throw.
	TFSArray& operator = (TFSArray&& other) noexcept
	{
		move_from(other);
		return *this;
	}

	// Destructor.
	// Frees allocated memory.
	// No-throw guarantee. This function will never throw.
	~TFSArray() noexcept
	{
		deallocate();
	}

	// Returns _size.
	// No-throw guarantee. This function will never throw.
	size_type size() const noexcept
	{
		return _size;
	}

	// Returns _capacity.
	// No-throw guarantee. This function will never throw.
	size_type capacity() const noexcept
	{
		return _capacity;
	}

	// Returns true if _size == 0.
	// No-throw guarantee. This function will never throw.
	bool empty() const noexcept
	{
		return _size == 0;
	}

	// Returns a pointer to the first element of the TFSArray.
	// This will be a nullptr if the TFSArray has a size of 0.
	// No-throw guarantee. This function will never throw.
	iterator begin() noexcept
	{
		if (empty())
			return nullptr;

		return _array;
	}

	// Returns a const pointer to the first element of the TFSArray.
	// This will be a nullptr if the TFSArray has a size of 0.
	// No-throw guarantee. This function will never throw.
	const_iterator begin() const noexcept
	{
		if (empty())
			return nullptr;

		return (const_iterator)(_array);
	}

	// Returns a pointer to 1 past the last element of the TFSArray.
	// This will be a nullptr if the TFSArray has a size of 0.
	// No-throw guarantee. This function will never throw.
	iterator end()noexcept
	{
		if (empty())
			return nullptr;

		return begin() + size();
	}

	// Returns a const pointer to 1 past the last element of the TFSArray.
	// This will be a nullptr if the TFSArray has a size of 0.
	// No-throw guarantee. This function will never throw.
	const_iterator end() const noexcept
	{
		if (empty())
			return nullptr;

		return const_iterator(begin() + size());
	}

	// Resizes and reallocates the TFSArray.
	// Strong Garuntee: If the function throws an exception, the state
	// of the program is rolled back to the state just before the 
	// function call.
	// This function is exception neutral.
	void resize(const size_type& new_size)
	{
		if (new_size > _capacity)
			reallocate(new_size);
		else // new_size <= _capacity
			_size = new_size;
	}

	// Inserts the passed element value at the position given by pos.
	// If the TFSArray is not at maximum capacity, this function will
	// never throw.
	// Otherwise, if an exception is thrown, the state
	// of the program is rolled back to the state just before the 
	// function call.
	// This function is exception neutral.
	iterator insert(iterator pos, const value_type& value)
	{
		iterator itr = nullptr;

		if (_size == _capacity) // Need to reallocate.
		{
			try
			{
				TFSArray new_arr(_size + 1);
				
				if (pos == begin())
				{
					new_arr._array[0] = value;
					new_arr.index_copy(*this, 0, _size, 1);
					move_from(new_arr);
					itr = begin();
				}
				else if (pos == end())
				{
					new_arr.index_copy(*this, 0, _size, 0);
					new_arr._array[_size] = value;
					move_from(new_arr);
					itr = end() - 1;
				}
				else
				{
					size_type index = std::distance(begin(), pos);
					new_arr.index_copy(*this, 0, index, 0);
					new_arr[index] = value;
					new_arr.index_copy(*this, index + 1, _size, index + 1);
					move_from(new_arr);
					itr = begin() + index;
				}
				
			}
			catch (...)
			{
				throw;
			}
		}
		else // Don't need to reallocate, but we have to rearrange the elements.
		{
			if (pos == begin())
			{
				++_size;

				move_forward(0, _size);
				_array[0] = value;

				itr = begin();
			}
			else if (pos == end())
			{
				++_size;
				_array[_size - 1] = value;
				itr = end() - 1;
			}
			else
			{
				++_size;
				size_type index = std::distance(begin(), pos);

				move_forward(index, _size);
				_array[index] = value;

				itr = pos;
			}
		}

		return itr;
	}

	// Removes the element at pos of the TFSArray.
	// -Preconditions:
	//  #1: _array != nullptr.
	//  #2: pos is a valid iterator for the container.
	// If the preconditions are met, this function will never throw.
	// Otherwise, it causes undefined behavior.
	iterator erase(iterator pos)
	{
		iterator itr = nullptr;

		if (pos == begin())
		{
			move_back(0, _size);
			--_size;
			itr = begin();
		}
		else if (pos == end())
		{
			--_size;
			itr = end() - 1;
		}
		else
		{
			move_back(std::distance(begin(), pos), _size);
			--_size;
			itr = pos;
		}

		return itr;
	}

	// Adds the element at the end of the TFSArray.
	// If the capacity of the TFSArray is sufficient, this function
	// will never throw.
	// Otherwise, if an exception is thrown, the state
	// of the program is rolled back to the state just before the 
	// function call.
	// This function is exception neutral.
	void push_back(const value_type& value)
	{
		if (_array == nullptr)
			allocate(1);

		if (_size < _capacity)
		{
			++_size;
			_array[_size - 1] = value;
		}
		else // _size == _capacity
		{
			size_type index = _size;
			reallocate(_size + 1);
			_array[index] = value;
		}
	}

	// Removes the last element of the TFSArray, reducing _size by 1.
	// -Preconditions: 
	//  #1: _size != 0
	// If the preconditions are met, this function will never throw.
	// Otherwise, it causes undefined behavior.
	void pop_back()
	{
		--_size;
	}

	// Swaps the values of this TFSArray and the passed TFSArray.
	// No-throw guarantee. This function will never throw.
	void swap(TFSArray& other) noexcept
	{
		std::swap(*this, other);
	}

	// Returns a reference to the element specified by index.
	// This member function DOES NOT perform bounds-checking.
	// -Preconditions:
	//  #1: _array != nullptr
	//  #2: index is a valid index for the TFSArray (index < _size).
	// If the preconditions are met, this function will never throw.
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
	// If the preconditions are met, this function will never throw.
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