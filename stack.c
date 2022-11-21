#include <stdio.h>
#include <stdlib.h>

typedef struct StackElement {
	struct StackElement *topElement;
	struct StackElement *bottomElement;
	int value;
	int elementUsed;
} Stack;

void StackInit(Stack **ptrStack) {
	(*ptrStack) = malloc( sizeof(Stack)*1 );
	(*ptrStack)->topElement = NULL;
	(*ptrStack)->bottomElement = NULL;
	(*ptrStack)->value = -1;
	(*ptrStack)->elementUsed = -1;
}

void StackPush(Stack **ptrStack, int pushValue) {
	if ((*ptrStack)->elementUsed != -1) {
		(*ptrStack)->topElement = (Stack *) malloc( sizeof(Stack)*1);
		(*ptrStack)->topElement->bottomElement = (*ptrStack);
		(*ptrStack) = (*ptrStack)->topElement;
	}
	(*ptrStack)->value = pushValue;
	(*ptrStack)->elementUsed = 0;
}

int StackPop(Stack **ptrStack) {
	if ((*ptrStack)->elementUsed == -1) {
		return (0);
	} else {
		int returnValue = (*ptrStack)->value;
		if ((*ptrStack)->bottomElement != NULL) {
			(*ptrStack) = (*ptrStack)->bottomElement;
			free((*ptrStack)->topElement);
		} else {
			(*ptrStack)->elementUsed = -1;
		}
		return (returnValue);
	}
}

void StackPrint(Stack **ptrStack) {
	Stack *scanStack = (*ptrStack);
	printf("-- Stack ----------------------------\n");
	while (scanStack->elementUsed != -1) {
		printf("[ %d\t ]\n", scanStack->value);
		scanStack = scanStack->bottomElement;
	}
	printf("-------------------------------------\n");
}

void main() {
	Stack *myStack;
	StackInit(&myStack);
	StackPrint(&myStack);

	StackPush(&myStack, 1);
//	StackPrint(&myStack);

	StackPush(&myStack, 2);
	StackPrint(&myStack);

//	StackPrint(myStack);

/*
	StackPush(myStack, 3);
	printf("Pop: %d\n", StackPop(myStack));
	StackPush(myStack, 4);
	printf("Pop: %d\n", StackPop(myStack));
	StackPush(myStack, 5);
	printf("Pop: %d\n", StackPop(myStack));
	StackPrint(myStack);
	printf("Pop: %d\n", StackPop(myStack));

	printf("Pop: %d\n", StackPop(myStack));
	printf("Pop: %d\n", StackPop(myStack));
	printf("Pop: %d\n", StackPop(myStack));
	printf("Pop: %d\n", StackPop(myStack));
	printf("Pop: %d\n", StackPop(myStack));
	printf("Pop: %d\n", StackPop(myStack));
	printf("Pop: %d\n", StackPop(myStack));
	printf("Pop: %d\n", StackPop(myStack));
*/
	printf("==============================================================\n");
}
