// Radix sort sorts numbers digit by digit starting from the least significant digit to the most significant digit.
// It uses counting sort as a subroutine for each digit position


#include <stdio.h>

// Get maximum value
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting sort based on digit (exp = 1, 10, 100...)
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so it contains position
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Sort digit by digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements (non-negative integers):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}