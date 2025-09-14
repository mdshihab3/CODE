#include <stdio.h>

void insertionSort(float arr[], int n) {
    for (int i=1; i<n; i++) {
        float key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float buckets[n][n];
    int count[n];
    for (int i=0; i<n; i++) count[i] = 0;

    for (int i=0; i<n; i++) {
        int bi = n*arr[i]; // bucket index
        buckets[bi][count[bi]++] = arr[i];
    }

    for (int i=0; i<n; i++) insertionSort(buckets[i], count[i]);

    int idx=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<count[i]; j++)
            arr[idx++] = buckets[i][j];
}

void printArray(float arr[], int n) {
    for (int i=0; i<n; i++) printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
