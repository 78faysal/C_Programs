// Counting sort works by counting how many times each value appears in the array and then placing them in order.
// It is very fast for small integer ranges but not suitable for large value ranges.

#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of total elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // create count array
    int count[max + 1];

    // initialize count array to 0
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // store frequency
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // rebuild sorted array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }

    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}