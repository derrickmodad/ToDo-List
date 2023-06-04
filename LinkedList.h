#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class LinkedList {
private:
	struct Node {
		string item;
		Node* nextNode = nullptr;
	};
	
	Node* head;

public:
	LinkedList();
	void appendNode(string);
	void deleteNode(int);
	void displayList();
	void writeToFile(string);
};

//Contructor
LinkedList::LinkedList() {
	head = nullptr;									//Make sure the node is initialized to null
}

//Append node
void LinkedList::appendNode(string content) {
	Node* currentNode = nullptr;					//This will be used to traverse list
	Node* newNode = new Node;						//This is the node being added to the list
	newNode->item = content;						//Load up the new node with content
	newNode->nextNode = nullptr;					//Prep the pointer

	if (!head)										//If there is no head (meaning that this is the first node)
		head = newNode;								//Make this node the head
	else											//Else
	{
		currentNode = head;							//Set currentNode to head for traversal
		while (currentNode->nextNode != nullptr)	//While we have a value at the next location
			currentNode = currentNode->nextNode;	//We need to step to the next location 
		currentNode->nextNode = newNode;			//Once we are at the end, let's point the current node to the new node
	}
}

//Delete node
void LinkedList::deleteNode(int num) {
	Node* currentNode = head;						//Start at the head
	Node* prevNode = nullptr;						//We'll need a variable to hold the last node so we can reroute pointers
	int counter = 1;								//We'll use a counter variable to keep track of how many nodes we've stepped through
	while (counter != num) {						//While counter is less than the item number we are deleting
		prevNode = currentNode;						//Set previous to the current node
		currentNode = currentNode->nextNode;		//Step to the next node
		counter++;									//Increment counter
	}
	if (prevNode == nullptr)						//If we are deleting the very first node
		head = currentNode->nextNode;				//We need to move the head to the next element
	else											//Else
		prevNode->nextNode = currentNode->nextNode;	//Reroute the pointers to go over the current node

	delete currentNode;								//Delete the current node
}

//Display List
void LinkedList::displayList() {
	Node* currentNode = head;
	int counter = 1;
	while (currentNode != nullptr)
	{
		cout << counter << ". " << currentNode->item << endl;
		currentNode = currentNode->nextNode;
		counter++;
	}
}

void LinkedList::writeToFile(string fileName)
{
	fstream outF(fileName, ios::out);
	Node* currentNode = head;
	while (currentNode != nullptr)
	{
		outF << currentNode->item << endl;
		currentNode = currentNode->nextNode;
	}
	outF.close();
}