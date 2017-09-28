#include <stdio.h>
#include "linkedList.h"
#include "tests.h"

int main(int arg, char* argc[]){
  //Create list 
  listElement* l = createEl("test string (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //test create and traverse
  printf("create list\n");
  traverse(l);
  printf("\n");

  //test length
  printf("length: %d\n",length(l));
 
  //test push
  printf("push list\n");
  push(&l,"another string (-1)" ,30);
  traverse(l);
  printf("\n");
  
  //test insert after
  printf("insert after list\n");
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");
  
  //test length
  printf("length: %d\n",length(l2));

  // test delete after
  printf("delete after list\n");
  deleteAfter(l);
  traverse(l);
  printf("\n");

  //test length
  printf("length: %d\n",length(l2)); 

  printf("pop list\n");
  listElement* popped = pop(&l);
  traverse(l);
  printf("\npopped: ");
  traverse(popped);

  //test enqueue
  printf("\nenqueue list\n");
  enqueue(&l,"enqueue string (4)" ,30);
  traverse(l);

  //test dequeue
  printf("\ndequeue list\n");
  listElement* dequeued = dequeue(l);
  traverse(l);
  printf("dequeued element: ");
  traverse(dequeued);
  
  runTests();
  return 0;
}
