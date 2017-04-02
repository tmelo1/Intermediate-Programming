#include <stdio.h>
#include <stdlib.h>
#include "list-ex-6-3.h"


//Remove first item (item closest to start of list)
//in a given list, if one exists.
//Return number of items removed (either 0 or 1).
int removeFirst(Node** listPtr){

  if (*listPtr == NULL) { //no item present to remove
    return 0;  
  }

  Node* temp = *listPtr;  //save a pointer to first node
  *listPtr = (*listPtr)->next; //adjust head pointer
  free(temp);  //deallocate node that is no longer needed
  return 1;

}


//Remove last item (item closest to end of list)
//in given list, if one exists.
//Return number of items removed (either 0 or 1).
int removeLast(Node** listPtr){
  if (*listPtr == NULL) {
    return 0;
  }

  Node *temp = *listPtr;
  Node *secondLast;
  while (temp->next != NULL) {
    if ((temp->next)->next == NULL) {
      secondLast = temp;
    }
    temp = temp->next;
  }
  secondLast->next = NULL;
  free(temp);
  return 1;


}


//Remove earliest occurrence of given item in the list.
//Does not remove any occurrences after the first.
//Does not assume list is already sorted.
//Return number of items removed (either 0 or 1).
int removeFirstOccurrence(Node** listPtr, int value){


  //TO DO PART 3: fill in your code here
  return -1;  //to get it to compile; modify as neeeded


}


//Remove all occurrences of given value in the list.
//Does not assume list is already sorted.
//Return number of items removed (0, 1, or more).
int removeAllOccurrences(Node** listPtr, int value){


  //TO DO PART 4: fill in your code here  
  return -1;  //to get it to compile; modify as neeeded


}







//Insert new data item at start of given list
//
//Assumes listPtr holds address of head pointer
//for the list.  Variable listPtr may not
//be NULL, but the head pointer might be.
void insertAtHead(Node** listPtr, int data){

  //create new node and populate it
  Node* newNode = malloc(sizeof(Node));
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

  //create new node and populate it
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*listPtr == NULL) { //list is empty

    //list is empty, so make new node the head
    *listPtr = newNode;

  } else {  //list already contains one or more items

    //locate end of existing list
    Node* cur = *listPtr;
    while(cur->next != NULL) {
      cur = cur->next;
    }

    //connect new node to end of list
    cur->next = newNode;

  }

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

  //create new node and populate it
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*listPtr == NULL) { //list is empty

    //list is empty, so make new node the head
    *listPtr = newNode;

  } else if (data < (*listPtr)->data) { //new item should precede existing list

    //append existing list to new node & make head point to new node
    newNode->next = *listPtr;
    *listPtr = newNode;

  } else {  //list already contains one or more items that should precede new item

    //determine where after first node, exactly, new node should go
    Node* cur = *listPtr;
    while(cur->next != NULL  &&  data > cur->next->data) { //short circuit &&
      cur = cur->next;
    }

    //insert new node between cur node and its successor node
    newNode->next = cur->next;
    cur->next = newNode;
  }

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

  //create new node and populate it
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*listPtr == NULL) { //list is empty, so can't have any duplicates

    //list is empty, so make new node the head
    *listPtr = newNode;
    return 1;

  } else if (data < (*listPtr)->data) { //new item should precede existing list

    //connect existing list so it appears after new node & make head point to new node
    newNode->next = *listPtr;
    *listPtr = newNode;
    return 1;

  } else if (data == (*listPtr)->data) { //new item matches first one in existing list

    free(newNode);  //don't insert it, won't need the node after all
    return 0;

  } else {  //list already contains at least one item that should precede new item

    //determine where after first node, exactly, new node should go
    Node* cur = *listPtr;
    while(cur->next != NULL && data > cur->next->data) {
      cur = cur->next;
    }

    //now insert as long as haven't found a duplicate value
    if (cur->next == NULL) {  //need to insert at end of list

      cur->next = newNode;
      return 1;

    } else if (data == cur->next->data) { //found duplicate, don't insert

      free(newNode);  //deallocate node; don't need it after all
      return 0;

    } else {  //data < cur->next->data, so safe to insert here

      //insert it between cur node and its successor node
      newNode->next = cur->next;
      cur->next = newNode;
      return 1;

    }
  }

}




//Iteratively print the list contents in forward direction
void printList(Node* head){

  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;  
  }  
}


