#pragma once
#include "node.h"
// Linkedlist class
template <typename T>

class LinkedList {
public:
	LinkedList() {
		// Create the dummy head node
		head = tail = new node<T>();
	}

	// void that destroys the list 
	void destroyList() {
		node<T>* temp;

		while (head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
		count = 0;
	}
	// bool that searchs the item of the list
	bool search(const T& searchItem) const {
		node<T>* current;
		bool found = false;

		current = head;
		while (current != nullptr) {
			if (current->data == searchItem) {
				return true;
			}
			else {
				current = current->next;
			}
		}
		return false;
	}

	//copies the list, position by position
	void copyList(const LinkedList<T>& otherList) {
		node<T>* newNode;
		node<T>* current;

		//empty our list if it is not empty already
		if (head != nullptr) {
			destroyList();
		}
		// If the other list is empty so this one 
		if (otherList.head == nullptr) {
			head = tail = nullptr;
			count = 0;
		}
		//Copy the elements from the other list
		else {
			current = otherList.head;
			count = otherList.count;

			head = new node<T>;
			head->data = current->data;
			head->next = nullptr;

			tail = head;

			current = current->next;

			while (current != nullptr) {
				newNode = new node<T>;
				newNode->data = current->data;
				newNode->next = nullptr;

				tail->next = newNode;
				tail = newNode;

				current = current->next;
			}
		}
	}

	// Inner class iterator
	class iterator {
		friend class LinkedList;
	private:
		node<T>* nodePtr;
		// The constructor is private, so  it
		// can create instances of iterators.
		iterator(node<T>* newPtr) : nodePtr(newPtr) {}
	public:
		iterator() : nodePtr(nullptr) {}

		// Overload for the comparison operator !=
		bool operator!=(const iterator& itr) const {
			return nodePtr != itr.nodePtr;
		}

		// Overload for the dereference operator *
		T& operator*() const {
			return nodePtr->next->data;
		}

		// Overload for the postincrement operator ++
		iterator operator++(int) {
			iterator temp = *this;
			nodePtr = nodePtr->next;
			return temp;
		}
		// Overload for the equal operator ==
		iterator operator== (const iterator& itr) const{

			return nodePtr == itr.nodePtr; 
		}

	}; // End of inner class iterator

	//Start at the first element 
	iterator begin() const {
		return iterator(head);
	}
	//Start at the last element 
	iterator end() const {
		return iterator(tail);
	}

	iterator insert(iterator position, const T& value) {
		node<T>* newNode = new node<T>(value, position.nodePtr->next);
		if (position.nodePtr == tail) tail = newNode;
		position.nodePtr->next = newNode;
		return position;
	}

	iterator erase(iterator position) {
		node<T>* toDelete = position.nodePtr->next;
		position.nodePtr->next = position.nodePtr->next->next;
		if (toDelete == tail) tail = position.nodePtr;
		delete toDelete;
		return position;
	}

private:
	node<T>* head;
	node<T>* tail;
	int count;
};