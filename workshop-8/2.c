#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

void* count_primes(void* arg) {
    int limit = *(int*)arg;
    int count = 0;

    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            count++;
        }
    }

    printf("Thread (Limit = %d): Found %d prime numbers\n", limit, count);
    
    // Return the count using pthread_exit()
    int* result = (int*)malloc(sizeof(int));
    *result = count;
    pthread_exit((void*)result);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <limit1> <limit2> ...\n", argv[0]);
        return 1;
    }

    int num_threads = argc - 1;
    pthread_t* threads = malloc(num_threads * sizeof(pthread_t));
    int* limits = malloc(num_threads * sizeof(int));

    for (int i = 0; i < num_threads; i++) {
        limits[i] = atoi(argv[i + 1]);
        pthread_create(&threads[i], NULL, count_primes, &limits[i]);
    }

    // Collect results from pthread_exit()
    for (int i = 0; i < num_threads; i++) {
        int* result;
        pthread_join(threads[i], (void**)&result);
        printf("Main: Thread %d returned %d primes\n", i+1, *result);
        free(result);   // Don't forget to free!
    }

    free(threads);
    free(limits);
    return 0;
}
