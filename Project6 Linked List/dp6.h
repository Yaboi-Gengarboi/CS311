// Project6 Linked List
// dp6.h
// Justyn Durnford
// Created on 2020-10-30
// Last updated on 2020-11-04
// Header file for Project 6.

#include "llnode2.h"

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>

// Reverses the order of the linked list given by the head node.
// ValType template requirements:
//  #1: ValType must have a copy constructor and a non-throwing destructor.
// No-throw Garuntee: This function will never throw.
template <typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>>& head) noexcept
{
	std::unique_ptr<LLNode2<ValType>> new_head = nullptr;

	while (head != nullptr)
	{
		std::swap(new_head, head->_next);
		std::swap(new_head, head);
	}

	std::swap(new_head, head);
}

//
template <typename KeyType, typename ValType>
class LLMap
{
	std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>> _head = nullptr;

	public:

	// Default constructor.
	LLMap() = default;

	// Copy constructor: Deleted.
	LLMap(const LLMap& other) = delete;

	// Move constructor: Deleted.
	LLMap(LLMap&& other) = delete;

	// Copy assignment: Deleted.
	LLMap& operator = (const LLMap& other) = delete;

	// Move assignment: Deleted.
	LLMap& operator = (LLMap&& other) = delete;

	// Destructor.
	~LLMap() = default;

	// Returns the size of the Linked List.
	// Strong Garuntee: The Linked List is left unchanged if an exception
	// is thrown (assuming it is caught).
	std::size_t size() const
	{
		try
		{
			std::size_t size = 0;
			LLNode2<std::pair<KeyType, ValType>>* ptr = _head.get();

			while (ptr != nullptr)
			{
				++size;
				ptr = ptr->_next;
			}

			return size;
		}
		catch (...) { throw; }

		return 0;
	}

	// Returns true if _dataset == nullptr.
	// No-throw Garuntee: This function will never throw.
	bool empty() const noexcept
	{
		if (_head == nullptr)
			return true;

		return false;
	}

	ValType* find(const KeyType& key)
	{
		try
		{
			LLNode2<std::pair<KeyType, ValType>>* ptr = _head.get();

			while (ptr != nullptr && ptr->_data != key)
			{
				ptr = ptr->_next;

				if (ptr->_data == key)
					return &( ptr->_data.second );
			}
		}
		catch (...) { throw; }

		return nullptr;
	}

	const ValType* find(const KeyType& key) const
	{
		try
		{
			LLNode2<std::pair<KeyType, ValType>>* ptr = _head.get();

			while (ptr != nullptr && ptr->_data != key)
			{
				ptr = ptr->_next;

				if (ptr->_data == key)
					return (const ValType*)&( ptr->_data.second );
			}
		}
		catch (...) { throw; }

		return nullptr;
	}

	void insert(const KeyType& key, const ValType& value)
	{
		try
		{
			LLNode2<std::pair<KeyType, ValType>>* ptr = _head.get();
			LLNode2<std::pair<KeyType, ValType>>* last = nullptr;
			std::pair<KeyType, ValType> new_pair(key, value);
			std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>> null_node = nullptr;
			std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>> new_node = std::make_unique<LLNode2<std::pair<KeyType, ValType>>>(new_pair, null_node);

			if (empty())
			{
				_head = new_node;
				return;
			}
			else if (ptr->_data.first > key)
			{
				std::swap(_head, new_node);
				new_node->_next = _head;
				return;
			}

			while (ptr != nullptr && ptr->_data.first < key)
			{
				last = ptr;
				ptr = ptr->_next.get();

				if (ptr == nullptr)
				{
					ptr = std::move(new_node);
					return;
				}
				

				if (ptr->_data == key)
					ptr->_data = value;
				else if (ptr->_data > key)
				{
					
				}
			}
		}
		catch (...) { throw; }
	}

	void erase(const KeyType& key)
	{
		try
		{

		}
		catch (...) { throw; }
	}

	/*template <typename T>
	void traverse(std::function<T> fn)
	{
		std::size_t s = size();

		for (std::size_t i = 0; i < s; ++i)
		{

		}
	}*/
};