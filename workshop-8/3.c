#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int num;     // number whose multiples to count
    int limit;   // upper limit
} ThreadData;

void* count_multiples(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int count = 0;

    for (int i = data->num; i <= data->limit; i += data->num) {
        count++;
    }

    printf("Thread, Multiples of %d up to %d = %d\n", 
           data->num, data->limit, count);

    pthread_exit(NULL);
}

int main() {
    int nums[] = {3, 5, 7, 9};
    int limit = 50;
    int num_threads = 4;

    pthread_t threads[4];
    ThreadData data[4];

    for (int i = 0; i < num_threads; i++) {
        data[i].num = nums[i];
        data[i].limit = limit;
        pthread_create(&threads[i], NULL, count_multiples, &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
