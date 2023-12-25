#include <stdio.h>
#include <stdlib.h>

void removeFromIntArray(int* array, int position) {

  for(int i = position; i < sizeof(array)/sizeof(array[0]); i++) {
    array[i] = array[i+1];
  }
}

int main() {

  int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(A)/sizeof(A[0]);

  removeFromIntArray(A, 1);

  for(int i = 0; i < size; i++) {
    printf("%d ", A[i]);
  }

  return 0;
}
