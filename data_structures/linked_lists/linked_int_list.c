#include <stdio.h>
#include <stdlib.h>

struct IntNode {
  int value;
  struct IntNode* next;
};

struct IntNode* createIntNode(int data) {
  struct IntNode* newNode = (struct IntNode*)malloc(sizeof(struct IntNode));
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  newNode->value = data;
  newNode->next = NULL;
  return newNode;
}

struct IntNode* insertIntAtBeginning(struct IntNode* head, int data) {
  struct IntNode* newNode = createIntNode(data);
  newNode->next = head;
  return newNode;
}

struct IntNode* insertIntAnywhere(struct IntNode* head, int data, size_t position) {
  if (position < 0) {
    printf("Invalid position for insertion.\n");
    return head;
  }

  if (position == 0) {
    return insertIntAtBeginning(head, data);
  }

  struct IntNode* newNode = createIntNode(data);
  struct IntNode* current = head;
  int currentPosition = 0;

  while (current != NULL && currentPosition < position - 1) {
    current = current->next;
    currentPosition++;
  }

  if (current == NULL) {
    printf("Invalid position for insertion.\n");
    return head;
  }

  newNode->next = current->next;
  current->next = newNode;

  return head;
}

struct IntNode* removeIntNode(struct IntNode* head, size_t position) {
  if (position < 0) {
    printf("Invalid position for removal.\n");
    return head;
  }

  if (head == NULL) {
    printf("List is empty.\n");
    return NULL;
  }

  struct IntNode* current = head;
  struct IntNode* previous = NULL;
  int currentPosition = 0;

  while(current != NULL && currentPosition < position) {
    previous = current;
    current = current->next;
    currentPosition++;
  }

  if (current == NULL) {
    printf("Invalid position for removal.\n");
    return head;
  }

  if (previous == NULL) {
    head = current->next;
  }
  else {
    previous->next = current->next;
  }

  free(current);

  return head;
}

void updateIntValue(struct IntNode* head, int newValue, size_t position) {
  if (position < 0) {
    printf("Invalid position for update.\n");
    return;
  }

  struct IntNode* current = head;
  size_t currentPosition = 0;

  while (current != NULL && currentPosition < position) {
    current = current->next;
    currentPosition++;
  }

  if (current == NULL) {
    printf("Invalid position for update.\n");
    return;
  }

  current->value = newValue;

}

void printIntList(struct IntNode* head) {
  struct IntNode* current = head;
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
}

void printIntListWithRecursion(struct IntNode* head) {
  if (head == NULL)  {
    printf("NULL\n");
    return;
  }
  printf("%d -> ", head->value);
  printIntListWithRecursion(head->next);
}

void printReverseIntList(struct IntNode* head) {
  if (head == NULL)  return;
  printReverseIntList(head->next);
  printf("%d ", head->value);
}

void freeIntList(struct IntNode* head) {
  struct IntNode* current = head;
  struct IntNode* nextNode;
  while (current != NULL) {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }

}

int main() {
  struct IntNode* head = NULL;

  printIntList(head);

  head = insertIntAtBeginning(head, 5);
  head = insertIntAtBeginning(head, 4);
  head = insertIntAtBeginning(head, 3);
  head = insertIntAtBeginning(head, 2);
  head = insertIntAtBeginning(head, 1);

  printIntList(head);

  head = insertIntAnywhere(head, 10, 1);

  printIntList(head);

  head = removeIntNode(head, 0);

  printIntList(head);

  head = removeIntNode(head, 2);

  printIntList(head);

  updateIntValue(head, 1, 0);

  updateIntValue(head, 8, 1);

  printIntList(head);

  printIntListWithRecursion(head);

  printReverseIntList(head);

  freeIntList(head);

  return 0;
}
