#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	string item;
	Node* nextNode;
};

class LinkedList {
private:
	Node* head;

public:
	LinkedList();
	void appendNode(string);
	void deleteNode(int);
	int displayList();
	void writeToFile(string);
};
