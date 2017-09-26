#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  printf("Create List\n");
  traverse(l);
  printf("\n");

  //Test length
  printf("Length: %d\n",length(l));
 
  //Test push
  printf("Push List\n");
  push(&l,"another string (-1)" ,30);
  traverse(l);
  printf("\n");
  
  //Test insert after
  printf("Insert after List\n");
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");
  
  //Test length
  printf("Length: %d\n",length(l2));

  // Test delete after
  printf("Delete after List\n");
  deleteAfter(l);
  traverse(l);
  printf("\n");

  //Test length
  printf("Length: %d\n",length(l2)); 

  printf("Pop List\n");
  listElement* popped = pop(&l);
  traverse(l);
  printf("\nPopped: ");
  traverse(popped);

  //Test Enqueue
  printf("\nEnqueue List\n");
  enqueue(&l,"Enqueue string (4)" ,30);
  traverse(l);

  //Test Dequeue
  printf("\nDequeue List\n");
  listElement* dequeued = dequeue(l);
  traverse(l);
  printf("\nDequeued: ");
  traverse(dequeued);

 printf("\nTests complete.\n");
}
