#include <stdio.h>

int main() {

    int numbers[11] = {12, 45, 3, 78, 23, 56, 89, 34, 9, 67, 41};

    int smallest = numbers[0];
    int largest = numbers[0];
    int sum = 0;

    for(int i = 0; i < 11; i++) {

        if(numbers[i] < smallest)
            smallest = numbers[i];

        if(numbers[i] > largest)
            largest = numbers[i];

        sum += numbers[i];
    }

    double average = (double)sum / 11;

    printf("Smallest: %d\n", smallest);
    printf("Largest: %d\n", largest);
    printf("Average: %.2f\n", average);

    return 0;
}
