#include "LinkedList.h"
#include <assert.h>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int pos) const throw(PrecondViolationExcep)
{
	bool ableToGet = (pos >= 1) && (pos <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(pos);
		return nodePtr->getItem();
	}
	else
	{
		string message = "getEntry() called with an empty list or ";
		message += "invalid position.";
		throw(PrecondViolationExcep(message));
	}
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int pos) const
{
	assert((pos >= 1) && (pos <= itemCount));
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < pos; skip++)
		curPtr = curPtr->getNext();
	return curPtr;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPos, const ItemType& newEntry)
{
	bool ableToInsert = (newPos >= 1) && (newPos <= itemCount + 1);
	if (ableToInsert)
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		if (newPos == 1)
		{
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(newPos - 1);
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}
		itemCount++;
	}
	return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int pos)
{
	bool ableToRemove = (pos >= 1) && (pos <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (pos == 1)
		{
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(pos - 1);
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
		itemCount--;
	}
	return ableToRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
	{
		remove(1);
	}
}