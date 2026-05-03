#include <stdio.h>

int main() {

    int input, cost, change;

    printf("Enter money inserted (pence): ");
    scanf("%d", &input);

    printf("Enter cost (pence): ");
    scanf("%d", &cost);

    change = input - cost;

    printf("Change: %dp\n", change);

    int twoPound = change / 200;
    change %= 200;

    int onePound = change / 100;
    change %= 100;

    int fifty = change / 50;
    change %= 50;

    int twenty = change / 20;
    change %= 20;

    int ten = change / 10;
    change %= 10;

    int five = change / 5;
    change %= 5;

    int two = change / 2;
    change %= 2;

    int one = change;

    printf("£2 x %d\n", twoPound);
    printf("£1 x %d\n", onePound);
    printf("50p x %d\n", fifty);
    printf("20p x %d\n", twenty);
    printf("10p x %d\n", ten);
    printf("5p x %d\n", five);
    printf("2p x %d\n", two);
    printf("1p x %d\n", one);

    return 0;
}
