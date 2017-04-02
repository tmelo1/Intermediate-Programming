#include <stdio.h>
#include <stdlib.h>
#include "list-ex-6-2.h"


//Insert new data item at start of given list
//
//Assumes listPtr holds address of head pointer
//for the list.  Variable listPtr may not
//be NULL, but the head pointer might be.
void insertAtHead(Node** listPtr, int data){

  //create new node and populate it
  Node * newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  //connect existing list to new node;
  //works even if list was empty
  newNode->next = *listPtr;

  //make head pointer of list point to new node
  *listPtr = newNode;


}


//Insert new data item at end of list
//
//Assumes listPtr holds address of head pointer
//for the list.  Variable listPtr may not
//be NULL, but the head pointer might be.
void insertAtTail(Node** listPtr, int data){


  /* TO DO (PART 2): fill in this function definition */



}

//Insert new data item into list into sorted list
//(ascending order) so that list remains sorted.
//
//Assumes listPtr holds address of head pointer
//for a SORTED list.  Variable listPtr may not
//be NULL, but the head pointer might be.
//
//The list is permitted to hold duplicate values.
void insertSorted(Node** listPtr, int data){


  /* TO DO (PART 3): fill in this function definition */




}


//Insert new data item into list into sorted list
//(ascending order) so that list remains sorted,
//but refuses to insert duplicate values into list.
//Returns the number of items actually inserted.
//
//Assumes listPtr holds address of head pointer
//for a SORTED list.  Variable listPtr may not
//be NULL, but the head pointer might be.
//
//The list is NOT permitted to hold duplicate values.                                                            
int insertSortedNoDups(Node** listPtr, int data){


  /* TO DO (PART 4): fill in this function definition */
  return 0; //to make this compile; replace as needed




}




//Iteratively print the list contents in forward direction
void printList(Node * head){

  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;  
  }  
}

