// Project2 MSArray
// msarray.h
// Justyn Durnford
// Created on 2020-09-09
// Last updated on 2020-09-14
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
// of the public at largeand to the detriment of our heirsand
// successors.We intend this dedication to be an overt act of
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

template <typename T>
class MSArray
{
	public:

	using size_type = std::size_t;
	using value_type = T;

	private:

	value_type* _array = nullptr;
	size_type _size = 0;

	void alloc(const size_type& size)
	{
		_size = size;
		_array = new value_type[_size];
	}

	void dealloc()
	{
		delete[] _array;
		_array = nullptr;
	}

	public:

	explicit MSArray()
	{
		alloc(8);
	}

	explicit MSArray(const size_type& size)
	{
		alloc(size);
	}

	explicit MSArray(const size_type& size, const value_type& t)
	{
		alloc(size);

		for (size_type i = 0; i < _size; ++i)
			_array[i] = t;
	}

	explicit MSArray(const MSArray& arr)
	{
		alloc(arr.size());

		for (size_type i = 0; i < _size; ++i)
			_array[i] = arr[i];
	}

	explicit MSArray(MSArray&& arr) noexcept
	{
		_array = arr._array;
		arr._array = nullptr;
	}

	MSArray& operator = (const MSArray& arr)
	{
		dealloc();
		alloc(arr.size());

		for (size_type i = 0; i < _size; ++i)
			_array[i] = arr[i];

		return *this;
	}

	MSArray& operator = (MSArray&& arr) noexcept
	{
		dealloc();
		_array = arr._array;
		arr._array = nullptr;
		return *this;
	}

	~MSArray()
	{
		dealloc();
	}

	size_type size() const
	{
		return _size;
	}

	value_type* begin() const
	{
		return _array;
	}

	value_type* end() const
	{
		return _array + _size;
	}

	value_type& operator [] (const size_type& index)
	{
		return _array[index];
	}

	const value_type& operator [] (const size_type& index) const
	{
		return _array[index];
	}

	bool operator == (const MSArray& arr)
	{
		// Whoever developed std::equal, thank you so much
		return std::equal(begin(), end(), arr.begin(), arr.end());
	}

	bool operator != (const MSArray& arr)
	{
		return !( *this == arr );
	}

	bool operator < (const MSArray& arr)
	{
		if (*this == arr)
			return false;
		if (_size < arr._size)
			return true;

		for (std::size_t i = 0; i < _size; ++i)
		{
			if (_array[i] < arr[i])
				return true;
		}

		return false;
	}

	bool operator > (const MSArray& arr)
	{
		if (*this == arr)
			return false;
		if (_size > arr._size)
			return true;

		return !( *this < arr );
	}

	bool operator <= (const MSArray& arr)
	{
		if (*this == arr)
			return true;

		return ( *this < arr );
	}

	bool operator >= (const MSArray& arr)
	{
		if (*this == arr)
			return true;

		return ( *this > arr );
	}
};

#endif // MSARRAY_H_INCLUDED