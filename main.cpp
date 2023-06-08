#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void mainMenu(LinkedList&);
bool firstUse();

int main() {
	fstream listFile;
	string fileName, transfer;
	fstream dir("directory.txt", ios::in | ios::out | ios::app);
	if (firstUse())
	{
		cout << "DISPLAY: TO DO LIST INTRODUCTION" << endl;
		cout << "Enter a file name for your to do list (ex: todolist.txt): ";
		cin >> fileName;
		dir << fileName << endl;
		dir.close();
	}
	else
	{
		while (getline(dir, transfer))
			cout << transfer << endl;
		cout << "Enter the file name for your \nlist or enter a name for a new list (include .txt at the end): ";
		cin >> fileName;
		dir << fileName << endl;
		dir.close();
	}

	listFile.open(fileName, ios::in);
	
	LinkedList list;

	while (getline(listFile, transfer))
		list.appendNode(transfer);
	listFile.close();

	mainMenu(list);

	list.writeToFile(fileName);

	return 0;
}

void mainMenu(LinkedList& list) {
	int choice = 0;
	string content;
	char ch;
	int listLen;
	list.displayList();
	cout << endl;
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
		cout << "\n\n*****************\n - Remove Item - \n";
		listLen = list.displayList();
		if (listLen)
		{
			cout << "\nEnter list item number to be removed: ";
			cin >> choice;										
			list.deleteNode(choice);
		}
		else
			cout << "No items to delete!" << endl;
		mainMenu(list);
		break;
	}
	case 3: {
		cout << endl;
		mainMenu(list);
		break;
	}
	case 9: {
		cout << "Are you sure you wish to exit? (Y/N): ";
		cin >> ch;
		if (toupper(ch) == 'Y') {
			cout << "Exiting program ";
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

bool firstUse()
{
	ifstream checkFile("usedBeforeTrue.txt");
	if (checkFile.good())	//This means the program has been ran before
	{
		checkFile.close();
		return false;
	}
	else					//This means this is first use
	{
		ofstream placeFile("usedBeforeTrue.txt");
		placeFile.close();
		return true;
	}
}

/* To Do
	Add option to use other file names (allow user to enter file name)(this enables multiple lists)
*/
