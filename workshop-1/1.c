#include <stdio.h>

int main() {
    int percentage;

    printf("Enter percentage: ");
    scanf("%d", &percentage);

    if (percentage < 50) {
        printf("Grade: Fourth\n");
    }
    else if (percentage < 60) {
        printf("Grade: Third\n");
    }
    else if (percentage < 70) {
        printf("Grade: Second\n");
    }
    else {
        printf("Grade: First\n");
    }

    return 0;
}
