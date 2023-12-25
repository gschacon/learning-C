#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct DynamicInt32Array {
  int32_t* array;
  size_t size;
  size_t capacity;
};

void initializeInt32Array(struct DynamicInt32Array* dynArray, size_t initialCapacity) {
  dynArray->array = (int32_t*)malloc(initialCapacity * sizeof(int32_t));
  if (dynArray->array == NULL) {
    printf("Failed to allocate memory.\n");
    exit(EXIT_FAILURE);
  }
  dynArray->size = 0;
  dynArray->capacity = initialCapacity;
}

void freeInt32Array(struct DynamicInt32Array* dynArray) {
  free(dynArray->array);
}

void appendInt32Array(struct DynamicInt32Array* dynArray, int32_t value) {
  if (dynArray->size == dynArray->capacity) {
    printf("Array is full, resizing...\n");
    dynArray->capacity *= 2;
    dynArray->array = (int32_t*)realloc(dynArray->array,dynArray->capacity * sizeof(int32_t));
    if (dynArray->array == NULL) {
      printf("Failed to reallocate memory.\n");
      exit(EXIT_FAILURE);
    }
    printf("Resized to %zu elements.\n", dynArray->capacity);
  }

  dynArray->array[dynArray->size] = value;
  dynArray->size++;
}

void removeFromInt32Array(struct DynamicInt32Array* dynArray, size_t position) {
  if (position >= dynArray->size) {
    printf("Invalid position for removal.\n");
    exit(EXIT_FAILURE);
  }

  for (size_t i = position; i < dynArray->size - 1; i++) {
    dynArray->array[i] = dynArray->array[i+1];
  }

  dynArray->size--;

  if (dynArray->size < dynArray->capacity/2) {
    dynArray->capacity /= 2;
    dynArray->array = (int32_t*)realloc(dynArray->array, dynArray->capacity * sizeof(int32_t));
    if (dynArray->array == NULL) {
      printf("Failed to reallocate memory.\n");
      exit(EXIT_FAILURE);
    }
  }
}

void insertIntoInt32Array(struct DynamicInt32Array* dynArray, int32_t value, size_t position) {
  if (position > dynArray->size) {
    printf("Invalid position for removal.\n");
    exit(EXIT_FAILURE);
  }
  else if (position == dynArray->size) {
    appendInt32Array(dynArray, value);
    return;
  }

  if (dynArray->size == dynArray->capacity) {
    printf("Array is full, resizing...\n");
    dynArray->capacity *= 2;
    dynArray->array = (int32_t*)realloc(dynArray->array, dynArray->capacity * sizeof(int32_t));
    if (dynArray->array == NULL) {
      printf("Failed to reallocate memory.\n");
      exit(EXIT_FAILURE);
    }
    printf("Resized to %zu elements.\n", dynArray->capacity);
  }

  for (size_t i = dynArray->size; i > position; i--) {
    dynArray->array[i] = dynArray->array[i-1];
  }

  dynArray->array[position] = value;
  dynArray->size++;
}

void printInt32Array(struct DynamicInt32Array* dynArray) {
  for (size_t i = 0; i < dynArray->size; i++) {
    printf("%d ",dynArray->array[i]);
  }
  printf("\n");
}

int main() {
  struct DynamicInt32Array myArray;
  initializeInt32Array(&myArray, 2);

  appendInt32Array(&myArray, 1);
  appendInt32Array(&myArray, 2);
  appendInt32Array(&myArray, 3);
  appendInt32Array(&myArray, 4);

  printInt32Array(&myArray);

  removeFromInt32Array(&myArray, 2);

  printInt32Array(&myArray);

  myArray.array[2] = 10;

  printInt32Array(&myArray);

  insertIntoInt32Array(&myArray, 5, 3);

  printInt32Array(&myArray);

  insertIntoInt32Array(&myArray, 4, 0);

  printInt32Array(&myArray);

  freeInt32Array(&myArray);
  return 0;
}
