#include <stdlib.h>
#include <stdio.h>
#include "linked_int_list.h"

struct IntNode* reverseLinkedList(struct IntNode* head) {
  if (head == NULL) {
    printf("Linked list is empty.\n");
    return NULL;
  }

  if (head->next == NULL) {
    printf("Linked list has only one element.\n");
    return head;
  }

  struct IntNode* previousNode = NULL;
  struct IntNode* currentNode = head;
  struct IntNode* nextNode;

  while(currentNode != NULL) {
    nextNode = currentNode->next;
    currentNode->next =  previousNode;
    previousNode = currentNode;
    currentNode = nextNode;
  }
  head = previousNode;

  return head;
}

struct IntNode* reverseListRecursive(struct IntNode* current, struct IntNode* prev) {
    if (current == NULL) {
        return prev;
    }
    struct IntNode* nextNode = current->next;
    current->next = prev;
    return reverseListRecursive(nextNode, current);
}

struct IntNode* reverseLinkedListRecursiveWrapper(struct IntNode* head) {
    return reverseListRecursive(head, NULL);
}

int main() {
  struct IntNode* head = NULL;

  head = reverseLinkedList(head);

  head = insertIntAtBeginning(head, 5);
  head = reverseLinkedList(head);
  head = insertIntAtBeginning(head, 4);
  head = insertIntAtBeginning(head, 3);
  head = insertIntAtBeginning(head, 2);
  head = insertIntAtBeginning(head, 1);

  printIntList(head);

  head = reverseLinkedList(head);

  printIntList(head);

  head = reverseLinkedListRecursiveWrapper(head);

  printIntList(head);

  freeIntList(head);

  return 0;
}
