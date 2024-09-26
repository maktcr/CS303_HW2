#pragma once

template<typename Item_Type>
class Node {
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
