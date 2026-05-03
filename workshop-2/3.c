#include <stdio.h>

// Recursive function to calculate sum of first n natural numbers
int sumNatural(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return n;
    }
    // Recursive case
    return n + sumNatural(n - 1);
}

int main() {
    int n;
    printf("Enter value of N: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    int result = sumNatural(n);
    printf("Sum of first %d natural numbers = %d\n", n, result);

    // For comparison: mathematical formula (O(1))
    printf("(using formula n(n+1)/2) = %d\n", n * (n + 1) / 2);

    return 0;
}
