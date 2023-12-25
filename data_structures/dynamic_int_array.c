#include <stdio.h>
#include <stdlib.h>

struct DynamicIntArray {
  int* array;
  size_t size;
  size_t capacity;
};

void initializeIntArray(struct DynamicIntArray* dynArray, size_t initialCapacity) {
  dynArray->array = (int*)malloc(initialCapacity * sizeof(int));
  if (dynArray->array == NULL) {
    printf("Failed to allocate memory.");
    exit(EXIT_FAILURE);
  }
  dynArray->size = 0;
  dynArray->capacity = initialCapacity;
}

void freeIntArray(struct DynamicIntArray* dynArray) {
  free(dynArray->array);
}

void appendIntArray(struct DynamicIntArray* dynArray, int value) {
  if (dynArray->size == dynArray->capacity) {
    printf("Array is full, resizing...\n");
    dynArray->capacity *= 2;
    dynArray->array = (int*)realloc(dynArray->array, dynArray->capacity*sizeof(int));
    if (dynArray->array == NULL) {
      printf("Failed to reallocate memory.");
      exit(EXIT_FAILURE);
    }
    printf("Resized to %zu elements.\n", dynArray->capacity);
  }

  dynArray->array[dynArray->size] = value;
  dynArray->size++;
}

void removeFromIntArray (struct DynamicIntArray* dynArray, size_t position) {
  if (position >= dynArray->size) {
    printf("Invalid position for removal.\n");
    return;
  }

  for (size_t i = position; i < dynArray->size-1; i++) {
      dynArray->array[i] = dynArray->array[i+1];
  }

  dynArray->size--;

  if (dynArray->size < dynArray->capacity/2) {
    dynArray->capacity /= 2;
    dynArray->array = (int*)realloc(dynArray->array, dynArray->capacity*sizeof(int));
    if (dynArray->array == NULL) {
      printf("Failed to reallocate memory.");
      exit(EXIT_FAILURE);
    }
  }
}

void printIntArray(struct DynamicIntArray* dynArray) {
    for (size_t i = 0; i < dynArray->size; i++) {
        printf("%d ", dynArray->array[i]);
    }
    printf("\n");
}

int main() {
  struct DynamicIntArray myArray;
  initializeIntArray(&myArray, 2);

  appendIntArray(&myArray, 1);
  appendIntArray(&myArray, 2);
  appendIntArray(&myArray, 3);
  appendIntArray(&myArray, 4);

  printIntArray(&myArray);

  removeFromIntArray(&myArray, 2);

  printIntArray(&myArray);

  freeIntArray(&myArray);
  return 0;
}
