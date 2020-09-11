// Project2 MSArray
// msarray.h
// Justyn Durnford
// Created on 2020-09-09
// Last updated on 2020-09-11
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

#ifndef MSARRAY_H
#define MSARRAY_H

#include <cstddef>

template <typename T>
class MSArray
{
	T* _array = nullptr;
	std::size_t _size = 0;

	void alloc(const std::size_t& size)
	{
		_size = size;
		_array = new T[_size];
	}

	public:

	MSArray()
	{
		alloc(8);
	}

	MSArray(const std::size_t& size)
	{
		alloc(size);
	}

	MSArray(const std::size_t& size, const T& t)
	{
		alloc(size);

		for (std::size_t i = 0; i < _size; ++i)
			_array[i] = t;
	}

	MSArray(const MSArray& arr)
	{
		alloc(arr.size());

		for (std::size_t i = 0; i < _size; ++i)
			_array[i] = arr[i];
	}

	MSArray(MSArray&& arr)
	{

	}

	~MSArray()
	{
		delete[] _array;
		_array = nullptr;
	}

	std::size_t size() const
	{
		return _size;
	}

	T& operator [] (const std::size_t& index)
	{
		return &_array[index];
	}
};

#endif // MSARRAY_H