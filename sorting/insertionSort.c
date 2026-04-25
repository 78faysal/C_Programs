// Insertion sort builds the sorted array one element at a time by inserting each element into its correct position in the already sorted part.

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

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // ASCENDING
        if (order == 1) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }

        // DESCENDING
        else if (order == 2) {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }

        arr[j + 1] = key;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}