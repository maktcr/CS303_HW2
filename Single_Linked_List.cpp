#include "Single_Linked_List.h"
#include <iostream>
using namespace std;

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

	Node* new_tail = new Node(item);

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

	//Save head data to return it after its deleted
	Item_Type item = head->data;

	//Node to be deleted
	Node<Item_Type>* temp = head;

	//Set new head to the second item in the list, then delete the temp node
	head = head->next;
	delete temp;

	//If list is now empty (head == nullptr), update the tail to nullptr
	if (head == nullptr) {
		tail = nullptr;
	}

	//decrement num_items and return the popped item
	num_items--;
	return item;
}

template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::pop_back() {

	if (empty()) {
		cout << "List is empty" << endl;
	}

	//Save tail data to return it aftet its deleted
	Item_Type item = tail->data;

	//If the head is the tail (there is only one entity in the list)
	//Delete the head, and set both head and tail to nullptr
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {

		//If the list has more than one entity, we need to find the node before the tail.
		//Since this is a single linked list, we have to iterate through the list in order to 
		//find the node before the tail.
		Node* temp = head;
		//Iterate through List until temp->next is equal to tail
		while (temp->next != tail) {
			temp = temp->next;
		}

		//Now that temp is the node before tail, delete the tail and set temp to the new tail.
		//Then set tail->next to nullptr
		delete tail;
		tail = temp;
		tail->next = nullptr;
	}

	//Decriment num_items and return the popped item
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

	//If the list is empty, return true. If it isnt empty, return false
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
		//
		new_node->next = temp->next;
		temp->next = new_node;
		num_items++;
	}
}

template<typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {

}