#include <stdio.h>
#include "genericLinkedList.h"
#include "tests.h"

void printChar(void* data);

void printChar(void* data){
  printf("%s\n",(char*)(data));
}

void printInt(void* data){
  printf("%d\n",*((int*)data));
}
int main(int arg, char* argc[]){
  
  listElement* l = createEl("First Element", 30, printChar);
  traverse(l);
  int two = 2;
  insertAfter(l,&two, 10, printInt);
  traverse(l);

  runTests();
  return 0;
}
