#pragma once
// The node class for our linked list
template <typename T>
class node {
public:
	int count;
	T data;
	node<T>* next;
	node() : next(nullptr) {} // need it for default  constructor 
	node(const T& item, node<T>* ptr = nullptr) :   // Constructor need to take 2 arguments 
		data(item), next(ptr) {}
};