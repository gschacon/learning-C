#include <stdio.h>
#include <stdlib.h>

struct DynamicStack {
  int* array;
  int top;
  size_t capacity;
};

void initializeDynamicStack(struct DynamicStack* dynStack, size_t initialCapacity) {
  dynStack->array = (int*)malloc(initialCapacity * sizeof(int));
  if (dynStack->array == NULL) {
    printf("Memory allocation failled.\n");
    exit(EXIT_FAILURE);
  }

  dynStack->top = -1;
  dynStack->capacity = initialCapacity;
}

int isDynamicStackEmpty(struct DynamicStack* dynStack) {
  return dynStack->top == -1;
}

void pushIntoDynamicStack(struct DynamicStack* dynStack, int value) {
  if (dynStack->top +1 == dynStack->capacity) {
    printf("Stack is full. Resizing..\n");
    dynStack->capacity *= 2;
    dynStack->array = (int*)realloc(dynStack->array, dynStack->capacity*sizeof(int));
    if (dynStack->array == NULL) {
      printf("Memory reallocation failled.\n");
      exit(EXIT_FAILURE);
    }
    printf("Resized to %zu elements.\n", dynStack->capacity);
  }
  dynStack->top++;
  dynStack->array[dynStack->top] = value;
}

void popDynamicStack(struct DynamicStack* dynStack) {
  if (isDynamicStackEmpty(dynStack)) {
    printf("Stack is already empty.\n");
    return;
  }

  int poppedValue = dynStack->array[dynStack->top];
  printf("Popped value: %d\n", poppedValue);
  dynStack->top--;

  if(dynStack->top < dynStack->capacity/2) {
    printf("Allocated space to big for Stack. Resizing...\n");
    dynStack->capacity /= 2;
    dynStack->array = (int*)realloc(dynStack->array, dynStack->capacity*sizeof(int));
    if (dynStack->array == NULL) {
      printf("Memory reallocation failled.\n");
      exit(EXIT_FAILURE);
    }
    printf("Resized to %zu elements.\n", dynStack->capacity);
  }
  return;
}

int peekDynamicStack(struct DynamicStack* dynStack) {
  if (isDynamicStackEmpty(dynStack)) {
    printf("Stack is empty.\n");
    return -1;
  }
  return dynStack->array[dynStack->top];
}

void freeDynamicStack(struct DynamicStack* dynStack) {
  free(dynStack->array);
}


int main() {
  struct DynamicStack myStack;
  initializeDynamicStack(&myStack,2);
  peekDynamicStack(&myStack);
  popDynamicStack(&myStack);
  printf("Is Stack empty: %d\n", isDynamicStackEmpty(&myStack));

  pushIntoDynamicStack(&myStack, 1);
  printf("Is Stack empty: %d\n", isDynamicStackEmpty(&myStack));
  pushIntoDynamicStack(&myStack, 2);
  pushIntoDynamicStack(&myStack, 3);
  pushIntoDynamicStack(&myStack, 4);

  printf("Peek stack: %d\n", peekDynamicStack(&myStack));

  popDynamicStack(&myStack);

  printf("Peek stack: %d\n", peekDynamicStack(&myStack));

  popDynamicStack(&myStack);
  popDynamicStack(&myStack);
  popDynamicStack(&myStack);
  popDynamicStack(&myStack);

  freeDynamicStack(&myStack);
  return 0;
}
