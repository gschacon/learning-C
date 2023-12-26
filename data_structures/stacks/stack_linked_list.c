#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* next;
};

struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  newNode->value = data;
  newNode->next = NULL;
  return newNode;
}

int isEmpty(struct Node* head) {
  return head == NULL;
}

struct Node* push(struct Node* head, int data) {
  struct Node* newNode = createNode(data);
  newNode->next = head;
  return newNode;
}

int peek(struct Node* head) {
  if (isEmpty(head)) {
    printf("Stack is empty. This will return -1.\n");
    return -1;
  }
  return head->value;
}

struct Node* pop(struct Node* head) {
  if (isEmpty(head)) {
    printf("Unable to pop. Stack is already empty.\n");
    return NULL;
  }

  struct Node* current = head;
  head = current->next;
  free(current);
  return head;
}

void freeList(struct Node* head) {
  struct Node* current = head;
  struct Node* nextNode;
  while (current != NULL) {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
}

int main() {
  struct Node* head = NULL;

  printf("IsEmpty: %d\n", isEmpty(head));
  peek(head);
  head = pop(head);

  head = push(head, 5);
  head = push(head, 4);
  head = push(head, 3);
  head = push(head, 2);
  head = push(head, 1);

  printf("IsEmpty: %d\n", isEmpty(head));

  printf("Peek: %d\n",peek(head));

  head = pop(head);

  printf("Peek: %d\n",peek(head));

  head = pop(head);
  head = pop(head);
  head = pop(head);
  head = pop(head);

  printf("IsEmpty: %d\n", isEmpty(head));

  printf("Peek: %d\n",peek(head));

  head = pop(head);

  freeList(head);
  return 0;
}
