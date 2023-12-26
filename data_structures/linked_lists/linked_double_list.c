#include <stdio.h>
#include <stdlib.h>

struct DoubleNode {
  double value;
  struct DoubleNode* next;
};

struct DoubleNode* createDoubleNode(double data) {
  struct DoubleNode* newNode = (struct DoubleNode*)malloc(sizeof(struct DoubleNode));
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  newNode->value = data;
  newNode->next = NULL;
  return newNode;

}
struct DoubleNode* insertDoubleAtBeginning(struct DoubleNode* head, double data) {
  struct DoubleNode* newNode = createDoubleNode(data);
  newNode->next = head;
  return newNode;
}

struct DoubleNode* insertDoubleAnywhere(struct DoubleNode* head, double data, size_t position) {
  if (position == 0) {
    return insertDoubleAtBeginning(head, data);
  }

  struct DoubleNode* newNode = createDoubleNode(data);
  struct DoubleNode* current = head;
  size_t currentPosition = 0;

  while (current != NULL && currentPosition < position-1) {
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

struct DoubleNode* removeDoubleNode(struct DoubleNode* head, size_t position) {
  if (position < 0) {
    printf("Invalid position for removal.\n");
    return head;
  }

  if (head == NULL) {
    printf("List is empty.\n");
  }

  struct DoubleNode* current = head;
  struct DoubleNode* previous = NULL;
  size_t currentPosition = 0;

  while (current != NULL && currentPosition < position) {
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

void updateDoubleValue(struct DoubleNode* head, double newValue, size_t position) {
  if (position < 0) {
    printf("Invalid position for update.\n");
    return;
  }

  struct DoubleNode* current = head;
  size_t newPosition = 0;

  while (current !=NULL && newPosition < position) {
    current = current->next;
    newPosition++;
  }

  if (current == NULL) {
    printf("Invalid position for update.\n");
    return;
  }

  current->value = newValue;
}

void printDoubleList(struct DoubleNode* head) {
  struct DoubleNode* current = head;
  while (current != NULL) {
    printf("%f -> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
}

void freeDoubleList(struct DoubleNode* head) {
  struct DoubleNode* current = head;
  struct DoubleNode* nextNode;
  while (current != NULL) {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
}

int main() {
  struct DoubleNode* head = NULL;

  printDoubleList(head);

  head = insertDoubleAtBeginning(head, 3.0);
  head = insertDoubleAtBeginning(head, 2.0);
  head = insertDoubleAtBeginning(head, 1.0);

  printDoubleList(head);

  head = insertDoubleAnywhere(head, 10.0, 1);

  printDoubleList(head);

  head = removeDoubleNode(head, 0);

  printDoubleList(head);

  head = removeDoubleNode(head, 2);

  printDoubleList(head);

  updateDoubleValue(head, 1.0, 0);

  updateDoubleValue(head, 8.00, 1);

  printDoubleList(head);

  freeDoubleList(head);

  return 0;
}
