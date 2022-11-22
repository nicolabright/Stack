#include <stdio.h>
#include <stdlib.h>

typedef struct StackElement {
	struct StackElement *bottomElement;
	int value;
} Stack;

void StackPush(Stack **ptrStack, int pushValue) {
	Stack *next = (Stack *) malloc( sizeof(Stack) );
	next->bottomElement = (*ptrStack);
	(*ptrStack) = next;
	(*ptrStack)->value = pushValue;
}

int StackPop(Stack **ptrStack) {
	if ( (*ptrStack) == NULL ) return (0);
	int returnValue = (*ptrStack)->value;
	Stack *previous = (*ptrStack)->bottomElement;
	free(ptrStack);
	(*ptrStack) = previous;
	return (returnValue);
}

void StackPrint(Stack **ptrStack) {
	Stack *scanStack = (*ptrStack);
	printf("-- Stack ----------------------------\n");
	while ( (scanStack != NULL) ) {
		printf("[ %d\t ]\n", scanStack->value);
		scanStack = scanStack->bottomElement;
	}
	printf("-------------------------------------\n");
}

int main() {
	Stack *myStack = NULL;
	StackPush(&myStack, 1);
	StackPush(&myStack, 2);
	StackPush(&myStack, 3);
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	StackPush(&myStack, 4);
	StackPush(&myStack, 5);
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	StackPush(&myStack, 6);
	StackPush(&myStack, 7);
	StackPush(&myStack, 8);
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	printf("P = %p\n", &myStack);
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	printf("P = %p\n", myStack);
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	printf("P = %p\n", myStack);
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	printf("P = %p\n", myStack);
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	printf("P = %p\n", myStack);
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	printf("Pop: %d\n", StackPop(&myStack));
	printf("Pop: %d\n", StackPop(&myStack));
	printf("Pop: %d\n", StackPop(&myStack));
	printf("Pop: %d\n", StackPop(&myStack));
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	StackPrint(&myStack);
	StackPush(&myStack, 9);
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	StackPrint(&myStack);
	printf("Pop: %d\n", StackPop(&myStack));
	return(0);
}
