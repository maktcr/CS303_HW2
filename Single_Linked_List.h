#pragma once
#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <vector>
#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

template<typename Item_Type>
class Node {
public:
	Item_Type data;
	Node* next;

	Node(const Item_Type& item) : data(item), next(nullptr) {}
};



template<typename Item_Type>
class Single_Linked_List {
private:
	//Data members
	Node<Item_Type>* head;
	Node<Item_Type>* tail;
	size_t num_items;

public:
	Single_Linked_List();	//Constructor
	~Single_Linked_List();	//Destructor

	//Member functions
	void push_front(const Item_Type& item);
	void push_back(const Item_Type& item);
	Item_Type pop_front();
	Item_Type pop_back();
	Item_Type front() const;
	Item_Type back() const;
	bool empty() const;
	void insert(size_t index, const Item_Type& item);
	bool remove(size_t index);
	size_t find(const Item_Type& item) const;

};


//Constructor
template<typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List()
	: head(nullptr), tail(nullptr), num_items(0) {}

//Destructor
template<typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
	while (!empty()) {
		pop_front();
	}
}

template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {

	Node* new_head = new Node(item);

	//If the linked list is empty, head and tail is set to new_head
	//else, set new_head next to the current head 
	if (empty()) {
		tail = new_head;
	}
	else {
		new_head->next = head;
	}
	//Now that new_head next is pointing to the old head,
	//set the head to new_head and incriment num_items.
	head = new_head;
	num_items++;
}

template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {

	Node<Item_Type>* new_tail = new Node<Item_Type>(item);

	//If the linked list is empty, head and tail is set to new_tail
	//else, set new_tail next to the current head 
	if (empty()) {
		head = new_tail;
	}
	else {
		tail->next = new_tail;
	}
	//Now that tail->next is set to the new tail (linking it to the list),
	//set the tail to new_tail and incriment num_items.
	tail = new_tail;
	num_items++;
}

template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::pop_front() {

	if (empty()) {
		//cannot pop from empty list
	}

	//Save head data to return it after its deleted.
	Item_Type item = head->data;

	//Node to be deleted.
	Node<Item_Type>* temp = head;

	//Set new head to the second item in the list, then delete the temp node.
	head = head->next;
	delete temp;

	//If list is now empty (head == nullptr), update the tail to nullptr.
	if (head == nullptr) {
		tail = nullptr;
	}

	//Decrement num_items and return the popped item.
	num_items--;
	return item;
}

template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::pop_back() {

	if (empty()) {
		cout << "List is empty" << endl;
	}

	//Save tail data to return it aftet its deleted.
	Item_Type item = tail->data;

	//If the head is the tail (there is only one entity in the list),
	//delete the head, and set both head and tail to nullptr.
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {

		//If the list has more than one entity, we need to find the node before the tail.
		//Since this is a single linked list, we have to iterate through the list in order to 
		//find the node before the tail.
		Node<Item_Type>* temp = head;
		//Iterate through List until temp->next is equal to tail.
		while (temp->next != tail) {
			temp = temp->next;
		}

		//Now that temp is the node before tail, delete the tail and set temp to the new tail,
		//Then set tail->next to nullptr.
		delete tail;
		tail = temp;
		tail->next = nullptr;
	}

	//Decriment num_items and return the popped item.
	num_items--;
	return item;
}

template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
	if (empty()) {
		cout << "List is empty" << endl;
	}
	return head->data;
}

template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
	if (empty()) {
		cout << "List is empty" << endl;
	}
	return tail->data;
}

template<typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {

	//If the list is empty, return true. If it isnt empty, return false.
	if (num_items == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {

	//If the given index is 0 or less, use the push_front function to add the item to the front.
	if (index <= 0) {
		push_front(item);
	}
	//If the given index is greater than or equal to the size of the list, use the push_back function
	//to add it to the end.
	else if (index >= num_items) {
		push_back(item);
	}
	//If the given index falls within the scope of the list, we must iterate through the list until we reach the node
	//before the given index.
	else {
		Node* new_node = new Node(item);	//item to be added
		Node* temp = head;
		for (size_t i = 0; i < index - 1; i++) {
			temp = temp->next;
		}

		//Now that temp is the node one index before the position we want to add a node,
		//link the temp node to the list by setting the new_node next to temp->next,
		//and then updated temp->next to reflect the change.
		new_node->next = temp->next;
		temp->next = new_node;
		num_items++;	//incriment num_items
	}
}

template<typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {

	//If given index is beyond the end of the list, return false.
	if (index < 0 || index >= num_items) {
		return false;
	}
	//If given index is at the front, use the pop_front function.
	if (index == 0) {
		pop_front();
	}
	else {
		//Iterate through the list until we reach the index before the one we want to remove.
		Node* temp = head;
		for (size_t i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		//Set node to_remove, if this node is the tail, set temp to be the new tail.
		Node* to_remove = temp->next;
		if (to_remove == tail) {
			tail = temp;
		}
		//Set temp->next to the next pointer of the item we are deleting, then delete the node and decriment num_items.
		temp->next = to_remove->next;
		delete to_remove;
		num_items--;
	}
	//Function was successful, return true.
	return true;
}

template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {

	//Use temp node to iterate through the list until item is found
	Node<Item_Type>* temp = head;
	size_t index = 0;	//Start at index 0
	while (temp != nullptr) {	//While temp (iterator) is not past the end of the list
		if (temp->data == item) {
			return index;	//Return position of the item when it is found
		}
		//Iterate
		temp = temp->next;
		index++;
	}
	return num_items; // Return size if not found
}


#endif