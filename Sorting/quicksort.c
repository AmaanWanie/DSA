#include <stdio.h>
#include <stdlib.h>

int a[] = {7, 3, 8, 2, 6, 33, 5, 12, 1};
int piv = 7;

void swap(int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int l, int h) {
  int pivot = a[h];
  int i = l - 1;
  for (int j = l; j < h; j++) {
    if (a[j] <= pivot) {
      i++;
      swap(i, j);
    }
  }
  swap(i + 1, h);
  return i + 1;
}


void quicksort(int l, int h) {
    if (l < h) {
        int j = partition(l, h);
        quicksort(l, j - 1);
        quicksort(j, h);
    }
}

int main() {
    int l = 0;
    int h = 8;

    quicksort(l, h);
    int k;
    for (k = 0; k < 9; k++) {
        printf("%d ", a[k]);
    }

    return 0;
}
