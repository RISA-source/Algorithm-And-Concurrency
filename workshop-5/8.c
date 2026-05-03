#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int* primes(int n) {
    if (n <= 0) return NULL;
    
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return NULL;
    
    int count = 0, num = 2;
    while (count < n) {
        if (isPrime(num)) {
            arr[count++] = num;
        }
        num++;
    }
    return arr;
}

int main() {
    int n;
    printf("Enter how many primes: ");
    scanf("%d", &n);
    
    int* p = primes(n);
    if (p != NULL) {
        for (int i = 0; i < n; i++)
            printf("%d ", p[i]);
        printf("\n");
        free(p);
    }
    return 0;
}
