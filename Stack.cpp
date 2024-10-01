#include "Stack.h"


bool Stack::checkEmpty() {
	//use the vectors empty() function which returns true if the vector is empty
	return ints.empty();
}

void Stack::push(int value) {
	//use the vector's push_back function
	ints.push_back(value);
}

void Stack::pop() {

	//Check if stack is empty. If so, notify user
	if (checkEmpty()) {
		cout << "Pop failed, the stack is empty." << endl;
	}
	//Use vectors pop_back function
	ints.pop_back();
	

}

int Stack::findTop() {

	if (checkEmpty()) {
		cout << "Find Top failed, the stack is empty." << endl;
	}
	//Use the vectors back function to find the top
	//(since the top of a stack is the back of the vector)
	return ints.back();
	
}

double Stack::findAverage() {

	double sum = 0;

	if (checkEmpty()) {
		cout << "Find Average failed, the stack is empty." << endl;
	}
	for (int i : ints) {
		sum += i;
	}
	return sum / ints.size();
}