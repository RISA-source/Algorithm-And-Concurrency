#include <stdio.h>
#include <stdlib.h>

int* fibonacci(int size) {
    if (size <= 0) return NULL;
    
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) return NULL;
    
    if (size >= 1) arr[0] = 0;
    if (size >= 2) arr[1] = 1;
    
    for (int i = 2; i < size; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    return arr;
}

int main() {
    int n;
    printf("Enter size for Fibonacci: ");
    scanf("%d", &n);
    
    int* fib = fibonacci(n);
    if (fib != NULL) {
        for (int i = 0; i < n; i++)
            printf("%d ", fib[i]);
        printf("\n");
        free(fib);
    }
    return 0;
}
