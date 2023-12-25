#include <stdio.h>
#include <stdlib.h>

struct IntNode {
  int value;
  struct IntNode* next;
};

struct IntNode* createIntNode(int data) {
  struct IntNode* newNode = (struct IntNode*)malloc(sizeof(struct IntNode));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  newNode->value = data;
  newNode->next = NULL;
  return newNode;
}

struct IntNode* insertIntAtBeginning(struct IntNode* head,int data) {
  struct IntNode* newNode = createIntNode(data);
  newNode->next = head;
  return newNode;
}

struct IntNode* insertIntAnywhere() {

}

void printList(struct IntNode* head) {
  struct IntNode* current = head;
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
}

void freeList(struct IntNode* head) {
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

  head = insertIntAtBeginning(head, 3);
  head = insertIntAtBeginning(head, 2);
  head = insertIntAtBeginning(head, 1);

  printList(head);

  freeList(head);

  return 0;
}
