// Project6 Linked List
// dp6.h
// Justyn Durnford
// Created on 2020-10-30
// Last updated on 2020-11-02
// Header file for Project 6.

#include "llnode2.h"

#include <cstddef>
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
	std::unique_ptr<LLNode2<std::pair<KeyType, ValType>>> _dataset = nullptr;

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

	std::size_t size() const
	{
		std::size_t size = 0;

		return size;
	}

	bool empty() const
	{
		if (_dataset)
			return true;

		return false;
	}


};