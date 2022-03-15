/*
* Linked List Template as seen on page 261-262 of the textbook
*/

#pragma once
#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE
template<class ItemType>
class ListInterface {
public:
	bool isEmpty();
	int getLength();
	bool insert(int newPos, ItemType& newEntry);
	bool remove(int pos);
	void clear();
	ItemType getEntry(int pos);
	void setEntry(int pos, ItemType newEntry);
};


template class ListInterface<float>;
#endif