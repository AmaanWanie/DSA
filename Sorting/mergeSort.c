#include <stdio.h>

int a[] = {7, 3, 8, 2, 6, 33, 5, 12, 1};
int b[9]; // Size of 'b' should match the size of 'a'

void merge(int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;

    while (i <= mid && j <= h) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= h) {
        b[k] = a[j];
        j++;
        k++;
    }

    // Copy sorted elements back to original array 'a'
    for (int m = l; m <= h; m++) {
        a[m] = b[m];
    }
}

void mergesort(int l, int h) {
    if (l < h) {
        int mid = l + (h-l) / 2;
        mergesort(l, mid);
        mergesort(mid + 1, h);
        merge(l, mid, h);
    }
}

int main() {
    int l = 0, h = 8;
    mergesort(l, h);

    printf("Sorted array:\n");
    for (int k = 0; k < 9; k++) {
        printf("%d ", a[k]);
    }

    return 0;
}
