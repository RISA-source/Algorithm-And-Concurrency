#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper function to check prime
int isPrime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter array size (1000 to 99999): ");
    scanf("%d", &n);

    if (n < 1000 || n > 99999) {
        printf("Size must be between 1000 and 99999\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(time(NULL));   // Seed random number generator

    // Fill array with random numbers (1 to 100000 for example)
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000 + 1;
    }

    printf("Prime numbers found:\n");
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
            count++;
            if (count % 10 == 0) printf("\n");   // nice formatting
        }
    }
    if (count == 0) printf("No primes found.\n");

    free(arr);   // Always free allocated memory
    printf("\nMemory freed.\n");

    return 0;
}
