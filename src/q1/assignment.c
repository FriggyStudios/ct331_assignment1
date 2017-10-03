#include <stdio.h>

int main(int arg, char* argc[]){
  printf("Hello assignment1.\n\n");

  int a = 1;
  int* b = &a;
  long c = 3;
  double d = 5.2;
  double* e = &d;
  char* f = "letters";
  char** g = &f;

  printf("int size: %lu\n",sizeof(a));
  printf("int* size: %lu\n",sizeof(b));
  printf("long size: %lu\n",sizeof(c));
  printf("double* size: %lu\n",sizeof(e));
  printf("char** size: %lu\n",sizeof(g));
  return 0;
}
