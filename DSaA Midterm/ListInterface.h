/*
* Linked List Template as seen on page 261-262 of the textbook
*/

#pragma once
#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template<class ItemType>
class ListInterface {
public:
	virtual bool isEmpty() const = 0;
	virtual int getLength() const = 0;
	virtual bool insert(int newPos, const ItemType& newEntry) = 0;
	virtual bool remove(int pos) = 0;
	virtual void clear() = 0;
	virtual ItemType getEntry(int pos) const = 0;
	virtual void setEntry(int pos, const ItemType& newEntry) = 0;
};
#endif