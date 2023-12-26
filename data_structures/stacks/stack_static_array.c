#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
  int Array[MAX_SIZE];
  int top;
};

void initializeStack(struct Stack* stack) {
  stack->top = -1;
}

int isEmpty(struct Stack* stack) {
  return stack->top == -1;
}

int isFull(struct Stack* stack) {
  return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
  if (isFull(stack)) {
    printf("Cannot push element: Stack overflow.\n");
    return;
  }
  stack->top++;
  stack->Array[stack->top] = value;
}

void pop(struct Stack* stack) {
  if (isEmpty(stack)) {
    printf("Cannot pop element: stack is empty.\n");
    return;
  }
  int popValue = stack->Array[stack->top];
  stack->top--;
  printf("Popped %d\n", popValue);

}

int peek(struct Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty.\n");
    return -1;
  }
  return stack->Array[stack->top];
}

int main() {
  struct Stack myStack;
  initializeStack(&myStack);

  printf("Stack is empty: %d\n", isEmpty(&myStack));
  printf("Stack is full: %d\n", isFull(&myStack));
  printf("Peek: %d\n", peek(&myStack));

  push(&myStack, 10);
  push(&myStack, 20);
  push(&myStack, 30);
  push(&myStack, 40);
  push(&myStack, 50);
  printf("Peek: %d\n", peek(&myStack));

  pop(&myStack);
  printf("Peek: %d\n", peek(&myStack));


  return 0;
}
