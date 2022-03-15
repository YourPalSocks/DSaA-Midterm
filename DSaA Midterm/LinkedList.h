/*
* As seen on page 273
*/

#pragma once
#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
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
	virtual ~LinkedList();

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
