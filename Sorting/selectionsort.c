#include <stdio.h>

void swap(int arr[],int minIndex,int i){
    int	temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i; // m=0
        for (j = i + 1; j < n; j++) { //j=1
            if (arr[j] < arr[minIndex]) //if arr[1]<arr[0]
                minIndex = j;//m=1
                 
        }
        // Swap the found minimum element with the first element
        swap(arr,minIndex,i);
    }
}

int main() {
    int arr[] = {9,8,7,6,5,4,3};
    int n = 7;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
