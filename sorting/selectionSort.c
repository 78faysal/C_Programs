// Selection sort repeatedly finds the smallest element from the unsorted part and swaps it with the first unsorted position.
// It divides the array into a sorted and unsorted part and grows the sorted part one element at a time.

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

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minOrMaxIndex = i;

        for (int j = i + 1; j < n; j++) {

            // ASCENDING → find minimum
            if (order == 1 && arr[j] < arr[minOrMaxIndex]) {
                minOrMaxIndex = j;
            }

            // DESCENDING → find maximum
            else if (order == 2 && arr[j] > arr[minOrMaxIndex]) {
                minOrMaxIndex = j;
            }
        }

        // swap
        int temp = arr[i];
        arr[i] = arr[minOrMaxIndex];
        arr[minOrMaxIndex] = temp;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}