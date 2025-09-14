#include <stdio.h>
#include <string.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i=1; i<n; i++) if (arr[i]>max) max = arr[i];

    int count[max+1];
    int output[n];
    memset(count, 0, sizeof(count));

    for (int i=0; i<n; i++) count[arr[i]]++;
    for (int i=1; i<=max; i++) count[i] += count[i-1];
    for (int i=n-1; i>=0; i--) output[--count[arr[i]]] = arr[i];
    for (int i=0; i<n; i++) arr[i] = output[i];
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
