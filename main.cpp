#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void mainMenu(LinkedList);

int main() {
	fstream listFile;
	string fileName = "list.txt";
	listFile.open(fileName, ios::in | ios::out);
	LinkedList list;
	string transfer;

	while (getline(listFile, transfer))
		list.appendNode(transfer);
	listFile.close();

	mainMenu(list);

	list.writeToFile(fileName);
	
	return 0;
}

void mainMenu(LinkedList list) {
	int choice = 0;
	string content;
	char ch;

	cout << "Select an option: " << endl;
	cout << "1. Add Item\n2. Delete Item\n3. Display List\n9. Exit Program" << endl;
	cout << "Selection: ";
	cin >> choice;
	
	switch (choice) {
	case 1: {
		cin.ignore();
		cout << "Enter content of list item: ";
		getline(cin, content);
		list.appendNode(content);
		mainMenu(list);
		break;
	}
	case 2: {
		cout << "Enter list item number to be removed: ";
		cin >> choice;										//Find a way to validate input (may need to step through list and count number of nodes to verify)(very easy member function of LL class)
		list.deleteNode(choice);
		mainMenu(list);
		break;
	}
	case 3: {
		cout << endl;
		list.displayList();
		cout << endl;
		mainMenu(list);
		break;
	}
	case 9: {
		cout << "Are you sure you wish to exit? (Y/N): ";
		cin >> ch;
		if (toupper(ch) == 'Y') {
			cout << "Exiting program...";
		}
		else {
			cout << "Returning to program...";
			mainMenu(list);
		}
		break;
	}
	default: {
		cout << "*** ERROR: Invalid Item Chosen ***\n\nReturning to program...";
		mainMenu(list);
	}
		break;
	}
}

/* To Do
	Add check for correct item number (if it's in range)
	Add check for first use (use a file to tell or some sort of flag)
	Add option to use other file names (allow user to enter file name)(this enables multiple lists)
	Add verification (make sure file opens)
*/
