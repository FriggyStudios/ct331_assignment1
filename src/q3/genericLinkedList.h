#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

void printChar(void* data);
void printInt(void* data);
void printFloat(void* data);

typedef struct listElementStruct listElement;
typedef void (*printFunction)(void* data);
typedef struct listElementStruct{
  void* data;
  size_t size;
  struct listElementStruct* next;
  printFunction print;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, printFunction printFunc);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size,printFunction printFunc);

//Delete the element after the given el
void deleteAfter(listElement* after);

//Returns the number of elements in a linked list
int length(listElement* list);

//Push a new element onto the head of a list.
void push(listElement** list, void* data, size_t size, printFunction printFunc);

//Pop an element from the head of a list.
//Return this element
listElement* pop(listElement** list);

//Enqueue a new element onto the head of the list.
void enqueue(listElement** list, void* data, size_t size,printFunction printFunc);

//Dequeue an element from the tail of the list.
listElement* dequeue(listElement* list);

#endif

