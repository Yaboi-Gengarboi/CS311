// Project6 Linked List
// dp6.h
// Justyn Durnford
// Created on 2020-10-30
// Last updated on 2020-11-05
// Header file for Project 6.

#include "llnode2.h"

#include <cstddef>
#include <functional>
#include <memory>
#include <stdexcept>
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

			while (ptr != nullptr && ptr->_data.first != key)
			{
				ptr = ptr->_next.get();

				if (ptr->_data.first == key)
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

			while (ptr != nullptr && ptr->_data.first != key)
			{
				ptr = ptr->_next.get();

				if (ptr->_data.first == key)
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
			std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>>* current = &_head;
			std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>>* last = nullptr;

			std::pair<KeyType, ValType> new_pair(key, value);
			std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>> null_node = nullptr;
			std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>> new_node = std::make_unique<LLNode2<std::pair<KeyType, ValType>>>(new_pair, null_node);

			if (empty())
			{
				_head = std::move(new_node);
				return;
			}
			else if ((*current)->_data.first > key)
			{
				std::swap(_head, new_node);
				new_node->_next = std::move(_head);
				return;
			}

			while (*current != nullptr && (*current)->_data.first < key)
			{
				last = current;
				current = &((*current)->_next);

				if (*current == nullptr)
				{
					*current = std::move(new_node);
					return;
				}
				else if ((*current)->_data.first == key)
				{
					(*current)->_data.second = value;
					return;
				}
				else if ((*current)->_data.first > key)
				{
					new_node->_next = std::move(*current);
					(*last)->_next = std::move(new_node);
					return;
				}
			}
		}
		catch (...) { throw; }
	}

	void erase(const KeyType& key)
	{
		try
		{
			std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>>* current = &_head;
			std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>>* next = nullptr;
			std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>>* last = nullptr;

			if (empty())
			{
				throw std::out_of_range("Attempted to erase an item of an empty list.");
				return;
			}
			else if (_head->_data.first == key)
			{
				_head.reset();
				return;
			}
			
			while ((*current)->_next != nullptr)
			{
				last = current;
				current = &((*current)->_next);

				if ((*current)->_data.first == key)
				{
					if ((*current)->_next == nullptr)
					{
						current->reset();
					}
					else
					{
						next = &((*current)->_next);
						current->release();
						(*last)->_next = std::move(*next);
					}

					return;
				}
			}
		}
		catch (...) { throw; }
	}

	void traverse(std::function<void(KeyType, ValType)> fn)
	{
		try
		{
			if (empty())
				return;

			std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>>* current = &_head;

			fn(_head->_data.first, _head->_data.second);

			while ((*current)->_next != nullptr)
			{
				current = &((*current)->_next );
				fn((*current)->_data.first, (*current)->_data.second);
			}
		}
		catch (...) { throw; }
	}
};