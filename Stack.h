#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Stack {
private:
	vector<int> ints;

public:
	bool checkEmpty();
	void push(int value);
	void pop();
	int findTop();
	double findAverage();
};
