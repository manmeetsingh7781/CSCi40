// Manmeet Singh
// This program creates a linked list connected to each other as a node which is the part of data structure

#include <iostream>
using namespace std;

// This data type represents the Node 
struct Node {
	char data;
	Node* next;
};

int main() { 
  int start;
	char letter;
  // Initilize the List
  Node *head = NULL;
  Node *currunt;

// Adding new Node
for(start = 1; start <= 26; start++){
     currunt = new Node();
     currunt->next = head;
     head = currunt;
 }
  // loop to add values in nodes
  currunt = head;
  letter = 'A';
	while(currunt != NULL) {
    currunt->data = letter;
    letter++;
   currunt = currunt->next;
	}
 // Loop to print 
	currunt = head;
	while(currunt != NULL) {
		cout << currunt->data << endl;
		currunt = currunt->next;
	}
	cout << endl;
  return 0;
}
