#include <stdio.h>

int main()
{
    // Declaring variables.
    int n, i, key, start, end, mid;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Declaring the array size.
    int arr[n];

    // Taking input for the array elements.
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // ASCENDING ORDER
    for (i = 1; i < n; i++){
        for (int j = 0; j < n - i; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];   // Temporary value holding for swapping
                arr[j] = arr[j + 1]; // Swapping the values
                arr[j + 1] = temp;
            }
        }
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Populating the values for binary search
    start = 0;
    end = n - 1;
    mid = (start + end) / 2;

    while (start <= end){
        if (arr[mid] < key){
            start = mid + 1; // Move the start to the right of mid
        }
        else if (arr[mid] > key){
            end = mid - 1; // Move the end to the left of mid
        }
        else{
            printf("Element found at index: %d \n", mid);
            break;
        }
        mid = (start + end) / 2;
    }

    if (start > end){
        printf("Element not found \n");
    }

    return 0;
}