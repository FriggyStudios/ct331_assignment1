#include <stdio.h>
#include "genericLinkedList.h"
#include "tests.h"

void printChar(void* data);
void printInt(void* data);
void printFloat(void* data);

void printChar(void* data){
  printf("%s\n",(char*)(data));
}
void printInt(void* data){
  printf("%d\n",*((int*)data));
}
void printFloat(void* data){
  printf("%f\n",*((float*)data));
}

int main(int arg, char* argc[]){
  printf("Create List\n");  
  listElement* l = createEl("First Element", 30, printChar);
  traverse(l);
  printf("Length: %d\n",length(l));

  printf("\nInsert to List\n");
  int two = 2;
  insertAfter(l,&two, 10, printInt);
  traverse(l);
  printf("Length: %d\n",length(l));
 
  printf("\nPush to List\n");
  float three = 3.14f;
  push(&l,&three,10,printFloat);
  traverse(l);
  printf("Length: %d\n",length(l));
 
  printf("\nPop from  List\n");
  pop(&l);
  traverse(l); 
  printf("Length: %d\n",length(l));

  runTests();
  return 0;
}
