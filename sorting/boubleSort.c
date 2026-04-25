// Bubble sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.
// After each pass, the largest unsorted element “bubbles up” to its correct position at the end.

#include <stdio.h>

int main() {
    int n, order;

    printf("Enter the number of total elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter 1 for Ascending or 2 for Descending: ");
    scanf("%d", &order);

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            // ASCENDING
            if (order == 1 && arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

            // DESCENDING
            else if (order == 2 && arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}