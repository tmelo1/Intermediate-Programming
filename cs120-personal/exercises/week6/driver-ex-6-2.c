#include <stdio.h>
#include <stdlib.h>
#include "list-ex-6-2.h"

int main() {


  /* Create a list by repeated use of insertAtHead, then output it */
  printf("\n---Section: insertAtHead---\n");

  Node * head = NULL;
  insertAtHead(&head, 55);
  printf("Expected: 55 \n  Actual: ");
  printList(head);
  printf("\n\n");

  insertAtHead(&head, 44);
  insertAtHead(&head, 22);
  
  printf("Expected: 22 44 55 \n  Actual: ");
  printList(head);
  printf("\n\n");



  /*----------------------------------------------------------------------*/



  /* PART 2:  Write insertAtTail method in list-ex-7-1.c, then 
     uncomment code below in order to test your insertAtTail method.
     Check that your actual output matches the expected output.


  printf("\n---Section: insertAtTail---\n");

  insertAtTail(&head, 77);
  insertAtTail(&head, 99);

  printf("Expected: 22 44 55 77 99 \n  Actual: ");
  printList(head);
  printf("\n\n");


  Node * head2 = NULL;
  insertAtTail(&head2, 5);
  insertAtTail(&head2, 8);

  printf("Expected: 5 8 \n  Actual: ");
  printList(head2);
  printf("\n\n");

  //deallocate all nodes in head2
  Node * temp2 = NULL;
  while (head2 != NULL) {
    temp2 = head2;
    head2 = head2->next;
    free(temp2);
  }

  */



  /*----------------------------------------------------------------------*/



/* PART 3:  Write insertSorted method in list-ex-7-1.c, then 
     uncomment code below in order to test your insertSorted method.
     Check that your actual output matches the expected output.


  printf("\n---Section: insertSorted---\n");
  insertSorted(&head, 35);
  insertSorted(&head, 35);
  insertSorted(&head, 11);
  insertSorted(&head, 101);
  insertSorted(&head, 17);

  printf("Expected: 11 17 22 35 35 44 55 77 99 101 \n  Actual: ");
  printList(head);
  printf("\n\n");

  Node * head3 = NULL;
  insertSorted(&head3, 5);
  insertSorted(&head3, 5);


  printf("Expected: 5 5 \n  Actual: ");
  printList(head3);
  printf("\n\n");

  insertSorted(&head3, 8);
  insertSorted(&head3, 0);
  insertSorted(&head3, 8);
  insertSorted(&head3, 5);
  insertSorted(&head3, 10);
  insertSorted(&head3, 10);
  insertSorted(&head3, 0);
  insertSorted(&head3, 4);

  printf("Expected: 0 0 4 5 5 5 8 8 10 10 \n  Actual: ");
  printList(head3);
  printf("\n\n");

  //deallocate all nodes in head3
  Node * temp3 = NULL;
  while (head3 != NULL) {
    temp3 = head3;
    head3 = head3->next;
    free(temp3);
  }

*/

  /*----------------------------------------------------------------------*/


  //deallocate all nodes in head
  Node * temp = NULL;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }


  /*----------------------------------------------------------------------*/


/* PART 4:  Write insertSortedNoDups method in list-ex-7-1.c, then 
     uncomment code below in order to test your insertSortedNoDups method.
     Check that your actual output matches the expected output.



  printf("\n---Section: insertSortedNoDups---\n");

  Node * head4 = NULL;
  int count = 0;
  count += insertSortedNoDups(&head4, 5);
  count += insertSortedNoDups(&head4, 5);


  printf("Expected: 5 \n  Actual: ");
  printList(head4);
  printf("\nExpected count = 1  \n  Actual count = %d\n\n", count);

  count += insertSortedNoDups(&head4, 8);
  count += insertSortedNoDups(&head4, 0);
  count += insertSortedNoDups(&head4, 8);
  count += insertSortedNoDups(&head4, 5);
  count += insertSortedNoDups(&head4, 10);
  count += insertSortedNoDups(&head4, 10);
  count += insertSortedNoDups(&head4, 0);
  count += insertSortedNoDups(&head4, 4);

  printf("Expected: 0 4 5 8 10 \n  Actual: ");
  printList(head4);
  printf("\nExpected count = 5  \n  Actual count = %d\n\n", count);

  //deallocate all nodes in head4
  Node * temp4 = NULL;
  while (head4 != NULL) {
    temp4 = head4;
    head4 = head4->next;
    free(temp4);
  }

*/


}
