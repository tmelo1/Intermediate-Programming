#include <stdio.h>
#include <stdlib.h>
#include "list-ex-6-3.h"

int main() {


  /* Create a list by repeated use of insertAtHead, then output it */
  printf("\n---Section: setup---\n");

  Node* head = NULL;
  insertAtHead(&head, 55);
  insertAtHead(&head, 44);
  insertAtHead(&head, 33);
  insertAtHead(&head, 22);
  
  printf("Expected: 22 33 44 55 \n  Actual: ");
  printList(head);
  printf("\n\n");


  /* Remove items by repeated use of removeFirst, then output result */
  printf("\n---Section: removeFirst---\n");

  int count = 0;  //counting removals
  count += removeFirst(&head);
  printf("Expected: 33 44 55 \n  Actual: ");
  printList(head);
  printf("\n\n");

  count += removeFirst(&head);
  count += removeFirst(&head);

  printf("Expected: 55 \n  Actual: ");
  printList(head);
  printf("\n\n");

  count += removeFirst(&head);

  printf("Expected: \n  Actual: ");
  printList(head);

  printf("\n\nExpected count: 4 \n  Actual count: %d \n\n", count);
  printf("\n\n");


 /*----------------------------------------------------------------------*/



  /* PART 2:  Write removeLast method in list-ex-7-2.c, then 
     uncomment code below in order to test your removeLast method.
     Check that your actual output matches the expected output.

  */
  //Create a list by repeated use of insertAtHead, then output it
  printf("\n---Section: setup---\n");

  Node* head2 = NULL;
  insertAtHead(&head2, 55);
  insertAtHead(&head2, 44);
  insertAtHead(&head2, 33);
  insertAtHead(&head2, 22);
  
  printf("Expected: 22 33 44 55 \n  Actual: ");
  printList(head2);
  printf("\n\n");

  printf("\n---Section: removeLast---\n");

  int count2 = 0;
  count2 += removeLast(&head2);

  printf("Expected: 22 33 44 \n  Actual: ");
  printList(head2);
  printf("\n\n");

  count2 += removeLast(&head2);
  count2 += removeLast(&head2);

  printf("Expected: 22 \n  Actual: ");
  printList(head2);
  printf("\n\n");

  count2 += removeLast(&head2);

  printf("Expected: \n  Actual: ");
  printList(head2);

  printf("\n\nExpected count: 4 \n  Actual count: %d \n\n", count2);
  printf("\n\n");





  /*----------------------------------------------------------------------*/



/* PART 3:  Write removeFirstOccurrence method in list-ex-7-2.c, then 
     uncomment code below in order to test your removeFirstOccurrence method.
     Check that your actual output matches the expected output.

  //Create a list by repeated use of different inserts, then output it
  printf("\n---Section: setup---\n");

  Node* head3 = NULL;
  int count3 = 0;

  insertSorted(&head3, 35);
  insertSorted(&head3, 35);
  insertSorted(&head3, 11);
  insertSorted(&head3, 101);
  insertSorted(&head3, 17);

  printf("Expected: 11 17 35 35 101 \n  Actual: ");
  printList(head3);
  printf("\n\n");

  //Remove items by repeated use of removeFirstOccurrence, then output result
  printf("\n---Section: removeFirstOccurrence---\n");

  count3 += removeFirstOccurrence(&head3, 17);
  
  printf("Expected: 11 35 35 101 \n  Actual: ");
  printList(head3);

  printf("\n\nExpected count: 1 \n  Actual count: %d \n\n", count3);

  count3 += removeFirstOccurrence(&head3, 35);
  
  printf("Expected: 11 35 101 \n  Actual: ");
  printList(head3);

  printf("\n\nExpected count: 2 \n  Actual count: %d \n\n", count3);

  count3 += removeFirstOccurrence(&head3, 101);
  
  printf("Expected: 11 35 \n  Actual: ");
  printList(head3);

  printf("\n\nExpected count: 3 \n  Actual count: %d \n\n", count3);

  insertSorted(&head3, 77);
  insertSorted(&head3, 15);
  insertSorted(&head3, 21);
  count3 += removeFirstOccurrence(&head3, 35);
  count3 += removeFirstOccurrence(&head3, 77);
  count3 += removeFirstOccurrence(&head3, 11);
  count3 += removeFirstOccurrence(&head3, 35);  //doesn't appear

  printf("Expected: 15 21 \n  Actual: ");
  printList(head3);

  printf("\n\nExpected count: 6 \n  Actual count: %d \n\n", count3);
  
  count3 += removeFirstOccurrence(&head3, 21);
  count3 += removeFirstOccurrence(&head3, 33);  //doesn't appear
  count3 += removeFirstOccurrence(&head3, 15);

  printf("Expected: \n  Actual: ");
  printList(head3);

  count3 += removeFirstOccurrence(&head3, 21); //doesn't appear

  printf("\n\nExpected count: 8 \n  Actual count: %d \n\n", count3);


  */


  /*----------------------------------------------------------------------*/


  //deallocate all nodes in head
  Node* temp = NULL;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }


  /*----------------------------------------------------------------------*/


