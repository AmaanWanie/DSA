#include <stdio.h>

int arr[] = {54, 72, 255, 834, 57, 977, 156756};

void bubbleSort(int arr[], int n);
void swap(int arr[], int j);

void bubbleSort(int arr[], int n) {
    int i, j;
    int flag = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j);
                flag = 1;
            }
        }

        if (flag == 0) {
            break;
        }
    }
}

void swap(int arr[], int j) {
    int temp = arr[j];
    arr[j] = arr[j + 1];
    arr[j + 1] = temp;
}

int main() {
    int n = sizeof(arr) / sizeof(arr[0]);
printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n Sorted Array: ");
    bubbleSort(arr, n);
    int k;
    for (k = 0; k < 7; k++) {
        printf("%d ", arr[k]);
    }
    return 0;
}
