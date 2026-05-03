#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;           // return index if found
        }
    }
    return -1;                  // not found
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);

    if (result == -1) {
        printf("%d is not present in the array.\n", key);
    } else {
        printf("%d found at index %d (position %d)\n", key, result, result + 1);
    }

    return 0;
}
