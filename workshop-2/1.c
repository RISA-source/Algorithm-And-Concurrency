#include <stdio.h>

int main() {
    int arr[] = {5, 2, 8, 5, 2, 9, 5, 1, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    int count = 0;

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter number to count: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    if (count == 0) {
        printf("%d does not appear in the array.\n", target);
    } else {
        printf("%d appears %d time%s in the array.\n", 
               target, count, count == 1 ? "" : "s");
    }

    return 0;
}
