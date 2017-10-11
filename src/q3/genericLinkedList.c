#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, printFunction printFunc){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  void* dataPointer = malloc(size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  e->print = printFunc;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    current->print(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size,printFunction printFunc){
  listElement* newEl = createEl(data, size,printFunc);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);

}
//Returns the number of elements in a linked list.
int length(listElement* list){ 
  int size = 0; 
  listElement* current = list;
  while(current != NULL){
    size++;
    current = current->next; 
  }
  return size;
}

//Push a new element onto the head of a list.
void push(listElement** list, void* data, size_t size,printFunction printFunc){
  listElement* newEl = createEl(data, size,printFunc);
  newEl->next = *list;
  *list = newEl;
}

//Pop an element from the head of a list.
listElement* pop(listElement** list){
  listElement* e  = *list;
  *list = (*list)->next;
  e->next = NULL;
  return e;    
}

//Enqueue a new element onto the head of the list.
void enqueue(listElement** list, void* data, size_t size,printFunction printFunc){ 
  listElement* newEl = createEl(data, size,printFunc);
  newEl->next = *list;
  *list = newEl;
}

//Dequeue an element from the tail of the list.
listElement* dequeue(listElement* list){
  listElement* last = list;
  listElement* secondLast = list;
  while(last->next != NULL){
   secondLast = last;
   last = last->next; 
  }
  secondLast->next = NULL;
  return last;  
}


