// Manmeet Singh
/*

This program creates a linked list of 26 nodes or more depending on user and then fill the list with the letters of the alphabet, and then prints the contents of the
linked list.

*/

#include <iostream>
using namespace std;

// Node Structure 
struct Node {

	char data;
	Node * Next;

};

// Linked List Structure so we can add Multiple nodes in One list instead of creating new Node every time
struct linkedList {
	Node *start, *currunt;

	// Constructor for setting up the list.. Run only once when object created
	linkedList() {
		start = new Node;
		currunt = start;
	}

	// function to add nodes into one List
	void addNode(char value) {
		currunt->Next = new Node;
		currunt = currunt->Next;
		currunt->data = value;
		currunt->Next = NULL;  
	}

	// Display all the nodes
	void displaynodes() {
		start = start->Next;
		 while(start != NULL){
		   cout << start->data << endl;
		   start = start -> Next;
		 }
	}

};

int main() {
	
	int starter, nodeLimit;
	
	nodeLimit = 26;
	char letter;
	// @ because next letter is A so when we start the loop the next letter will be A
	letter = '@';
	
	linkedList list;
	for (starter = 0; starter <= nodeLimit; starter++) {
		letter = letter + 1;
		list.addNode(letter);
	}
	list.displaynodes();

	return 0;
}