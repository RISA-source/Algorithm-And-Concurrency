#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;   // avoid overflow

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;   // not found
}

int main() {
    // Array must be sorted for binary search
    int arr[] = {11, 22, 25, 34, 45, 64, 90, 112, 145, 200};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter number to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result == -1) {
        printf("%d is not present in the array.\n", key);
    } else {
        printf("%d found at index %d (position %d)\n", key, result, result + 1);
    }

    return 0;
}
