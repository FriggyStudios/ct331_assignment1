#include <stdio.h>
#include <string.h>
#include "tests.h"
#include "linkedList.h"
#include <stdbool.h>
void runTests(){
  printf("Tests running...\n");
  testCreateEl();
  testInsertAfter();
  testDeleteAfter();
  testLength();
  testPush();
  testPop();
  testEnqueue();
  testDequeue();
  printf("\nTests complete.\n");
}

void testCreateEl(){
  char* string  = "string123";
  size_t size = 30;
  listElement* e = createEl(string,size);
  if(e == NULL)
    printf("Error: creatEl returned Null\n");
  else if(strcmp(e->data, string) != 0)
    printf("Error: createEl not passing correct char*\n");
  else if(e->size != size)
    printf("Error: createEl not passing correct size\n");
  else if(e->next != NULL)
    printf("Error: createEl not setting  next element NULL");
  else
    printf("Success: createEl\n");
    	
}
void testInsertAfter(){
  char* string1 = "string123";
  char* string2 = "string321"; 
  size_t size = 30;
  listElement* e = createEl(string1,size);
  listElement* eNext = e->next;
  listElement* e2  = insertAfter(e,string2,size);
  
  if(e2 == NULL)
    printf("Error: insertAfter returning Null\n");  
  else if(e2->next != eNext)
    printf("Error: insertAfter not setting next for new element correctly\n");
  else if(e->next != e2)
    printf("Error: ot setting next for old element correctly\n");
  else
    printf("Success: insertAfter\n");
}

void testDeleteAfter(){
  char* string1 = "string123";
  char* string2 = "string321"; 
  size_t size = 30;
  listElement* e = createEl(string1,size);
  listElement* e2 = insertAfter(e,string2,size);
  listElement* e2Next = e2->next;
  deleteAfter(e);
  
  if(e->next != e2Next)
    printf("Error: deleteAfter not updating next pointer\n");
  else 
    printf("Success: deleteAfter\n");
}

void testLength(){
  bool fail = false;
  char* string1 = "string123";
  char* string2 = "string321"; 
  size_t size = 30;
  listElement* e = createEl(string1,size);
  if(length(e) != 1)
    fail = true;
  insertAfter(e,string2,size);
  if(length(e) != 2)
    fail = true;
  deleteAfter(e);
  if(length(e) != 1)
    fail = true;

  if(fail)
    printf("Error: length incorrect length\n");
  else
    printf("Success: length\n");
}

void testPush(){
  char* string1 = "string123";
  char* string2 = "string321"; 
  size_t size = 30;
  listElement* e = createEl(string1,size);
  listElement** list = &e;
  push(list,string2,size);
  
  if(e->next == NULL)
    printf("Error: push next not updated \n");  
  else if(strcmp(e->data, string2) != 0)
    printf("Error: push head of list not updated\n");
  else
    printf("Success: push\n");
}

void testPop(){
  char* string1 = "string123";
  char* string2 = "string321"; 
  size_t size = 30;
  listElement* e = createEl(string1,size);
  insertAfter(e,string2,size);
  listElement* ePop = pop(&e);

  if(ePop == NULL)
    printf("Error: pop returned NULL\n");
  else if(strcmp(string1,ePop->data) != 0)
    printf("Error: pop returned wrong element\n");
  else if(strcmp(string2,e->data) != 0)
    printf("Error: pop set wrong element to front of list\n");
   else
    printf("Success: pop\n"); 
}

void testEnqueue(){
  char* string1 = "string123";
  char* string2 = "string321"; 
  size_t size = 30;
  listElement* e = createEl(string1,size);
  listElement** list = &e;
  push(list,string2,size);
  
  if(e->next == NULL)
    printf("Error: enqueue next not updated \n");  
  else if(strcmp(e->data, string2) != 0)
    printf("Error: enqueue head of list not updated\n");
  else
    printf("Success: enqueue\n");
}
void testDequeue(){
  char* string1 = "string123";
  char* string2 = "string321"; 
  size_t size = 30;
  listElement* e = createEl(string1,size);
  insertAfter(e,string2,size);
  listElement* queue = dequeue(e);
  
  if(queue == NULL)
    printf("Error: dequeue returned NULL\n");
  else if(strcmp(queue->data,string2) != 0)
    printf("Error: dequeue returned wrong element\n");
  else if(e->next != NULL)
    printf("Error: dequeue next not updated\n");
  else
    printf("Success: dequeue\n");
}  

