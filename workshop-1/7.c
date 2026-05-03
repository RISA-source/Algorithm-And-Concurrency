#include <stdio.h>

int main() {

    int num, i, isPrime;

    while(1) {

        printf("Enter number: ");
        scanf("%d", &num);

        isPrime = 1;

        if(num <= 1)
            isPrime = 0;

        for(i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if(isPrime) {
            printf("Prime number entered. Program ending.\n");
            break;
        }
        else {
            printf("Not prime, try again.\n");
        }
    }

    return 0;
}
