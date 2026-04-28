#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int start;
    int end;
    int thread_id;
} SumData;

void* compute_sum(void* arg) {
    SumData* data = (SumData*)arg;
    long long sum = 0;

    for (int i = data->start; i <= data->end; i++) {
        sum += i;
    }

    printf("Thread %d: Sum from %d to %d = %lld\n", 
           data->thread_id, data->start, data->end, sum);

    pthread_exit(NULL);
}

int main() {
    int ranges[][2] = {
        {1, 1000},
        {1001, 2000},
        {2001, 3000},
        {3001, 4000}
    };

    int num_threads = 4;
    pthread_t threads[4];
    SumData data[4];

    for (int i = 0; i < num_threads; i++) {
        data[i].start = ranges[i][0];
        data[i].end = ranges[i][1];
        data[i].thread_id = i + 1;
        
        pthread_create(&threads[i], NULL, compute_sum, &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
