#include "Single_Linked_List.h"
#include "Stack.h"

int main()
{
    //Single_Linked_List test
    Single_Linked_List<int> list;
    int input;
    int input2;

    //Load the linked list
    list.push_back(10);
    list.push_back(9);
    list.push_back(8);
    list.push_back(7);
    list.push_back(6);
    list.push_back(11);
    list.push_back(5);

    //test functions
    cout << list.pop_back() << " was removed from the end" << endl;     //pop functions
    cout << list.pop_front() << " was removed from the front" << endl;

    cout << "Enter a number to locate: ";       //find function
    cin >> input;
    cout << "Number was found at index " << list.find(input) << endl;   

    cout << "Enter the index of a number to remove: ";      //remove function
    cin >> input;
    if (list.remove(input)) {
        cout << "Removal of entity from index " << input << " was sucessful." << endl;  
    }
    else {
        cout << "Removal of entity from index " << input << " failed." << endl;
    }  

    cout << "Enter the index at which you want to insert the number: ";     //insert function 
    cin >> input;
    cout << "Enter the number you want to add: ";
    cin >> input2;
    list.insert(input, input2);

    cout << "Item at the front of the linked list is: " << list.front() << endl;    //front and back functions
    cout << "Item at the end of the linked list is: " << list.back() << endl;

    if (list.empty()) {                     //empty function
        cout << "List is empty" << endl;
    }
    else {
        cout << "List is not empty" << endl;
    }

    cout << endl << endl << endl << "--------------- QUESTION 2 ---------------" << endl << endl;

    //Q2::Write a C++ program to implement a stack of integers using a vector with push and pop operations.
    //Stack class is seperated into Stack.h and Stack.cpp
   
    Stack stack;
    //Check if stack is empty (should return true)
    if (stack.checkEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack is not empty" << endl;
    }

    //Load the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);

    cout << "1, 2, 3, 4, 5, and 6 were added to the stack." << endl;

    //Check if stack is empty again (should return false)
    if (stack.checkEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack is not empty" << endl;
    }

    //Find the top of the stack
    cout << "The element at the top of the stack is: " << stack.findTop() << endl;

    //Remove an element from the stack
    stack.pop();
    cout << "An element was removed from the stack" << endl;

    //Find the top of the stack
    cout << "The element at the top of the stack is: " << stack.findTop() << endl;

    //Find the average of the stack
    cout << "The average of all elements in the stack is: " << stack.findAverage() << endl;

}



