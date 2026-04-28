#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to check if a number is prime (returns 1 if prime, 0 otherwise)
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

// Thread function: counts primes up to given limit
void* count_primes(void* arg) {
    int limit = *(int*)arg;
    int count = 0;
    
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            count++;
        }
    }
    
    printf("Thread (Limit = %d): Found %d prime numbers\n", limit, count);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <limit1> <limit2> ... <limitN>\n", argv[0]);
        printf("Example: %s 100 1000 10000\n", argv[0]);
        return 1;
    }

    int num_threads = argc - 1;
    pthread_t* threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    int* limits = (int*)malloc(num_threads * sizeof(int));

    if (threads == NULL || limits == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Create one thread for each limit
    for (int i = 0; i < num_threads; i++) {
        limits[i] = atoi(argv[i + 1]);
        
        if (limits[i] < 2) {
            printf("Warning: Limit %d is too small, skipping...\n", limits[i]);
            continue;
        }
        
        if (pthread_create(&threads[i], NULL, count_primes, &limits[i]) != 0) {
            printf("Error: Failed to create thread for limit %d\n", limits[i]);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nAll threads have completed execution.\n");

    // Clean up
    free(threads);
    free(limits);

    return 0;
}