/* PART 4:  Write removeAllOccurrences method in list-ex-7-2.c, then 
     uncomment code below in order to test your removeAllOccurrences method.
     Check that your actual output matches the expected output.



  printf("\n---Section: removeAllOccurrences---\n");

  Node* head4 = NULL;
  int count4 = 0;

  count4 += removeAllOccurrences(&head4, 5);  //does not appear


  printf("Expected: \n  Actual: ");
  printList(head4);
  printf("\n\nExpected count = 0  \n  Actual count = %d\n\n", count4);


  insertAtHead(&head4, 3);
  insertAtHead(&head4, 5);
  insertAtHead(&head4, 5);
  insertAtHead(&head4, 2);
  insertAtHead(&head4, 1);

  printf("Expected: 1 2 5 5 3\n  Actual: ");
  printList(head4);
  printf("\n\nExpected count = 0  \n  Actual count = %d\n\n", count4);
  count4 += removeAllOccurrences(&head4, 5); //appears twice

  printf("Expected: 1 2 3\n  Actual: ");
  printList(head4);
  printf("\n\nExpected count = 2  \n  Actual count = %d\n\n", count4);


  //deallocate all nodes in head4 so we can start fresh
  Node* temp4 = NULL;
  while (head4 != NULL) {
    temp4 = head4;
    head4 = head4->next;
    free(temp4);
  }


  insertAtHead(&head4, 5);
  insertAtHead(&head4, 5);
  insertAtHead(&head4, 5);
 
  printf("Expected: 5 5 5 \n  Actual: ");
  printList(head4);
  printf("\n\n");

  count4 += removeAllOccurrences(&head4, 5); //appears three times

  printf("Expected: \n  Actual: ");
  printList(head4);
  printf("\n\nExpected count = 5  \n  Actual count = %d\n\n", count4);


  insertAtHead(&head4, 2);
  insertAtHead(&head4, 5);

  count4 += removeAllOccurrences(&head4, 5); //appears once

  printf("Expected: 2 \n  Actual: ");
  printList(head4);
  printf("\n\n");

  insertAtHead(&head4, 5);
  insertAtHead(&head4, 2);
  count4 += removeAllOccurrences(&head4, 5); //appears once

  printf("Expected: 2 2 \n  Actual: ");
  printList(head4);
  printf("\n\nExpected count = 7  \n  Actual count = %d\n\n", count4);

  count4 += removeAllOccurrences(&head4, 5); //doesn't appear

  printf("Expected: 2 2 \n  Actual: ");
  printList(head4);
  printf("\n\nExpected count = 7  \n  Actual count = %d\n\n", count4);

  count4 += removeAllOccurrences(&head4, 2); //appears twice

  printf("Expected: \n  Actual: ");
  printList(head4);
  printf("\n\nExpected count = 9  \n  Actual count = %d\n\n", count4);
  return 0;

  //deallocate all remaining nodes in head4
  temp4 = NULL;
  while (head4 != NULL) {
    temp4 = head4;
    head4 = head4->next;
    free(temp4);
  }
*/

}
