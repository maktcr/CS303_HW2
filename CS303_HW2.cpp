#include "Single_Linked_List.h"


int main()
{
    //Single_Linked_List test
    Single_Linked_List<int> list;
    string input;
    list.push_back(10);
    list.push_back(11);
    list.push_back(5);
    cout << list.pop_back() << " was removed from the end" << endl;
    cout << list.pop_front() << " was removed from the front" << endl;
    cout << "Enter a number to locate: ";
    cin >> input;
    cout << "Number was found at index " << list.find(stoi(input));



    //Q2::Write a C++ program to implement a stack of integers using a vector with push and pop operations.

}



