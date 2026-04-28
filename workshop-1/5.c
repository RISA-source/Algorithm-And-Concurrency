#include <stdio.h>

int main() {

    int pin = 1234;
    int input;
    int attempts = 0;
    int maxAttempts = 5;

    while(attempts < maxAttempts) {

        printf("Enter PIN: ");
        scanf("%d", &input);

        attempts++;

        if(input == pin) {
            printf("Access Granted\n");
            printf("Attempts taken: %d\n", attempts);
            return 0;
        }
        else {
            printf("Incorrect PIN\n");
        }
    }

    printf("Too many failed attempts\n");

    return 0;
}
