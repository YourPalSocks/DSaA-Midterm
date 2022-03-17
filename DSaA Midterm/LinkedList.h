/*
* As seen on page 273
* No comments since this is lifted directly from the textbook
*/

#pragma once
#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include <string>
template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;
	Node<ItemType>* getNodeAt(int pos) const;
public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPos, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int pos) const throw(PrecondViolationExcep);
	void setEntry(int pos, const ItemType& newEntry)
		throw(PrecondViolationExcep);
};
#endif // !_LINKED_LIST
template class LinkedList<int>;
template class LinkedList<string>;
