#ifndef LIST_H
#define LIST_H


//Node is fundamental structure in our linked list
typedef struct node {
  int data;
  struct node * next;
} Node;


//Remove first item (item closest to start of list)
//in a given list, if one exists.
//Return number of items removed (either 0 or 1).
int removeFirst(Node** listPtr);

//Remove last item (item closest to end of list)
//in given list, if one exists.
//Return number of items removed (either 0 or 1).
int removeLast(Node** listPtr);

//Remove earliest occurrence of given item in the list.
//Does not remove any occurrences after the first.
//Does not assume list is already sorted.
//Return number of items removed (either 0 or 1).
int removeFirstOccurrence(Node** listPtr, int value);

//Remove all occurrences of given value in the list.
//Does not assume list is already sorted.
//Return number of items removed (0, 1, or more).
int removeAllOccurrences(Node** listPtr, int value);


//Insert new data item at start of given list.
//
//Assumes listPtr holds address of head pointer
//for the list.  Variable listPtr may not
//be NULL, but the head pointer might be.
void insertAtHead(Node** listPtr, int data);


//Insert new data item at end of list.
//
//Assumes listPtr holds address of head pointer
//for the list.  Variable listPtr may not
//be NULL, but the head pointer might be.
void insertAtTail(Node** listPtr, int data);


//Insert new data item into list into sorted list.
//(ascending order) so that list remains sorted.
//
//Assumes listPtr holds address of head pointer
//for a SORTED list.  Variable listPtr may not
//be NULL, but the head pointer might be.
//
//The list is permitted to hold duplicate values.
void insertSorted(Node** listPtr, int data);


//Insert new data item into list into sorted list.
//(ascending order) so that list remains sorted,
//but refuses to insert duplicate values into list.
//Returns the number of items actually inserted.
//
//Assumes listPtr holds address of head pointer
//for a SORTED list.  Variable listPtr may not
//be NULL, but the head pointer might be.
//
//The list is NOT permitted to hold duplicate values.
int insertSortedNoDups(Node** listPtr, int data);


//Iteratively print the list contents in forward direction
void printList(Node* head);


#endif
