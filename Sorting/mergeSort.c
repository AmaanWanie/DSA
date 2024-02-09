#include <stdio.h>

int a[] = {7, 3, 8, 2};
int b[4]; // Size of 'b' should match the size of 'a'

void merge(int l, int mid, int h) { // 0,0,1
    int i = l;//0
    int j = mid + 1;//1
    int k = l;//1

    while (i <= mid && j <= h) {//0<=1 1<=1
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
        int mid = l + (h-l) / 2;//1st=0+(8-0)/2==4  
        mergesort(l, mid);//1st=(0,4)
        mergesort(mid + 1, h);//1st=(4,8)
        merge(l, mid, h);//1st=(0,4,8)
    }
}

int main() {
    int l = 0, h = 3;
    mergesort(l, h);

    printf("Sorted array:\n");
    for (int k = 0; k <=h; k++) {
        printf("%d ", a[k]);
    }

    return 0;
}
