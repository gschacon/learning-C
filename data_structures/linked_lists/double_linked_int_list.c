#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node* previous;
  int value;
  struct Node* next;
};

struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  newNode->previous = NULL;
  newNode->value = data;
  newNode->next = NULL;
  return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
  struct Node* newNode = createNode(data);
  if (head != NULL) {
    head->previous = newNode;
  }
  newNode->next = head;
  return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
  struct Node* newNode = createNode(data);
  struct Node* current = head;

  if (head == NULL) {
    return newNode;
  }

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
  newNode->previous = current;

  return head;
}

struct Node* removeNode(struct Node* head, size_t position) {
  if (head == NULL) {
    printf("List is empty.\n");
    return NULL;
  }

  if (position < 0) {
    printf("Invalid removal position.\n");
    return head;
  }

  struct Node* current = head;
  size_t currentPosition = 0;

  while (current != NULL && currentPosition < position) {
    current = current->next;
    currentPosition++;
  }

  if (current == NULL) {
    printf("Invalid removal position.\n");
  }

  if (current->previous != NULL) {
    current->previous->next = current->next;
  }
  else {
    head = current->next;
  }

  if (current->next != NULL) {
    current->next->previous = current->previous;
  }

  free(current);

  return head;
}

void printList(struct Node* head) {
  struct Node* current = head;
  while (current != NULL) {
    printf("%d <-> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
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

  head = insertAtBeginning(head, 5);
  head = insertAtBeginning(head, 4);
  head = insertAtBeginning(head, 3);
  head = insertAtBeginning(head, 2);
  head = insertAtBeginning(head, 1);

  printList(head);

  head = removeNode(head, 0);
  head = removeNode(head, 1);
  head = removeNode(head, 2);

  printList(head);

  head = insertAtEnd(head, 6);
  head = insertAtEnd(head, 7);
  head = insertAtEnd(head, 8);

  printList(head);

  freeList(head);

  return 0;
}
