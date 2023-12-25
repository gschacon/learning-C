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

int main() {
  struct DynamicIntArray myArray;
  initializeIntArray(&myArray, 10);

  return 0;
}
