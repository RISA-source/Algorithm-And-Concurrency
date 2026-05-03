#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("How many numbers do you want to store? ");
    scanf("%d", &n);
    
    int* arr1 = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(n * sizeof(int));
    
    if (arr1 == NULL || arr2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    
    // Copy in reverse order
    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[n - 1 - i];
    }
    
    printf("Original : ");
    for (int i = 0; i < n; i++) printf("%d ", arr1[i]);
    printf("\nReversed  : ");
    for (int i = 0; i < n; i++) printf("%d ", arr2[i]);
    printf("\n");
    
    free(arr1);
    free(arr2);
    
    return 0;
}
